//
// Created by noamc on 24/12/2019.
//

#ifndef UTEMP_ICOMMAND_H
#define UTEMP_ICOMMAND_H

#include <vector>
#include <string>
#include <set>

#include "ICommand.h"

class AbstCommand: public ICommand {
public:
    virtual void error();

    void addObserver(CommandObserver *obs) override;

    void notify(CommandNotify args) override;

protected:
    std::set<AbstCommand::CommandObserver *> observers;
};


#endif //UTEMP_ICOMMAND_H
