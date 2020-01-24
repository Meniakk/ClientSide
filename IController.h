//
// Created by noamc on 24/12/2019.
//

#ifndef UTEMP_ICONTROLLER_H
#define UTEMP_ICONTROLLER_H

#include <vector>
#include <string>
#include "View/IView.h"
#include "Model/IModel.h"

class IController : public IModel::ModelObserver {
public:

    virtual void sendServerCommand(std::string command) = 0;

    virtual void stop() = 0;

    virtual ~IController() {}
};


#endif //UTEMP_ICONTROLLER_H
