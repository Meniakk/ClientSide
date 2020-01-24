//
// Created by to on 1/23/20.
//

#ifndef CLIENTSIDE_PRINTCOMMAND_H
#define CLIENTSIDE_PRINTCOMMAND_H

#include <string>
#include "IOCommands.h"

class PrintCommand: public IOCommands {
public:
    void doCommand(std::vector<std::string> line) override;

};


#endif //CLIENTSIDE_PRINTCOMMAND_H
