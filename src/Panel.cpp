//--------------------------------------------------------------------------------------------------
// LED-Panel-Control
// Copyright (C) 2020 Enrico Schörnick
// Licensed under the MIT License
//--------------------------------------------------------------------------------------------------

#include "Panel.hpp"

#include <iostream>

Panel::~Panel()
{
    delete matrix;
}

bool Panel::initialize()
{
    RGBMatrix::Options my_defaults;
    my_defaults.show_refresh_rate = true;
    my_defaults.brightness = brightness;
    my_defaults.cols = cols;
    my_defaults.rows = rows;

    rgb_matrix::RuntimeOptions runtime_defaults;
    runtime_defaults.drop_privileges = 1;
    runtime_defaults.gpio_slowdown = 4;

    matrix = RGBMatrix::CreateFromOptions(my_defaults, runtime_defaults);

    if (matrix == NULL)
    {
        std::cout << "Error: Couldn't create RGBMatrix." << std::endl;
        return false;
    }

    frame = matrix->CreateFrameCanvas();

    return true;
}