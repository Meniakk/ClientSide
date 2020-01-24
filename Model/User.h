//
// Created by to on 1/17/20.
//

#ifndef CLIENTSIDE_USER_H
#define CLIENTSIDE_USER_H

#include <string>


class User {
    int id;
    int age;
    std::string name;
    std::string shortBio;
    std::string longBio;
    std::string type;
    std::string userSex;
    std::string prefSex;
public:
    User(int id, int age, const std::string &name, const std::string &shortBio, const std::string &longBio,
         const std::string &type, const std::string &userSex, const std::string &prefSex);

    User();

    int getId() const;

    int getAge() const;

    const std::string &getName() const;

    const std::string &getShortBio() const;

    const std::string &getLongBio() const;

    const std::string &getType() const;

    const std::string &getUserSex() const;

    const std::string &getPrefSex() const;


};


#endif //CLIENTSIDE_USER_H
