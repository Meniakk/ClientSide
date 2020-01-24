//
// Created by to on 1/17/20.
//

#include "UserBuilder.h"

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

void UserBuilder::setType(UserType type) {
    UserBuilder::type = type;
}

void UserBuilder::setUserSex(std::string userSex) {
    UserBuilder::userSex = string2gender(userSex);
}

void UserBuilder::setPrefSex(std::string prefSex) {
    UserBuilder::prefSex = string2gender(prefSex);
}

void UserBuilder::build() {
    UserHolder::getInstance().setUser(User(id, age, name, shortBio, longBio, type, userSex, prefSex));
}


UserSex UserBuilder::string2gender(std::string str_gender) {
    if (str_gender == "MALE") {
        return MALE;
    } else if (str_gender == "FEMALE") {
        return FEMALE;
    }
    throw "no gender";
}
