#ifndef User_hpp
#define User_hpp

#include <iostream>

class Channel;
class Message;

class User {
private:
    std::string name;
    
public:
    std::string get_name();
    void set_name(std::string name);

    void send_message(Message message, Channel* channel);
};

#endif /* User_hpp */
