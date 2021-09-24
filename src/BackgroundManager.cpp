//--------------------------------------------------------------------------------------------------
// LED-Panel-Control
// Copyright (C) 2020 Enrico Schörnick
// Licensed under the MIT License
//--------------------------------------------------------------------------------------------------

#include "BackgroundManager.hpp"

void BackgroundManager::redraw()
{
    drawer->draw(background, backgroundShift);

    if(backgroundShift < 63)
    {
        backgroundShift++;
    }
    else
    {
        backgroundShift = 0;
    }
}