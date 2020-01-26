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
#include "StateStack.h"
#include "UserHolder.h"


class Model : public IModel, public ICommand::CommandObserver {
private:
    Lexer lex;
    Parser par;
    IState *currentState;
    std::vector<IModel::EObserver *> eObservers;
    std::vector<IModel::IOObserver *> ioObservers;
    std::vector<IModel::ConnectionObserver *> conObservers;
public:

    void notify(ICommand::CommandNotify args) override;

    void proccesLine(std::string line) override;

    void addEObserver(EObserver *observer) override;

    void addIOObserver(IOObserver *observer) override;

    Model(IState *currentState);

    Model();

    void addConObserver(ConnectionObserver *observer) override;

private:
    class InputCallbackAdapter: public IModel::InCallback{
        ICommand::CommandInputCallback *callback;
    public:
        InputCallbackAdapter(ICommand::CommandInputCallback *callback);

        void in(std::string input) override;

    };

    void notifyExit();

    void notifyError();

    void notifyOutput(std::string output);

    void notifyInput(ICommand::CommandInputCallback* callback);

    void notifyConInput(ICommand::CommandInputCallback* callback);

    void notifySend(std::string output);

    void notifyNewState();

};




#endif //UTEMP_MODEL_H
