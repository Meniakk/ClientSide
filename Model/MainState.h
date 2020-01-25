//
// Created by to on 1/19/20.
//

#ifndef CLIENTSIDE_MAINSTATE_H
#define CLIENTSIDE_MAINSTATE_H


#include <unordered_map>
#include <string>

#include "MapState.h"
#include "LoveCommand.h"
#include "LovedCommand.h"
#include "getCommand.h"
#include "ExitCommand.h"
#include "BiCommand.h"
#include "PrintCommand.h"
#include "CreateUserCommand.h"

class MainState : public MapState {
public:
    MainState();
};


#endif //CLIENTSIDE_MAINSTATE_H
