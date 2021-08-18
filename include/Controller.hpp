//--------------------------------------------------------------------------------------------------
// LED-Panel-Control
// Copyright (C) 2020 Enrico Schörnick
// Licensed under the MIT License
//--------------------------------------------------------------------------------------------------

#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include "Panel.hpp"
#include "ImageManager.hpp"
#include "ControlConnection.hpp"

class Controller
{
private:
    ImageManager* imageManager;
    SafeQueue<std::string> messages{};
    Panel* panel;
    ControlConnection* controlConnection;
    
public:
    Controller();
    ~Controller();
    bool initialize();
    void start();
    void display();
};

#endif