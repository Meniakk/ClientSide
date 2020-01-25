//
// Created by user on 24.1.2020.
//

#ifndef CLIENTSIDE_STATESTACK_H
#define CLIENTSIDE_STATESTACK_H

#include "IState.h"
#include "LoginState.h"
#include <stack>
#include <vector>
class StateStack {
std::stack<IState*> stack;
std::vector<IState*> toDel;

private:
    StateStack(){}

public:
    void operator=(StateStack const &) = delete;

    StateStack(StateStack const &) = delete;

    static StateStack &getInstance();

    void push(IState* state);

    IState* pop();

    virtual ~StateStack();

};


#endif //CLIENTSIDE_STATESTACK_H
