//--------------------------------------------------------------------------------------------------
// LED-Panel-Control
// Copyright (C) 2020 Enrico Schörnick
// Licensed under the MIT License
//--------------------------------------------------------------------------------------------------

#include "Background.hpp"

Background::Background(Frame background)
{
    this->background = background;
}

void Background::redraw(Frame &frame)
{
    static int bgPixelPos = 0;
    for(int x = 0; x < 64; x++)
    {
        const auto offset = (bgPixelPos + x) % 64;
        for(int y = 0; y < 64; y++)
        {
            frame.pixel[x][y].R = background.pixel[offset][y].R;
            frame.pixel[x][y].G = background.pixel[offset][y].G;
            frame.pixel[x][y].B = background.pixel[offset][y].B;
        }
    }
    if(bgPixelPos < 63)
    {
        bgPixelPos++;
    }
    else
    {
        bgPixelPos = 0;
    }
}