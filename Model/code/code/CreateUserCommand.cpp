//
// Created by to on 1/17/20.
//

#include "CreateUserCommand.h"


void CreateUserCommand::doCommand(std::vector<std::string> line) {
    UserBuilder builder;
    std::string enter = "please enter your";
    printOuput(enter + "name");
    builder.setName(getInfo());
    printOuput(enter + "age");
    builder.setAge(std::stoi(getInfo()));
    printOuput(enter + "gender\n MALE/FEMALE" );
    builder.setUserSex(getInfo());
    printOuput(enter + "age");
    builder.setName(getInfo());
    printOuput(enter + "age");
    builder.setName(getInfo());
    printOuput(enter + "age");
    builder.setName(getInfo());
    printOuput(enter + "age");
    builder.setName(getInfo());
    printOuput(enter + "age");
    builder.setName(getInfo());

}

std::string CreateUserCommand::getInfo() {
    std::string out;
    while (true){
        //TODO: check there is not ileagle chars
        out = getLine();
        break;
    }
    return out;

}

