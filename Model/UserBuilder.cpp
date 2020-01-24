//
// Created by to on 1/17/20.
//

#include "UserBuilder.h"

User UserBuilder::build() {
    User outUser(id, age, name, shortBio, longBio, type, userSex, prefSex);
    return outUser;
}

void UserBuilder::setId(int id) {
    UserBuilder::id = id;
}

void UserBuilder::setAge(int age) {
    UserBuilder::age = age;
}

void UserBuilder::setName(const std::string &name) {
    UserBuilder::name = name;
}

void UserBuilder::setShortBio(const std::string &shortBio) {
    UserBuilder::shortBio = shortBio;
}

void UserBuilder::setLongBio(const std::string &longBio) {
    UserBuilder::longBio = longBio;
}

void UserBuilder::setType(const std::string &type) {
    UserBuilder::type = type;
}

void UserBuilder::setUserSex(const std::string &userSex) {
    UserBuilder::userSex = userSex;
}

void UserBuilder::setPrefSex(const std::string &prefSex) {
    UserBuilder::prefSex = prefSex;
}

int UserBuilder::getId() const {
    return id;
}

int UserBuilder::getAge() const {
    return age;
}

const std::string &UserBuilder::getName() const {
    return name;
}

const std::string &UserBuilder::getShortBio() const {
    return shortBio;
}

const std::string &UserBuilder::getLongBio() const {
    return longBio;
}

const std::string &UserBuilder::getType() const {
    return type;
}

const std::string &UserBuilder::getUserSex() const {
    return userSex;
}

const std::string &UserBuilder::getPrefSex() const {
    return prefSex;
}

