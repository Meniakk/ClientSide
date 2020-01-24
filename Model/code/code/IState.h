//
// Created by noamc on 24/12/2019.
//

#ifndef UTEMP_ISTATE_H
#define UTEMP_ISTATE_H

#include <string>
#include "AbstCommand.h"

class IState {
public:
    virtual bool isCommandInWindow(std::string symbol) = 0;

    virtual AbstCommand *findCommand(std::string symbol) = 0;

    virtual void addObserver(AbstCommand::CommandObserver *obs) = 0;

    virtual ~IState() {}

};


#endif //UTEMP_ISTATE_H
