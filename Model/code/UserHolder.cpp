//
// Created by to on 1/18/20.
//

#include "UserHolder.h"

const User &UserHolder::getUser() const {
    return user;
}

void UserHolder::setUser(const User user) {
    UserHolder::user = user;
}

UserHolder &UserHolder::getInstance() {
    static UserHolder instance;
    return instance;
}

