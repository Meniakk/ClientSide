//
// Created by noamc on 24/12/2019.
//

#include "Controller.h"


void Controller::exitEvent() {
    this->stop();
}


Controller::~Controller() {}

Controller::Controller(IView *view, IModel *model) : run(true) {
    this->model = model;
    this->view = view;
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


