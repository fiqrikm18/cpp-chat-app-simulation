cmake_minimum_required(VERSION 3.24)
project(Chatting_Application)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(Chatting_Application
        src/Channel.cpp
        src/Channel.hpp
        src/User.cpp
        src/User.hpp
        main.cpp
        src/Message.cpp src/Message.h)
