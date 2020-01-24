//
// Created by to on 1/17/20.
//

#ifndef CLIENTSIDE_USERBUILDER_H
#define CLIENTSIDE_USERBUILDER_H

#include <string>
#include "User.h"
#include "UserHolder.h"

class UserBuilder {
    int id;
    int age;
    std::string name;
    std::string shortBio;
    std::string longBio;
    UserType type;
    UserSex userSex;
    UserSex prefSex;
public:
    void build();

    void setId(int id);

    void setAge(int age);

    void setName(const std::string &name);

    void setShortBio(const std::string &shortBio);

    void setLongBio(const std::string &longBio);

    void setType(UserType type);

    void setUserSex(std::string userSex);

    void setPrefSex(std::string prefSex);

private:
    static UserSex string2gender(std::string str_gender);
};


#endif //CLIENTSIDE_USERBUILDER_H
