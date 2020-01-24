//
// Created by noamc on 24/12/2019.
//

#include "Controller.h"


void Controller::exitEvent() {
    this->stop();
}

void Controller::sendServerCommand(std::string command) {

}

Controller::~Controller() {}

Controller::Controller(IView *view, IModel *model) : view(view), model(model), run(true) {
    this->run = true;
    std::string line;
    int lineCounter = 0;
    model->addEObserver(this);
    model->addIOObserver(this);
    while (run) {
        ++lineCounter;
        view->showOutput(">>");
        view->getLine(line);
        model->proccesLine(line);
    }
}


void Controller::stop() {
    this->run = false;
}

void Controller::outEvent(std::string output) {
    view->showOutput(output + "\n");
}

void Controller::inEvent(IModel::InCallback *callback) {
    std::string input;
    view->getLine(input);
    callback->in(input);
}

void Controller::errorEvent() {
    view->showOutput("there has been an error\n");
}


