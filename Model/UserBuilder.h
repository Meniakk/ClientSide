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
    std::string type;
    std::string userSex;
    std::string prefSex;
public:
    int getId() const;

    int getAge() const;

    const std::string &getName() const;

    const std::string &getShortBio() const;

    const std::string &getLongBio() const;

    const std::string &getType() const;

    const std::string &getUserSex() const;

    const std::string &getPrefSex() const;

    User build();

    void setId(int id);

    void setAge(int age);

    void setName(const std::string &name);

    void setShortBio(const std::string &shortBio);

    void setLongBio(const std::string &longBio);

    void setType(const std::string &type);

    void setUserSex(const std::string &userSex);

    void setPrefSex(const std::string &prefSex);
};


#endif //CLIENTSIDE_USERBUILDER_H
