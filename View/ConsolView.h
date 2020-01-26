//
// Created by noamc on 24/12/2019.
//

#ifndef UTEMP_CONSOLVIEW_H
#define UTEMP_CONSOLVIEW_H

#include "IView.h"
#include <iostream>
#include <string>
#include <vector>
class ConsolView: public IView {
    std::vector<IView::ViewObserver*> observers;
public:
    bool getLine(std::string& toline) override;

    void showOutput(std::string output) override;

    void open() override;

    void addObserver(ViewObserver *obs) override;

};


#endif //UTEMP_CONSOLVIEW_H
