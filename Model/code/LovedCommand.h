//
// Created by to on 1/18/20.
//

#ifndef CLIENTSIDE_LOVEDCOMMAND_H
#define CLIENTSIDE_LOVEDCOMMAND_H

#include <vector>

#include "ClientCommands.h"
#include "IOCommands.h"
#include "Client.h"
#include "UserHolder.h"
#include "Spliter.h"

#define INFO {"name","short bio", "long bio"};

class LovedCommand : public ClientCommands, public IOCommands, public Spliter {
public:
    void doCommand(std::vector<std::string> line) override;

};


#endif //CLIENTSIDE_LOVEDCOMMAND_H
