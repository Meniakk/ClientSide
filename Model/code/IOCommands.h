//
// Created by to on 1/17/20.
//

#ifndef CLIENTSIDE_IOCOMMAND_H
#define CLIENTSIDE_IOCOMMAND_H

#include "AbstCommand.h"

class IOCommands : public virtual AbstCommand {
protected:
    std::string getLine();

    void printOuput(std::string ouput);
};


#endif //CLIENTSIDE_IOCOMMAND_H
