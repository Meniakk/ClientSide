//
// Created by to on 1/17/20.
//

#include <iostream>
#include "TestClientCommand.h"

void TestClientCommand::doCommand(std::vector<std::string> line) {
    sendToServer("check");
    std::string str = this->getFromServer();
//    std::cout<<str;
    printOuput(str);
}
