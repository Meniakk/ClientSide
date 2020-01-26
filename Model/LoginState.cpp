//
// Created by user on 24.1.2020.
//

#include "LoginState.h"


LoginState::LoginState() {
    str2commands["exit"] = new ExitCommand();
    str2commands["print"] = new PrintCommand();
    str2commands["new"] = new CreateUserCommand(new MainState());
}

