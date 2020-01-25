//
// Created by to on 1/25/20.
//

#ifndef CLIENTSIDE_MAPSTATE_H
#define CLIENTSIDE_MAPSTATE_H

#include <unordered_map>
#include "IState.h"

class MapState: public IState {
public:
    bool isCommandInWindow(std::string symbol) override;

    ICommand *findCommand(std::string symbol) override;

    void addObserver(ICommand::CommandObserver *obs) override;

    ~MapState() override;

protected:
    std::unordered_map<std::string, ICommand *> str2commands;

};


#endif //CLIENTSIDE_MAPSTATE_H
