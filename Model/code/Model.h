//
// Created by noamc on 25/12/2019.
//

#ifndef UTEMP_MODEL_H
#define UTEMP_MODEL_H

#include <vector>
#include <queue>
#include "IModel.h"
#include "IState.h"
#include "Lexer.h"
#include "Parser.h"
#include "Client.h"

class Model : public IModel, public AbstCommand::CommandObserver {
private:
    Lexer lex;
    Parser par;
    Client client;
    IState *currentState;
    std::vector<IModel::EObserver *> eObservers;
    std::vector<IModel::IOObserver *> ioObservers;
public:

    void notify(AbstCommand::CommandNotify args) override;

    void proccesLine(std::string line) override;

    void addEObserver(EObserver *observer) override;

    void addIOObserver(IOObserver *observer) override;

    Model(IState *currentState,std::string &ip, int port);

private:
    class InputCallbackAdapter: public IModel::InCallback{
        AbstCommand::CommandInputCallback *callback;
    public:
        InputCallbackAdapter(AbstCommand::CommandInputCallback *callback);

        void in(std::string input) override;

    };

    void notifyExit();

    void notifyError();

    void notifyOutput(std::string output);

    void notifyInput(AbstCommand::CommandInputCallback* callback);

    void notifyNewState(IState *newState);

};




#endif //UTEMP_MODEL_H
