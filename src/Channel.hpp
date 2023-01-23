#ifndef Channel_hpp
#define Channel_hpp

#include <iostream>
#include <vector>
#include "Message.h"
#include "User.hpp"


class Channel {
private:
    std::string name;
    bool status = false;
    std::vector<Message> channel_conversation;
    std::vector<User> channel_members;
    
    static std::vector<Channel*> channel_list;

public:
    Channel();
    Channel(std::string name);
    
    std::string get_name();
    std::vector<User> get_channel_members();
    std::vector<Message> get_channel_conversation();
    bool is_active() const;
    
    void set_name(std::string name);
    void active(bool status);
    void add_member(User user);
    void add_conversation(Message message);

    static std::vector<Channel*> get_channels();
    static void get_channel_by_member(User user, std::vector<Channel> *dst);
};

#endif /* Channel_hpp */
