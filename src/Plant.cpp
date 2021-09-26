//--------------------------------------------------------------------------------------------------
// LED-Panel-Control
// Copyright (C) 2020 Enrico Schörnick
// Licensed under the MIT License
//--------------------------------------------------------------------------------------------------

#include "Plant.hpp"

#include <ctime>
#include <cstdlib>

void Plant::init(int yBaseLine)
{
    this->yBaseLine = yBaseLine;
    srand((unsigned) time(0));
    reset();
}

Drawable& Plant::getSprite()
{
    return isOpen ? open : closed;
}

int Plant::getXPos()
{
    return x;
}

int Plant::getYPos()
{
    return y;
}

void Plant::step()
{
    x--;
    displayedForFrames++;
    if(displayedForFrames >= displayFor)
    {
        isOpen = !isOpen;
        displayedForFrames = 0;
    }
}

bool Plant::isOffScreen()
{
    return (open.width() + x) <= 0;
}

void Plant::reset()
{
    x = 63;
    displayedForFrames = 0;
    displayFor = minDisplayTime + (rand() % 3);
    y = yBaseLine + (rand() % 2);
    isOpen = (rand() % 2) == 0 ? true : false;
}