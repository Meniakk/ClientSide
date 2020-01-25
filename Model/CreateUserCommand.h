//
// Created by to on 1/17/20.
//

#ifndef CLIENTSIDE_CREATEUSERCOMMAND_H
#define CLIENTSIDE_CREATEUSERCOMMAND_H

#include "IOCommands.h"
#include "ClientCommands.h"
#include "Client.h"
#include "UserBuilder.h"
#include "UserHolder.h"
#include "StateStack.h"
#include "IState.h"

class CreateUserCommand : public IOCommands, public ClientCommands {
private:
    IState* nextState;
public:
    CreateUserCommand(IState *nextState);

    void doCommand(std::vector<std::string> line) override;

private:
    std::string getInfo();
};


#endif //CLIENTSIDE_CREATEUSERCOMMAND_H
