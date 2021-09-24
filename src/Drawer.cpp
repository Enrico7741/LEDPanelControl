//--------------------------------------------------------------------------------------------------
// LED-Panel-Control
// Copyright (C) 2020 Enrico Schörnick
// Licensed under the MIT License
//--------------------------------------------------------------------------------------------------

#include "Drawer.hpp"

Frame& Drawer::getCurrentFrame()
{
    return frame;
}

void Drawer::draw(Drawable& sprite, int xPos, int yPos)
{
    for(int x = 0; x < sprite.width(); x++)
    {
        for(int y = 0; y < sprite.height(); y++)
        {
            if (sprite.getPixels()[x][y].B != 150 && xPos + x < 64 && xPos + x >= 0)
            {
		        frame.pixel[xPos + x][yPos + y] = sprite.getPixels()[x][y];
            }
        }
    }
}

void Drawer::draw(Drawable& sprite, int shift)
{
    for(int x = 0; x < sprite.width(); x++)
    {
        const auto offset = (shift + x) % 64;
        for(int y = 0; y < sprite.height(); y++)
        {
		    frame.pixel[x][y] = sprite.getPixels()[offset][y];
        }
    }
}