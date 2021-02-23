//--------------------------------------------------------------------------------------------------
// LED-Panel-Control
// Copyright (C) 2020 Enrico Schörnick
// Licensed under the MIT License
//--------------------------------------------------------------------------------------------------

#include "Panel.hpp"

#include <sys/time.h>
#include <math.h>

#include <iostream>
#include <thread>
#include <chrono>

Panel::~Panel()
{
    matrix->Clear();
    delete matrix;
}

bool Panel::initialize()
{
    Magick::InitializeMagick(NULL);

    rgb_matrix::RGBMatrix::Options my_defaults;
    //my_defaults.show_refresh_rate = true;
    my_defaults.brightness = brightness;
    my_defaults.cols = cols;
    my_defaults.rows = rows;
    my_defaults.hardware_mapping = "adafruit-hat-pwm";

    rgb_matrix::RuntimeOptions runtime_defaults;
    runtime_defaults.drop_privileges = 1;
    runtime_defaults.gpio_slowdown = 4;
    runtime_defaults.do_gpio_init = true;

    matrix = rgb_matrix::RGBMatrix::CreateFromOptions(my_defaults, runtime_defaults);

    if (matrix == NULL)
    {
        std::cout << "Error: Couldn't create RGBMatrix." << std::endl;
        return false;
    }

    frame = matrix->CreateFrameCanvas();

    if (frame == NULL)
    {
        std::cout << "Error: Couldn't create frame." << std::endl;
        return false;
    }

    return true;
}

void Panel::run(std::vector<Animation>& animations)
{
    for(int i = 0; i < 20; i++)
    {
        display(animations[0]);
    }
}

void Panel::display(const Animation& animation)
{
    using namespace std::chrono;
    
    rgb_matrix::StreamReader reader(animation.contentStream);

    const auto endTime = steady_clock::now() + milliseconds(animation.animationDurationMs);

    while (steady_clock::now() < endTime)
    {
        uint32_t delayUs = 0;
        while (steady_clock::now() <= endTime && reader.GetNext(frame, &delayUs))
        {
            frame = matrix->SwapOnVSync(frame);
            std::string message;
            if (messageQueue.pop(message))
            {
                if (message.compare("status") != 0)
                {
                    //std::cout << std::stoi(message) << std::endl;
                    frame->~Canvas();
                    frame = matrix->CreateFrameCanvas();

                    matrix->SetBrightness(30);//static_cast<uint8_t>(std::stoi(message)));
                    std::cout << matrix->brightness() << std::endl;
                }
            }
            std::this_thread::sleep_for(milliseconds(animation.animationDelayMs));
        }
        reader.Rewind();
    }
}