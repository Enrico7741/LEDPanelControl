//--------------------------------------------------------------------------------------------------
// LED-Panel-Control
// Copyright (C) 2020 Enrico Schörnick
// Licensed under the MIT License
//--------------------------------------------------------------------------------------------------

#include "Mario.hpp"

Mario::Mario(CharacterFrame mario)
{
    this->mario = mario;
}

void Mario::redraw(Frame &frame)
{
    if(up)
    {
        if(posY > upperLimit)
        {
            posY--;
            if(posY == upperLimit)
            {
                up = false;
            }
        }
    }
    else
    {
        if(posY < lowerLimit)
        {
            posY++;
            if(posY == lowerLimit)
            {
                up = true;
            }
        }
    }
    const int heigthOffset = upperLimit;
    const int widthOffset = 18;

    for(int x = 0; x < 28; x++)
    {
        const auto offset =  x;
        for(int y = 0; y < 30; y++)
        {
            if(mario.pixel[offset][y].R != 65)
            {
            frame.pixel[x+widthOffset][y+posY].R = mario.pixel[offset][y].R;
            frame.pixel[x+widthOffset][y+posY].B = mario.pixel[offset][y].B;
            frame.pixel[x+widthOffset][y+posY].G = mario.pixel[offset][y].G;

            }
        }
    }
}