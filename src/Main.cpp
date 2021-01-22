//--------------------------------------------------------------------------------------------------
// LED-Panel-Control
// Copyright (C) 2020 Enrico Schörnick
// Licensed under the MIT License
//--------------------------------------------------------------------------------------------------

#include "Panel.hpp"

#include <chrono>
#include <thread>

int main(int argc, char **argv)
{
    Panel panel;
    panel.initialize();
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
}