//
// Created by to on 1/18/20.
//

#include "getCommand.h"

void getCommand::doCommand(std::vector<std::string> line) {
    int k;
    try {
        k = std::stoi(line[1]);
    } catch (...) {
        error();
        return;
    }
    int id = UserHolder::getInstance().getUser();
    sendToServer(getCommandGen(k, id));
    std::string answer = getFromServer();
    if (answer == "0") {
        error();
        return;
    }
    std::vector<std::string> users = splitLine(answer, "~");
    std::vector<std::string> infoParts = INFO_PARTS;
    std::string out;
    for (std::string const &user: users) {
        std::vector<std::string> info = splitLine(user, ",");
        try {
            for (int i = 0; i < infoParts.size(); ++i) {
                out += infoParts[i] + ": " + info[i] + "\n";
            }
        } catch (...) {
            error();
            return;
        }
    }

    printOuput(out);

}
