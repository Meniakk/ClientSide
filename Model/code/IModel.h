//
// Created by noamc on 24/12/2019.
//

#ifndef UTEMP_IMODEL_H
#define UTEMP_IMODEL_H

#include <string>
#include "IState.h"

class IModel {

public:
    class InCallback {
    public:
        virtual void in(std::string input) = 0;
    };

    class OutCallback {
    public:
        virtual std::string out() = 0;
    };

protected:
    class IOObserver {
    public:
        virtual void outEvent(std::string output) = 0;

        virtual void inEvent(InCallback *callback) = 0;
    };

    class EObserver {
    public:
        virtual void errorEvent() = 0;

        virtual void exitEvent() = 0;
    };

public:
    class ModelObserver : public IOObserver, public EObserver {
    };


    virtual void addEObserver(EObserver *observer) = 0;

    virtual void addIOObserver(IOObserver *observer) = 0;

    virtual void proccesLine(std::string line) = 0;


};


#endif //UTEMP_IMODEL_H
