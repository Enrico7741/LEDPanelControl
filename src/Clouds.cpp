//--------------------------------------------------------------------------------------------------
// LED-Panel-Control
// Copyright (C) 2020 Enrico Schörnick
// Licensed under the MIT License
//--------------------------------------------------------------------------------------------------

#include "Clouds.hpp"

Clouds::Clouds(Frame clouds)
{
    this->clouds = clouds;
}

void Clouds::redraw(Frame &frame)
{
    static int cloudsPixelPos = 0;
    static int counter20 = 0;

    for(int x = 0; x < 64; x++)
    {
        const auto offset = (cloudsPixelPos + x) % 64;
        for(int y = 0; y < 64; y++)
        {
            if (clouds.pixel[offset][y].R == 255)
            {
            frame.pixel[x][y].R = clouds.pixel[offset][y].R;
            frame.pixel[x][y].G = clouds.pixel[offset][y].G;
            frame.pixel[x][y].B = clouds.pixel[offset][y].B;
            }
        }
    }

    if(cloudsPixelPos < 63)
    {
        if(counter20 % 20 == 0)
        {
        cloudsPixelPos++;
        }
    }
    else
    {
        cloudsPixelPos = 0;
    }

    counter20++;
}