//
// Created by to on 1/17/20.
//

#include "LoveCommand.h"


void LoveCommand::doCommand(std::vector<std::string> line) {
    int id2;
    try {
        if (line.size() <2){
            error();
            return;
        }
        id2 = std::stoi(line[1]);
    } catch (...) {
        error();
        return;
    }
    int id1 = UserHolder::getInstance().getUser();
    this->sendToServer(loveCommandGen(id1, id2));
    std::string answer = getFromServer();

    if (answer == "1") {
        return;
    }
    if (answer == "0") {
        error();
        return;
    }
    error();

}
