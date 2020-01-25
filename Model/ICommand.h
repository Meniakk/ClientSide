//
// Created by to on 1/25/20.
//

#ifndef CLIENTSIDE_ICOMMAND_H
#define CLIENTSIDE_ICOMMAND_H


#include <vector>
#include <string>
#include <set>

class ICommand {
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
        bool newState = false;
        ICommand::CommandInputCallback *viewCallback = nullptr;
        ICommand::CommandInputCallback *serverCallback = nullptr;

        CommandNotify() = default;
    } CommandNotify;

    class CommandObserver {
    public:
        virtual void notify(CommandNotify args) = 0;
    };

    virtual void addObserver(CommandObserver *obs) = 0;

    virtual void notify(CommandNotify args) = 0;

    virtual void doCommand(std::vector<std::string> line) = 0;

    virtual ~ICommand(){}

};


#endif //CLIENTSIDE_ICOMMAND_H
