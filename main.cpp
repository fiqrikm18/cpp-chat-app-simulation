#include <iostream>
#include "src/Channel.hpp"
#include "src/User.hpp"

int main(int argc, const char * argv[]) {
    Channel chan_one("channel one");
    chan_one.active(true);
    
    Channel chan_two("channel two");
    chan_two.active(true);
    
    std::vector<Channel*> channels = Channel::get_channels();
    
    std::cout << "Channel List: " << std::endl;
    for (Channel *ch: channels) {
        std::string channel_status = ch->is_active() ? "Active" : "Inactive";
        std::cout << "Name: \t\t" << ch->get_name() << std::endl;
        std::cout << "Status: \t" << channel_status << std::endl;
        std::cout << "==================================================" << std::endl;
    }
    
    std::cout << std::endl;
    
    User bob;
    bob.set_name("Bob");
    
    User maria;
    maria.set_name("Maria");
    
    chan_one.add_member(bob);
    chan_two.add_member(maria);

    std::cout << std::endl;

    std::vector<Channel> bob_joined_chan;
    std::vector<Channel> maria_joined_chan;

    Channel::get_channel_by_member(bob, &bob_joined_chan);
    Channel::get_channel_by_member(maria, &maria_joined_chan);

    std::cout << "Bob Channel List: " << std::endl;
    for (Channel ch: bob_joined_chan) {
        std::cout << "Name: \t\t" << ch.get_name() << std::endl;
    }

    std::cout << "==================================================" << std::endl;
    std::cout << "Maria Channel List: " << std::endl;
    for (Channel ch: maria_joined_chan) {
        std::cout << "Name: \t\t" << ch.get_name() << std::endl;
    }

    std::cout << "==================================================" << std::endl;
    std::cout << std::endl;

    User mike;
    mike.set_name("Mike");

    chan_two.active(false);
    chan_two.add_member(mike);

    chan_two.active(true);
    chan_two.add_member(mike);

    std::vector<User> chan_one_members = chan_one.get_channel_members();
    std::vector<User> chan_two_members = chan_two.get_channel_members();

    std::cout << std::endl;
    std::cout << "Channel One Member List: " << std::endl;
    for (User member: chan_one_members) {
        std::cout << "Name: \t\t" << member.get_name() << std::endl;
    }

    std::cout << "==================================================" << std::endl;
    std::cout << "Channel Two Member List: " << std::endl;
    for (User member: chan_two_members) {
        std::cout << "Name: \t\t" << member.get_name() << std::endl;
    }

    std::cout << "==================================================" << std::endl;
    std::cout << std::endl;

    Message msg;
    msg.set_message("Hello");
    bob.send_message(msg, &chan_one);
    maria.send_message(msg, &chan_two);

    msg.set_message("hai");
    mike.send_message(msg, &chan_two);

    std::vector<Message> chan_one_conversation = chan_one.get_channel_conversation();
    std::vector<Message> chan_two_conversation = chan_two.get_channel_conversation();

    std::cout << "Channel One Conversation: " << std::endl;
    for (Message m: chan_one_conversation) {
        std::cout << m.get_sender().get_name() << ": " << m.get_message() << std::endl;
    }

    std::cout << "==================================================" << std::endl;
    std::cout << "Channel Two Conversation: " << std::endl;
    for (Message m: chan_two_conversation) {
        std::cout << m.get_sender().get_name() << ": " << m.get_message() << std::endl;
    }

    std::cout << "==================================================" << std::endl;
    std::cout << std::endl;

    return 0;
}
