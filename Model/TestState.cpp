//
// Created by noamc on 24/12/2019.
//

#include "TestState.h"

bool TestState::isCommandInWindow(std::string symbol) {
    return symbol == "print" || symbol == "test";
}

AbstCommand *TestState::findCommand(std::string symbol) {
    if (symbol == "print") return &(this->c);
    return &c1;
}

void TestState::addObserver(ICommand::CommandObserver *obs) {
    c.addObserver(obs);
    c1.addObserver(obs);
}

void TestState::TestCommand::doCommand(std::vector<std::string> line) {
    ICommand::CommandNotify out;
    out.isExit = false;
    if (line.size() < 2) {
        out.isError = true;
    } else {
        out.output = line[1];
    }
    notify(out);
}
