//--------------------------------------------------------------------------------------------------
// LED-Panel-Control
// Copyright (C) 2020 Enrico Schörnick
// Licensed under the MIT License
//--------------------------------------------------------------------------------------------------

#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include "Panel.hpp"
#include "SceneCreator.hpp"
#include "ControlConnection.hpp"

class Controller
{
public:
    Controller();
    ~Controller();
    bool initialize();
    void start();

private:
    SceneCreator* sceneCreator;
    SafeQueue<std::string> messages{};
    Panel* panel;
    ControlConnection* controlConnection;
};

#endif