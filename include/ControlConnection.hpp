//--------------------------------------------------------------------------------------------------
// LED-Panel-Control
// Copyright (C) 2020 Enrico Schörnick
// Licensed under the MIT License
//--------------------------------------------------------------------------------------------------

#ifndef CONTROLCONNECTION_HPP
#define CONTROLCONNECTION_HPP

#include "SafeQueue.hpp"

#include <queue>
#include <string>
#include <zmq.hpp>

class ControlConnection
{
public:
    ControlConnection(SafeQueue<std::string>& msgQueue) : messageQueue(msgQueue) {}
    bool initialize();
    void waitForMessages();
    
private:
    zmq::socket_t socket;
    zmq::context_t context;
    std::string address{"tcp://*:5555"};
    SafeQueue<std::string>& messageQueue;
};

#endif
