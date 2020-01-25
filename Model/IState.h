//
// Created by noamc on 24/12/2019.
//

#ifndef UTEMP_ISTATE_H
#define UTEMP_ISTATE_H

#include <string>
#include "ICommand.h"

class IState {
public:
    virtual bool isCommandInWindow(std::string symbol) = 0;

    virtual ICommand *findCommand(std::string symbol) = 0;

    virtual void addObserver(ICommand::CommandObserver *obs) = 0;

    virtual ~IState() {}

};


#endif //UTEMP_ISTATE_H
