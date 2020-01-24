//
// Created by to on 1/18/20.
//

#ifndef CLIENTSIDE_BICOMMAND_H
#define CLIENTSIDE_BICOMMAND_H

#include "ClientCommands.h"
#include "IOCommands.h"
#include "Client.h"

class BiCommand: public ClientCommands, public IOCommands {
public:
    void doCommand(std::vector<std::string> line) override;

};


#endif //CLIENTSIDE_BICOMMAND_H
