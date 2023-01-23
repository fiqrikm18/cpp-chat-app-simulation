#include "Channel.hpp"
#include "Message.h"

std::vector<Channel*> Channel::channel_list;

Channel::Channel() {
    this->name = "default channel name";
    Channel::channel_list.push_back(this);
}

Channel::Channel(std::string name) {
    this->name = name;
    Channel::channel_list.push_back(this);
}

void Channel::set_name(std::string name) {
    this->name = name;
}

std::string Channel::get_name() {
    return this->name;
}

std::vector<Channel*> Channel::get_channels() {
    return channel_list;
}

void Channel::active(bool status) {
    this->status = status;
}

bool Channel::is_active() const {
    return this->status;
}

void Channel::add_member(User user) {
    if (!this->status) std::cout << "You can't join to inactive channel." << std::endl;
    else {
        this->channel_members.push_back(user);
        std::cout << user.get_name() << " join to channel " << this->get_name() << std::endl;
    }
}

std::vector<User> Channel::get_channel_members() {
    return this->channel_members;
}

void Channel::get_channel_by_member(User user, std::vector<Channel> *dst) {
    for (Channel *ch: channel_list)
        for (User member: ch->get_channel_members())
            if (member.get_name() == user.get_name()) dst->push_back(*ch);
}

std::vector<Message> Channel::get_channel_conversation() {
    return this->channel_conversation;
}

void Channel::add_conversation(Message message) {
    this->channel_conversation.push_back(message);
}
