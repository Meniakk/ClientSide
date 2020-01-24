//
// Created by to on 1/18/20.
//

#include "BiCommand.h"

void BiCommand::doCommand(std::vector<std::string> line) {
    std::string tag;
    try {
        tag = line[1];
    } catch (...) {
        error();
        return;
    }
    sendToServer(biCommandGen(tag));
    std::string answer = getFromServer();
    if (answer == "0") {
        error();
        return;
    }
    printOuput(answer);
}
