#ifndef CHATTING_APPLICATION_MESSAGE_H
#define CHATTING_APPLICATION_MESSAGE_H

#include <iostream>
#include <vector>
#include "User.hpp"


class Channel;

class Message {
private:
    std::string message;
    User sender;

public:
    std::string get_message();
    User get_sender();

    void set_sender(User sender);
    void set_message(std::string message);
};


#endif //CHATTING_APPLICATION_MESSAGE_H
