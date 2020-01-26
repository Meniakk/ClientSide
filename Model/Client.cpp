//
// Created by noamc on 13/01/2020.
//

#include "Client.h"
//#include <iostream>

std::string loveCommandGen(int id1, int id2) {
    return "love " + std::to_string(id1) + "," + std::to_string(id2) + ";";
}

std::string getCommandGen(int k, int id) {
    return "get " + std::to_string(id) + "," + std::to_string(k) + ";";
}

std::string biCommandGen(std::string reportTag, int id) {
    return "bi " + std::to_string(id) + "," + reportTag + ";";
}

std::string lovedCommandGen(int id) {
    return "loved " + std::to_string(id) + ";";
}

std::string isUserInDataBase(int id) {
    return "is_user " + std::to_string(id) + ";";
}

std::string newUserParse(int age,
                         std::string name,
                         std::string shortBio,
                         std::string longBio,
                         std::string userType,
                         std::string userGender,
                         std::string intoGender) {
    return "new_user " + std::to_string(age) + ", " + name + ", " + shortBio + ", " + longBio + ", " + userType + ", " +
           userGender + ", " + intoGender;
}

Client::Client(std::string &ip, int port) {
    if (port == -1) return; //TODO: del this line

    struct sockaddr_in serv_addr;
    struct hostent *server;

    /* Create a socket point */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        throw CLIENT_ERROR;
    }

    server = gethostbyname(ip.c_str());

    if (server == NULL) {
        throw CLIENT_ERROR;
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(port);


    /* Now connect to the server */
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        throw CLIENT_ERROR;
    }


}

int Client::getSockfd() const {
    return sockfd;
}

void Client::sendingEvent(std::string msg) {
    msg += "\n";
    /* Send message to the server */
    int n = write(sockfd, msg.c_str(), msg.length());

    if (n < 0) {
        throw CLIENT_ERROR;
    }

}


std::string Client::readMsg() const {
    char buffer[BUFFER_SIZE];
    /* If connection is established then start communicating */
    bzero(buffer, BUFFER_SIZE);
    int n = read(sockfd, buffer, BUFFER_SIZE - 1);

    if (n < 0) {
        throw CLIENT_ERROR;
    }

    return std::string(buffer);


}

std::string Client::getLine() {
    while (line.find(LINE_END) == std::string::npos) {
        line += readMsg();
    }
//    unsigned long i = line.find_first_not_of("\n");
    std::string out = line.substr(0, line.find_first_of(LINE_END));
    line = line.substr(line.find_first_of(LINE_END) + 1, line.size() - 1);
    return out;

}

void Client::inputEvent(IModel::InCallback *callback) {
    callback->in(getLine());
}
