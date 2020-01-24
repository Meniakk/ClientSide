//
// Created by to on 1/17/20.
//

#ifndef CLIENTSIDE_USER_H
#define CLIENTSIDE_USER_H

#include <string>

enum UserType{TIAL, MEMBER, GOLD, ADMIN};
enum UserSex{MALE, FEMALE};

class User {
    int id;
    int age;
    std::string name;
    std::string shortBio;
    std::string longBio;
    UserType type;
    UserSex userSex;
    UserSex prefSex;
public:
    User(int id, int age, const std::string &name, const std::string &shortBio, const std::string &longBio,
         UserType type, UserSex userSex, UserSex prefSex);

    User();

    int getId() const;

    std::string toString();

};


#endif //CLIENTSIDE_USER_H
