//
// Created by noamc on 25/12/2019.
//

#include "Model.h"

void Model::notifyExit() {
    for (EObserver *obs: eObservers) {
        obs->exitEvent();
    }
}

void Model::notifyError() {
    for (EObserver *obs: eObservers) {
        obs->errorEvent();
    }
}

void Model::notifyOutput(std::string output) {
    for (IOObserver *obs: ioObservers) {
        obs->outEvent(output);
    }
}


void Model::notifyInput(ICommand::CommandInputCallback *callback) {
    InputCallbackAdapter adapter(callback);
    for (IOObserver *obs: ioObservers) {
        obs->inEvent(&adapter);
    }
}


void Model::notifyConInput(ICommand::CommandInputCallback *callback) {
    InputCallbackAdapter adapter(callback);
    for (ConnectionObserver *obs: conObservers) {
        obs->inputEvent(&adapter);
    }
}

void Model::notifySend(std::string output) {
    for (ConnectionObserver *obs: conObservers) {
        obs->sendingEvent(output);
    }
}


void Model::proccesLine(std::string line) {
    std::vector<std::string> tokens = this->lex.lexLine(line);
    ICommand *command = this->par.parse(tokens, currentState);
    if (command == nullptr) {
        this->notifyError();
        return;
    }
    command->doCommand(tokens);

}


void Model::addEObserver(IModel::EObserver *observer) {
    eObservers.push_back(observer);
}

void Model::addIOObserver(IModel::IOObserver *observer) {
    ioObservers.push_back(observer);
}

void Model::notify(ICommand::CommandNotify args) {
    if (args.isError) {
        this->notifyError();
    }
    if (args.isExit) {
        this->notifyExit();
    }
    if (!args.output.empty()) {
        this->notifyOutput(args.output);
    }

    if (args.viewCallback != nullptr) {
        this->notifyInput(args.viewCallback);
    }

    if (args.serverCallback != nullptr) {
        notifyConInput(args.serverCallback);
    }

    if (!args.toServer.empty()) {
        notifySend(args.toServer);
    }
    if (args.newState) {
        notifyNewState();
    }

}

Model::Model(IState *currentState) : currentState(currentState) {
    currentState->addObserver(this);
}


void Model::InputCallbackAdapter::in(std::string input) {
    callback->setInput(input);
}


Model::InputCallbackAdapter::InputCallbackAdapter(ICommand::CommandInputCallback *callback) : callback(callback) {}


Model::Model()   {
    this->currentState = StateStack::getInstance().pop();
}

void Model::notifyNewState() {
    this->currentState = StateStack::getInstance().pop();
}


void Model::addConObserver(IModel::ConnectionObserver *observer) {
    this->conObservers.push_back(observer);
}


