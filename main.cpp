#include <iostream>
#include "Controller.h"
#include "Model/TestState.h"
#include "View/ConsolView.h"
#include "Model/Model.h"
#include "Model/MainState.h"
int main() {
    try {
        MainState s;
        //TODO: create client with real args
        std::string r = "192.168.239.1";
        Model m(&s, r, 1234);
        ConsolView v;
        Controller c(&v, &m);
        std::cout << "Hello, World!" << std::endl;
    }catch (char const* e){
        std::cout<<std::string(e);
    }
    return 0;
}