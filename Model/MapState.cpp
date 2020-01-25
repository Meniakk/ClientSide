//
// Created by to on 1/25/20.
//

#include "MapState.h"

bool MapState::isCommandInWindow(std::string symbol) {
    return str2commands.find(symbol) != str2commands.end();
}

ICommand *MapState::findCommand(std::string symbol) {
    return str2commands[symbol];
}

void MapState::addObserver(ICommand::CommandObserver *obs) {
    for (auto it : str2commands) {
        it.second->addObserver(obs);
    }
}

MapState::~MapState() {
    for (auto &it : str2commands) {
        delete it.second;
    }
}
