//
// Created by to on 1/19/20.
//

#ifndef CLIENTSIDE_MAINSTATE_H
#define CLIENTSIDE_MAINSTATE_H


#include <unordered_map>
#include <string>

#include "IState.h"
#include "LoveCommand.h"
#include "LovedCommand.h"
#include "getCommand.h"
#include "ExitCommand.h"
#include "BiCommand.h"
#include "PrintCommand.h"


class MainState : public IState {
private:
    std::unordered_map<std::string, AbstCommand *> str2commands;
public:
    MainState();

    bool isCommandInWindow(std::string symbol) override;

    AbstCommand *findCommand(std::string symbol) override;

    void addObserver(AbstCommand::CommandObserver *obs) override;

    virtual ~MainState();
};


#endif //CLIENTSIDE_MAINSTATE_H
