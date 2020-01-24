//
// Created by to on 1/17/20.
//

#ifndef CLIENTSIDE_TESTCLIENTCOMMAND_H
#define CLIENTSIDE_TESTCLIENTCOMMAND_H

#include "ClientCommands.h"
#include "IOCommands.h"

class TestClientCommand: public ClientCommands, public IOCommands{
public:
    void doCommand(std::vector<std::string> line) override;

};


#endif //CLIENTSIDE_TESTCLIENTCOMMAND_H
