//
// Created by to on 1/17/20.
//

#include "User.h"

User::User(int id, int age, const std::string &name, const std::string &shortBio, const std::string &longBio,
           UserType type, UserSex userSex, UserSex prefSex) : id(id), age(age), name(name), shortBio(shortBio),
                                                              longBio(longBio), type(type), userSex(userSex),
                                                              prefSex(prefSex) {
}

int User::getId() const {
    return id;
}

std::string User::toString() {
    //TODO: implement the function
    throw "didn't implement the function User::toString()";
}

User::User() {}
