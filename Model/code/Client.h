//
// Created by noamc on 13/01/2020.
//

#ifndef CLIENT_SIDE_CLIENT_H
#define CLIENT_SIDE_CLIENT_H
#include <stdio.h>
#include <stdlib.h>

#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>

#include <string.h>
#include <string>


#include "Spliter.h"


#include <iostream>

#define BUFFER_SIZE 1024

#define LINE_END ';'

#define CLIENT_ERROR "communication error"

std::string loveCommandGen(int id1, int id2);
std::string lovedCommandGen(int id);
std::string getCommandGen(int k, int id);
std::string biCommandGen(std::string reportTag);
std::string isUserInDataBase(int id);


class Client : public Spliter {
    int sockfd;
    std::string line;


public:
    /**
     * connect to the server with the given ip and port
     * @param ip - the given ip
     * @param port - the given port
     */
    Client(std::string &ip, int port);

    /**
     * send a given string to the server
     * @param msg - the given string
     */
    void sendingEvent(std::string msg);

    /**
     * get the socket the client using
     * @return the socket the client using
     */
    int getSockfd() const;

    std::string readMsg() const;

    std::string getLine();
};



#endif //CLIENT_SIDE_CLIENT_H
