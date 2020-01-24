//
// Created by to on 1/18/20.
//

#ifndef CLIENTSIDE_GETCOMMAND_H
#define CLIENTSIDE_GETCOMMAND_H

#include <vector>
#include "ClientCommands.h"
#include "IOCommands.h"
#include "Client.h"
#include "UserHolder.h"

#define INFO_PARTS {"name","short bio", "long bio","id"};

class getCommand : public ClientCommands, public IOCommands, public Spliter {
public:
    void doCommand(std::vector<std::string> line) override;

};


#endif //CLIENTSIDE_GETCOMMAND_H
