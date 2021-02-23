//--------------------------------------------------------------------------------------------------
// LED-Panel-Control
// Copyright (C) 2020 Enrico Schörnick
// Licensed under the MIT License
//--------------------------------------------------------------------------------------------------

#include "Controller.hpp"

#include <iostream>

int main(int argc, char **argv)
{
    Controller controller;
    if(!controller.initialize())
    {
        std::cout << "Error: Couldn't initialize controller." << std::endl;
        return false;
    }

    controller.start();

    return true;
}