//--------------------------------------------------------------------------------------------------
// LED-Panel-Control
// Copyright (C) 2020 Enrico Schörnick
// Licensed under the MIT License
//--------------------------------------------------------------------------------------------------

#include "ControlConnection.hpp"

#include <zmq.hpp>
#include <string>
#include <iostream>
#include <queue>

void ControlConnection::waitForMessages()
{
    // Prepare a context and socket
    zmq::context_t context;
    zmq::socket_t socket(context, ZMQ_REP);

    // Listen on port 5555 for a tcp connection
    socket.bind(address);

    while (true)
    {
        // Request to handle
        zmq::message_t request;

        // Wait for the next request
        socket.recv(&request);
        
        auto replyMessage = std::string(static_cast<char *>(request.data()), request.size());

        messageQueue.push(replyMessage);

        std::string msgToClient;
        if(replyMessage.compare("status") == 0)
        {
            msgToClient = "on 80";
        }
        else if (replyMessage.compare("turn off") == 0)
        {
            msgToClient = "turned off";
        }
        else if (replyMessage.compare("turn on") == 0)
        {
            msgToClient = "turned on";
        }
        else
        {
            msgToClient = replyMessage;
        }

        //  Send reply back to client
        zmq::message_t reply(msgToClient.size());
        memcpy((void *) reply.data(), (msgToClient.c_str()), msgToClient.size());
        socket.send(reply);
    }

    // Unbind from address
    socket.unbind(address);

    // Destroy context
    context.shutdown();
    context.close();
}
