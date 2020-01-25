//
// Created by noamc on 24/12/2019.
//

#ifndef UTEMP_TESTSTATE_H
#define UTEMP_TESTSTATE_H

#include "IState.h"
#include "ICommand.h"
#include "TestClientCommand.h"

class TestState : public IState {
    std::vector<ICommand::CommandObserver*> observers;

    class TestCommand : public AbstCommand {
    public:
        void doCommand(std::vector<std::string> line) override;
    };

    TestCommand c;
    TestClientCommand c1;

public:
    bool isCommandInWindow(std::string symbol) override;

    AbstCommand *findCommand(std::string symbol) override;

    void addObserver(ICommand::CommandObserver *obs) override;

};


#endif //UTEMP_TESTSTATE_H
