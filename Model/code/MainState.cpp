//
// Created by to on 1/19/20.
//

#include "MainState.h"

bool MainState::isCommandInWindow(std::string symbol) {
    return str2commands.find(symbol) != str2commands.end();
}

AbstCommand *MainState::findCommand(std::string symbol) {
    return str2commands[symbol];
}

void MainState::addObserver(AbstCommand::CommandObserver *obs) {
    for (auto it : str2commands) {
        it.second->addObserver(obs);
    }
}

MainState::MainState() {
    str2commands["love"] = new LoveCommand();
    str2commands["loved"] = new LovedCommand();
    str2commands["get"] = new getCommand();
    str2commands["exit"] = new ExitCommand();
    str2commands["bi"] = new BiCommand();
    str2commands["print"] = new PrintCommand();
}

MainState::~MainState() {
    for (auto &it : str2commands) {
        delete it.second;
    }
}
