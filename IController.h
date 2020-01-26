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
protected:
    IView *view;
    IModel *model;

public:

    virtual void stop() = 0;

    virtual ~IController() {}
};


#endif //UTEMP_ICONTROLLER_H
