//--------------------------------------------------------------------------------------------------
// LED-Panel-Control
// Copyright (C) 2020 Enrico Schörnick
// Licensed under the MIT License
//--------------------------------------------------------------------------------------------------

#include "ControlConnection.hpp"

#include <queue>
#include <string>
#include <zmq.hpp>
#include <iostream>

#define ZMQ_CPP11

bool ControlConnection::initialize()
{
    socket = zmq::socket_t(context, ZMQ_REP);
    if (socket == nullptr)
    {
        return false;
    }

    socket.bind(address);

    return true;
}

void ControlConnection::waitForMessages()
{
    // Request to handle
    zmq::message_t request;

    while (true)
    { 
        // Wait for the next request
        socket.recv(request);
        
        auto incomingMsg = std::string(static_cast<char *>(request.data()), request.size());
        messageQueue.push(incomingMsg);
        
        // Send reply back to client
        zmq::message_t reply(request.data(), request.size());
        socket.send(reply, zmq::send_flags::none);
    }
}