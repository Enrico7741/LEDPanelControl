//--------------------------------------------------------------------------------------------------
// LED-Panel-Control
// Copyright (C) 2020 Enrico Schörnick
// Licensed under the MIT License
//--------------------------------------------------------------------------------------------------

#include "Controller.hpp"
#include "SafeQueue.hpp"

#include <chrono>
#include <thread>

Controller::Controller()
{
    panel = new Panel(messages);
    sceneCreator = new SceneCreator();
    controlConnection = new ControlConnection(messages);
}

Controller::~Controller()
{
    delete panel;
    delete sceneCreator;
    delete controlConnection;
}

bool Controller::initialize()
{
    sceneCreator->createMarioKartScene();
    return panel->initialize() && controlConnection->initialize();
}

void Controller::start()
{
    std::thread controlThread(&ControlConnection::waitForMessages, controlConnection);
    std::thread panelThread(&Panel::run, panel, std::ref(*sceneCreator));
    controlThread.join();
    panelThread.join();
}