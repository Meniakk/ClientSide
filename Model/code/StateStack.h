//
// Created by user on 24.1.2020.
//

#ifndef CLIENTSIDE_STATESTACK_H
#define CLIENTSIDE_STATESTACK_H

#include "IState.h"
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

    static StateStack &getInstance() {
        static StateStack instance;
        return instance;
    }

    void push(IState* state) {
        stack.push(state);
        toDel.push_back(state);
    }

    IState* pop() {
        IState* out = stack.top();
        stack.pop();
        return out;
    }

    virtual ~StateStack() {
        for (IState* s: toDel){
            delete s;
        }
    }

};


#endif //CLIENTSIDE_STATESTACK_H
