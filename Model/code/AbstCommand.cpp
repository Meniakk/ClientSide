//
// Created by to on 1/17/20.
//
#include "AbstCommand.h"

void AbstCommand::addObserver(AbstCommand::CommandObserver *obs) {
    observers.insert(obs);
}

void AbstCommand::notify(AbstCommand::CommandNotify args) {
    for (CommandObserver *obs: observers) {
        obs->notify(args);
    }

}

void AbstCommand::error() {
    CommandNotify notifyArgs;
    notifyArgs.isError = true;
    notify(notifyArgs);

}

const std::string &AbstCommand::CommandInputCallback::getInput() const {
    return input;
}

void AbstCommand::CommandInputCallback::setInput(const std::string &input) {
    this->input = input;
}