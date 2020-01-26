//
// Created by noamc on 24/12/2019.
//

#ifndef UTEMP_IVIEW_H
#define UTEMP_IVIEW_H

#include <string>


class IView {
public:
    class ViewObserver{
    public:
        virtual void newLineEvent(std::string input) = 0;
    };

    virtual void open() = 0;

    virtual void addObserver(ViewObserver* obs) = 0;

    virtual bool getLine(std::string &toline) = 0;

    virtual void showOutput(std::string output) = 0;
};


#endif //UTEMP_IVIEW_H
