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

class ControlConnection
{
public:
    ControlConnection(SafeQueue<std::string>& msgQueue) : messageQueue(msgQueue) {}
    void waitForMessages();
private:
    std::string address{"tcp://*:5555"};
    SafeQueue<std::string>& messageQueue;
};

#endif
