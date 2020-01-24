//
// Created by to on 1/17/20.
//

#include "User.h"


int User::getId() const {
    return id;
}

User::User() {}

User::User(int id, int age, const std::string &name, const std::string &shortBio, const std::string &longBio,
           const std::string &type, const std::string &userSex, const std::string &prefSex) : id(id), age(age),
                                                                                              name(name),
                                                                                              shortBio(shortBio),
                                                                                              longBio(longBio),
                                                                                              type(type),
                                                                                              userSex(userSex),
                                                                                              prefSex(prefSex) {}

int User::getAge() const {
    return age;
}

const std::string &User::getName() const {
    return name;
}

const std::string &User::getShortBio() const {
    return shortBio;
}

const std::string &User::getLongBio() const {
    return longBio;
}

const std::string &User::getType() const {
    return type;
}

const std::string &User::getUserSex() const {
    return userSex;
}

const std::string &User::getPrefSex() const {
    return prefSex;
}
