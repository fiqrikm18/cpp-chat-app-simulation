#include "Message.h"
#include "Channel.hpp"
#include "User.hpp"

std::string Message::get_message() {
    return this->message;
}

User Message::get_sender() {
    return this->sender;
}

void Message::set_sender(User sender) {
    this->sender = sender;
}

void Message::set_message(std::string message) {
    this->message = message;
}
