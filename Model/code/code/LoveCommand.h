//
// Created by to on 1/17/20.
//

#ifndef CLIENTSIDE_LOVECOMMAND_H
#define CLIENTSIDE_LOVECOMMAND_H

#include "ClientCommands.h"
#include "Client.h"
#include "UserHolder.h"

class LoveCommand: public ClientCommands{
public:
    void doCommand(std::vector<std::string> line) override;
};


#endif //CLIENTSIDE_LOVECOMMAND_H
