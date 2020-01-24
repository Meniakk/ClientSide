//
// Created by user on 24.1.2020.
//

#ifndef CLIENTSIDE_LOGINSTATE_H
#define CLIENTSIDE_LOGINSTATE_H

#include "IState.h"
#include "CreateUserCommand.h"
class LoginState : public IState{
    CreateUserCommand c;

public:
    bool isCommandInWindow(std::string symbol) override;

    AbstCommand *findCommand(std::string symbol) override;

    void addObserver(AbstCommand::CommandObserver *obs) override;
};


#endif //CLIENTSIDE_LOGINSTATE_H
