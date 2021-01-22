//--------------------------------------------------------------------------------------------------
// LED-Panel-Control
// Copyright (C) 2020 Enrico Schörnick
// Licensed under the MIT License
//--------------------------------------------------------------------------------------------------

#include "led-matrix.h"

#include <chrono>
#include <thread>

using rgb_matrix::RGBMatrix;

int main(int argc, char **argv)
{
    // Set some defaults
    RGBMatrix::Options my_defaults;
    my_defaults.hardware_mapping = "regular"; // or e.g. "adafruit-hat" or "adafruit-hat-pwm"
    my_defaults.chain_length = 1;
    my_defaults.show_refresh_rate = true;
    rgb_matrix::RuntimeOptions runtime_defaults;
    // If you drop privileges, the root user you start the program with
    // to be able to initialize the hardware will be switched to an unprivileged
    // user to minimize a potential security attack surface.
    runtime_defaults.drop_privileges = 1;
    RGBMatrix *matrix = RGBMatrix::CreateFromFlags(&argc, &argv,
                                                   &my_defaults,
                                                   &runtime_defaults);
    if (matrix == NULL)
    {
        PrintMatrixFlags(stderr, my_defaults, runtime_defaults);
        return 1;
    }

    matrix->Fill(100, 100, 100);
    
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    // matrix->ApplyPixelMapper(...);  // Optional

    // Do your own command line handling with the remaining options.

    //  .. now use matrix

    delete matrix; // Make sure to delete it in the end.
}