//
// Created by noamc on 24/12/2019.
//

#ifndef UTEMP_CONTROLLER_H
#define UTEMP_CONTROLLER_H

#include <string>
#include <vector>
#include <queue>
#include "IController.h"
#include "Model/IState.h"
#include "View/IView.h"
#include "Model/IModel.h"


/*
 * Used to control the program.
 * the "head" of the app
 * the c in mvc
 */
class Controller : public IController {

private:
    IView *view;
    IModel *model;
    IState *currentState;
    std::queue<std::string> inputs;
    bool run;
public:
    Controller(IView *view, IModel *model);

    void sendServerCommand(std::string command) override;

    ~Controller() override;

    void stop() override;

    void outEvent(std::string output) override;

    void inEvent(IModel::InCallback *callback) override;

    void errorEvent() override;

    void exitEvent() override;


};


#endif //UTEMP_CONTROLLER_H
