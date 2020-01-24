//
// Created by to on 1/18/20.
//

#include "UserHolder.h"

const int &UserHolder::getUser() const {
    return id;
}

void UserHolder::setUser(const int user) {
    this->id = user;
}

UserHolder &UserHolder::getInstance() {
    static UserHolder instance;
    return instance;
}

