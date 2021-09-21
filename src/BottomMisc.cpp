//--------------------------------------------------------------------------------------------------
// LED-Panel-Control
// Copyright (C) 2020 Enrico Schörnick
// Licensed under the MIT License
//--------------------------------------------------------------------------------------------------

#include "BottomMisc.hpp"

BottomMisc::BottomMisc(PlantBig plantBigOpen, PlantBig plantBigClosed)
{
    this->plantBigOpen = plantBigOpen;
    this->plantBigClosed = plantBigClosed;
}

void BottomMisc::redraw(Frame &frame)
{
    if(isOpen)
    {
        for(int x = 0; x < 11; x++)
        {
            for(int y = 0; y < 12; y++)
            {
                if (plantBigOpen.pixel[x][y].R != 255)
                {
                    frame.pixel[posX + x][posY + y].R = plantBigOpen.pixel[x][y].R;
                    frame.pixel[posX + x][posY + y].G = plantBigOpen.pixel[x][y].G;
                    frame.pixel[posX + x][posY + y].B = plantBigOpen.pixel[x][y].B;
                }
            }
        }
    }
    else
    {
        for(int x = 0; x < 11; x++)
        {
            for(int x = 0; x < 11; x++)
            {
                for(int y = 0; y < 12; y++)
                {
                    if (plantBigClosed.pixel[x][y].R != 255)
                    {
                        frame.pixel[posX + x][posY + y].R = plantBigClosed.pixel[x][y].R;
                        frame.pixel[posX + x][posY + y].G = plantBigClosed.pixel[x][y].G;
                        frame.pixel[posX + x][posY + y].B = plantBigClosed.pixel[x][y].B;
                    }
                }
            }
        }
    }

    lastSwitch++;

    if(lastSwitch > 3)
    {
        isOpen != isOpen;
    }

    posX--;
    if (posX < -13)
    {
        posX = 63;
    }
    
}