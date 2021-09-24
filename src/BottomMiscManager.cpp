//--------------------------------------------------------------------------------------------------
// LED-Panel-Control
// Copyright (C) 2020 Enrico Schörnick
// Licensed under the MIT License
//--------------------------------------------------------------------------------------------------

#include "BottomMiscManager.hpp"

#include <iostream>

void BottomMiscManager::redraw()
{
    auto& plant = isOpen ? plantBigOpen : plantBigClosed;
    drawer->draw(plant, posX, posY);
    adjustCounters();
}

void BottomMiscManager::adjustCounters()
{
    if(framesUntilSwitch == 0)
    {
        isOpen = !isOpen;
        framesUntilSwitch = 5;
    }
    else
    {
        framesUntilSwitch--;
    }

    posX--;
    if (posX < -15)
    {
        posX = 63;
    }
}