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
    return panel->initialize() && imageManager->initialize(panel->frame);
}

void Controller::start()
{
    std::thread controlThread(&ControlConnection::waitForMessages, controlConnection);
    std::thread panelThread(&Panel::run, panel, std::ref(imageManager->other));
    controlThread.join();
    panelThread.join();
}