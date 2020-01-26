#include <iostream>
#include "Controller.h"
#include "Model/TestState.h"
#include "View/ConsolView.h"
#include "Model/Model.h"
#include "Model/LoginState.h"
#include "Model/Client.h"

int main() {
    try {
        LoginState s;
        std::string r = "192.168.239.1";
        int port = 1234;
        Client con(r,port);
        Model m(&s);
        m.addConObserver(&con);
        ConsolView v;
        Controller c(&v, &m);
    } catch (char const *e) {
        std::cout << std::string(e);
    }
    return 0;
}