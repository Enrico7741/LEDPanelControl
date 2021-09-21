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
   static int onEdgeCounter = 15;
    static bool onEdge = true;
    static int widthOffset = 18;
if(onEdge)
{
 onEdgeCounter--;
if(onEdgeCounter == 0)
{
onEdge = false;
onEdgeCounter = 4;
}

}
else
{    

if(up)
    {
        if(posY > upperLimit)
        {
            posY--;
            if(posY == upperLimit)
            {
                up = false;
		onEdge = true;
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
		onEdge = true;
            }
        }
    }
}

    const int heigthOffset = upperLimit;

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
