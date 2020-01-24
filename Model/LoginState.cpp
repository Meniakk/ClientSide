//
// Created by user on 24.1.2020.
//

#include "LoginState.h"

bool LoginState::isCommandInWindow(std::string symbol) {
    return symbol == "new";
}

AbstCommand *LoginState::findCommand(std::string symbol) {
    return &c;
}

void LoginState::addObserver(AbstCommand::CommandObserver *obs) {
    c.addObserver(obs);
}
