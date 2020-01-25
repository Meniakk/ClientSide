//
// Created by noamc on 24/12/2019.
//

#ifndef UTEMP_PARSER_H
#define UTEMP_PARSER_H

#include "ICommand.h"
#include <vector>
#include <string>
#include "IState.h"

class Parser {
public:
    ICommand* parse(std::vector<std::string> line, IState *currentState);
};


#endif //UTEMP_PARSER_H
