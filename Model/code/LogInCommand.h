//
// Created by to on 1/21/20.
//

#ifndef CLIENTSIDE_LOGINCOMMAND_H
#define CLIENTSIDE_LOGINCOMMAND_H

#include "IOCommands.h"
#include "ClientCommands.h"
#include "Client.h"
#include "UserBuilder.h"

class LogInCommand : public IOCommands, public ClientCommands{
public:
    void doCommand(std::vector<std::string> line) override;

};


#endif //CLIENTSIDE_LOGINCOMMAND_H
