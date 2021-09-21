//--------------------------------------------------------------------------------------------------
// LED-Panel-Control
// Copyright (C) 2020 Enrico Schörnick
// Licensed under the MIT License
//--------------------------------------------------------------------------------------------------

#include "TopMisc.hpp"

TopMisc::TopMisc(Tunnel tunnel)
{
    this->tunnel = tunnel;
}

void TopMisc::redraw(Frame &frame)
{
        for(int x = 0; x < 14; x++)
        {
            for(int y = 0; y < 18; y++)
            {
                if (plantBigOpen.pixel[x][y].R != 255)
                {
                    frame.pixel[posX + x][posY + y].R = plantBigOpen.pixel[x][y].R;
                    frame.pixel[posX + x][posY + y].G = plantBigOpen.pixel[x][y].G;
                    frame.pixel[posX + x][posY + y].B = plantBigOpen.pixel[x][y].B;
                }
            }
        }

    posX--;
    if (posX < -16)
    {
        posX = 63;
    }
}