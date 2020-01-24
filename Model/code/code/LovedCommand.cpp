//
// Created by to on 1/18/20.
//

#include "LovedCommand.h"

void LovedCommand::doCommand(std::vector<std::string> line) {
    int id = UserHolder::getInstance().getUser().getId();
    sendToServer(lovedCommandGen(id));
    std::string answer = getFromServer();
    if (answer == "0") {
        error();
        return;
    }

    std::vector<std::string> info = splitLine(answer, ",");
    std::vector<std::string> infoParts = INFO;
    std::string out;
    try {
        for (int i = 0; i < infoParts.size(); ++i) {
            out += infoParts[i] + ": " + info[i] + "\n";
        }
    } catch (...) {
        error();
        return;
    }

    printOuput(out);


}
