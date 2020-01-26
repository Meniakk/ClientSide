//
// Created by to on 1/18/20.
//

#include "BiCommand.h"
#include "UserHolder.h"

void BiCommand::doCommand(std::vector<std::string> line) {
    std::string tag;
    try {
        if (line.size() <2){
            error();
            return;
        }
        tag = line[1];
    } catch (...) {
        error();
        return;
    }
    int id = UserHolder::getInstance().getUser();
    sendToServer(biCommandGen(tag,id));
    std::string answer = getFromServer();
    if (answer == "0") {
        error();
        return;
    }
    printOuput(answer);
}
