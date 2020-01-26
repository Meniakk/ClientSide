//
// Created by to on 1/17/20.
//

#include "CreateUserCommand.h"


void CreateUserCommand::doCommand(std::vector<std::string> line) {
    UserBuilder builder;
    std::string enter = "please enter your ";
    try {
        printOuput(enter + "name");
        builder.setName(getInfo());
        printOuput(enter + "age");
        builder.setAge(std::stoi(getInfo()));
        printOuput(enter + "gender\n MALE/FEMALE");
        builder.setUserSex(getInfo());
        printOuput(enter + "short bio");
        builder.setShortBio(getInfo());
        printOuput(enter + "long bio");
        builder.setLongBio(getInfo());
        printOuput(enter + "user type");
        builder.setType(getInfo());
        printOuput(enter + "what you into\n MALE/FEMALE");
        builder.setPrefSex(getInfo());
    } catch (...) {
        error();
        return;
    }
    User user = builder.build();

    sendToServer(newUserParse(user.getAge(), user.getName(), user.getShortBio(), user.getLongBio(), user.getType(),
                              user.getUserSex(), user.getPrefSex()));
    std::string answer = getFromServer();
    if (answer == "0") {
        error();
        return;
    } else {
        try {
            UserHolder::getInstance().setUser(std::stoi(answer));
        } catch (...) {
            error();
            return;
        }

    }

    StateStack::getInstance().push(nextState);
    CommandNotify cn;
    cn.newState = true;
    notify(cn);
}

std::string CreateUserCommand::getInfo() {
    std::string out;
    while (true) {
        out = getLine();
        break;
    }
    return out;

}

CreateUserCommand::CreateUserCommand(IState *nextState) : nextState(nextState) {}

