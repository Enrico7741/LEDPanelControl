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
    imageManager = new ImageManager();
    controlConnection = new ControlConnection(messages);
}

Controller::~Controller()
{
    delete panel;
    delete imageManager;
    delete controlConnection;
}

bool Controller::initialize()
{
    return panel->initialize() && imageManager->initialize() && controlConnection->initialize();
}

void Controller::start()
{
    std::thread controlThread(&ControlConnection::waitForMessages, controlConnection);
    std::thread panelThread(&Panel::run, panel, std::ref(*imageManager));
    controlThread.join();
    panelThread.join();
}