//
// Created by noamc on 24/12/2019.
//

#ifndef UTEMP_ICOMMAND_H
#define UTEMP_ICOMMAND_H

#include <vector>
#include <string>
#include <set>
#include <functional>

class AbstCommand {
public:
    class CommandInputCallback {
        std::string input;
    public:
        void setInput(const std::string &input);

        const std::string &getInput() const;

    };

    typedef struct CommandNotify {
        std::string output = "";
        std::string toServer = "";
        bool isError = false;
        bool isExit = false;
        AbstCommand::CommandInputCallback *viewCallback = nullptr;
        AbstCommand::CommandInputCallback *serverCallback = nullptr;

        CommandNotify() = default;
    } CommandNotify;

    class CommandObserver {
    public:
        virtual void notify(CommandNotify args) = 0;
    };

    virtual void addObserver(CommandObserver *obs);

    virtual void notify(CommandNotify args);

    virtual void error();

    virtual void doCommand(std::vector<std::string> line) = 0;

    virtual ~AbstCommand() {}

protected:
    std::set<AbstCommand::CommandObserver *> observers;
};


#endif //UTEMP_ICOMMAND_H
