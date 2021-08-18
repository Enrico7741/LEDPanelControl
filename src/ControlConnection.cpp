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
    while (true)
    {
        // Request to handle
        zmq::message_t request;

        // Wait for the next request
        socket.recv(&request);
        
        auto replyMessage = std::string(static_cast<char *>(request.data()), request.size());

        messageQueue.push(replyMessage);

        std::string msgToClient;

        msgToClient = replyMessage;
        
        //  Send reply back to client
        zmq::message_t reply(msgToClient.size());
        memcpy((void *) reply.data(), (msgToClient.c_str()), msgToClient.size());
        socket.send(reply);
    }
}