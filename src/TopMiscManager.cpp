//--------------------------------------------------------------------------------------------------
// LED-Panel-Control
// Copyright (C) 2020 Enrico Schörnick
// Licensed under the MIT License
//--------------------------------------------------------------------------------------------------

#include "TopMiscManager.hpp"

TopMiscManager::TopMiscManager(Drawer* drawer, Tunnel tunnel, Plant plant) : tunnel{tunnel}, plant{plant}
{
    this->drawer = drawer;
    this->plant.init(20);
    this->tunnel.init(12);
}

void TopMiscManager::redraw()
{
    drawer->draw(tunnel.getSprite(), tunnel.getXPos(), tunnel.getYPos());

    drawer->draw(plant.getSprite(), plant.getXPos(), plant.getYPos());

    plant.step();
    if(plant.isOffScreen())
    {
        plant.reset();
    }

    tunnel.step();
    if(tunnel.isOffScreen())
    {
        tunnel.reset();
    }
}