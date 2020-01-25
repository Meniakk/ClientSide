//
// Created by user on 24.1.2020.
//

#include "StateStack.h"

StateStack &StateStack::getInstance() {
    static StateStack instance;
    return instance;
}

void StateStack::push(IState* state) {
    stack.push(state);
    toDel.push_back(state);
}

IState* StateStack::pop() {
    if (stack.empty()){
        this->push(new LoginState());
    }
    IState* out = stack.top();
    stack.pop();
    return out;
}

StateStack::~StateStack() {
    for (IState* s: toDel){
        delete s;
    }
}
