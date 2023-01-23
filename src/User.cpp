#include "User.hpp"
#include "Message.h"
#include "Channel.hpp"

void User::set_name(std::string name) {
    this->name = name;
}

std::string User::get_name() {
    return this->name;
}

void User::send_message(Message message, Channel* channel) {
    message.set_sender(*this);
    channel->add_conversation(message);
}
