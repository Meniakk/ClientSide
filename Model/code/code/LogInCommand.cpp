//
// Created by to on 1/21/20.
//

#include "LogInCommand.h"

void LogInCommand::doCommand(std::vector<std::string> line) {
    int id;
    try {
        id = std::stoi(line[1]);
    } catch (...) {
        error();
        return;
    }

    sendToServer(isUserInDataBase(id));


}
