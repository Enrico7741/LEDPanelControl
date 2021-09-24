//--------------------------------------------------------------------------------------------------
// LED-Panel-Control
// Copyright (C) 2020 Enrico Schörnick
// Licensed under the MIT License
//--------------------------------------------------------------------------------------------------

#include "TopMiscManager.hpp"

void TopMiscManager::redraw()
{
    drawer->draw(tunnel, tunnelX, tunnelY);

    auto& plant = isOpen ? plantOpen : plantClosed;
    drawer->draw(plant, plantX, plantY);

    adjustCounters();
}

void TopMiscManager::adjustCounters()
{
    tunnelX--;
    if (tunnelX < -16)
    {
        tunnelX = 63;
    }

    plantX--;
    if (plantX < -16)
    {
        plantX = 63;
    }

    if(framesUntilSwitch == 0)
    {
        isOpen = !isOpen;
        framesUntilSwitch = 5;
    }
    else
    {
        framesUntilSwitch--;
    }
}