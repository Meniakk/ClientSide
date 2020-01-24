//
// Created by to on 1/17/20.
//

#include "IOCommands.h"

std::string IOCommands::getLine() {
    AbstCommand::CommandNotify notification;
    AbstCommand::CommandInputCallback callback;
    notification.viewCallback = &callback;
    notify(notification);
    return callback.getInput();
}


void IOCommands::printOuput(std::string ouput) {
    AbstCommand::CommandNotify notification;
    notification.output = ouput;
    notify(notification);
}
