//
// Created by to on 1/19/20.
//

#include "MainState.h"


MainState::MainState() {
    str2commands["love"] = new LoveCommand();
    str2commands["loved"] = new LovedCommand();
    str2commands["get"] = new getCommand();
    str2commands["exit"] = new ExitCommand();
    str2commands["bi"] = new BiCommand();
    str2commands["print"] = new PrintCommand();
    str2commands["new"] = new CreateUserCommand(this);
}

