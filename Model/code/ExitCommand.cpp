//
// Created by noamc on 24/12/2019.
//

#include "ExitCommand.h"

void ExitCommand::doCommand(std::vector<std::string> line) {
    AbstCommand::CommandNotify out;
    out.isExit = true;
    notify(out);
}
