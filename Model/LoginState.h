//
// Created by user on 24.1.2020.
//

#ifndef CLIENTSIDE_LOGINSTATE_H
#define CLIENTSIDE_LOGINSTATE_H


#include <unordered_map>
#include "MapState.h"
#include "CreateUserCommand.h"
#include "ExitCommand.h"
#include "PrintCommand.h"

class LoginState : public MapState {
public:
    LoginState();

};


#endif //CLIENTSIDE_LOGINSTATE_H
