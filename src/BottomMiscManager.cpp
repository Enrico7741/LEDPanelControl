//--------------------------------------------------------------------------------------------------
// LED-Panel-Control
// Copyright (C) 2020 Enrico Schörnick
// Licensed under the MIT License
//--------------------------------------------------------------------------------------------------

#include "BottomMiscManager.hpp"

#include <ctime>
#include <cstdlib>

BottomMiscManager::BottomMiscManager(Drawer* drawer, Plant plant) : plant{plant}
{
    this->drawer = drawer;
    this->plant.init(50);
    srand((unsigned) time(0));
}

void BottomMiscManager::redraw()
{
    if (isOnScreen)
    {
        drawer->draw(plant.getSprite(), plant.getXPos(), plant.getYPos());
        plant.step();
        if(plant.isOffScreen())
        {
            isOnScreen = false;
            reappearDelay = (rand() % 10);
        }
    }
    else
    {
        reappearDelay--;
        if(reappearDelay <= 0)
        {
            isOnScreen = true;
            plant.reset();
        }
    }
}