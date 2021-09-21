//--------------------------------------------------------------------------------------------------
// LED-Panel-Control
// Copyright (C) 2020 Enrico Schörnick
// Licensed under the MIT License
//--------------------------------------------------------------------------------------------------

#include "TopMisc.hpp"

TopMisc::TopMisc(Tunnel tunnel, PlantSmall plantOpen, PlantSmall plantClosed)
{
    this->tunnel = tunnel;
    this->plantOpen = plantOpen;
    this->plantClosed = plantClosed;
}

void TopMisc::redraw(Frame &frame)
{
        for(int x = 0; x < 14; x++)
        {
            for(int y = 0; y < 18; y++)
            {
                if (tunnel.pixel[x][y].R != 160 && posX + x < 64 && posX + x >= 0)
                {
                    frame.pixel[posX + x][posY + y].R = tunnel.pixel[x][y].R;
                    frame.pixel[posX + x][posY + y].G = tunnel.pixel[x][y].G;
                    frame.pixel[posX + x][posY + y].B = tunnel.pixel[x][y].B;
                }
            }
        }

    posX--;
    if (posX < -16)
    {
        posX = 63;
    }


if(isOpen)
{
    for(int x = 0; x < 11; x++)
        {
            for(int y = 0; y < 11; y++)
            {
                if (plantOpen.pixel[x][y].B != 150 && posXPlant + x < 64 && posXPlant + x >= 0)
                {
                    frame.pixel[posXPlant + x][posYPlant + y].R = plantOpen.pixel[x][y].R;
                    frame.pixel[posXPlant + x][posYPlant + y].G = plantOpen.pixel[x][y].G;
                    frame.pixel[posXPlant + x][posYPlant + y].B = plantOpen.pixel[x][y].B;
                }
            }
        }
}
else
{
for(int x = 0; x < 11; x++)
        {
            for(int y = 0; y < 11; y++)
            {
                if (plantClosed.pixel[x][y].B != 150 && posXPlant + x < 64 && posXPlant + x >= 0)
                {
                    frame.pixel[posXPlant + x][posYPlant + y].R = plantClosed.pixel[x][y].R;
                    frame.pixel[posXPlant + x][posYPlant + y].G = plantClosed.pixel[x][y].G;
                    frame.pixel[posXPlant + x][posYPlant + y].B = plantClosed.pixel[x][y].B;
                }
            }
        }
}

    posXPlant--;
    if (posXPlant < -16)
    {
        posXPlant = 63;
    }

	lastSwitch++;

    if(lastSwitch > 4)
    {
        isOpen = !isOpen;
lastSwitch = 0;
    }


}
