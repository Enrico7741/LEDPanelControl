//--------------------------------------------------------------------------------------------------
// LED-Panel-Control
// Copyright (C) 2020 Enrico Schörnick
// Licensed under the MIT License
//--------------------------------------------------------------------------------------------------

#include "CloudManager.hpp"

void CloudManager::redraw()
{
    drawer->draw(clouds, cloudShift);
    adjustCounters();
}

void CloudManager::adjustCounters()
{
    if(framesUntilShift == 0)
    {
        if(cloudShift < 63)
        {
            cloudShift++;
        }
        else
        {
            cloudShift = 0;
        }

        framesUntilShift = 23;
    }
    else
    {
        framesUntilShift--;
    }
}