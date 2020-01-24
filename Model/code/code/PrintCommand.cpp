//
// Created by to on 1/23/20.
//

#include "PrintCommand.h"

void PrintCommand::doCommand(std::vector<std::string> line) {
    std::string out;
    try {
        out = line[1];
    } catch (...) {
        error();
    }
    printOuput(out);


}
