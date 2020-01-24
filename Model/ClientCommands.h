//
// Created by to on 1/17/20.
//

#ifndef CLIENTSIDE_CLIENTCOMMANDS_H
#define CLIENTSIDE_CLIENTCOMMANDS_H

#include "AbstCommand.h"

class ClientCommands : public virtual AbstCommand {
protected:
    void sendToServer(std::string msg);

    std::string getFromServer();
};


#endif //CLIENTSIDE_CLIENTCOMMANDS_H
