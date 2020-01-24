//
// Created by to on 1/17/20.
//

#include "ClientCommands.h"

void ClientCommands::sendToServer(std::string msg) {
    AbstCommand::CommandNotify notification;
    notification.toServer = msg;
    notify(notification);
}

std::string ClientCommands::getFromServer() {
    AbstCommand::CommandNotify notification;
    AbstCommand::CommandInputCallback callback;
    notification.serverCallback = &callback;
    notify(notification);
    return callback.getInput();
}
