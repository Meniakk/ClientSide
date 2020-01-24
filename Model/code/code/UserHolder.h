//
// Created by to on 1/18/20.
//

#ifndef CLIENTSIDE_USERHOLDER_H
#define CLIENTSIDE_USERHOLDER_H

#include "User.h"

class UserHolder {
private:
    UserHolder(){};

    User user;

public:
    void operator=(UserHolder const &) = delete;

    UserHolder(UserHolder const &) = delete;

    static UserHolder &getInstance();

    const User &getUser() const;

    void setUser(const User user);


};


#endif //CLIENTSIDE_USERHOLDER_H
