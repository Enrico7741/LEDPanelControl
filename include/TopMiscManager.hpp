//--------------------------------------------------------------------------------------------------
// LED-Panel-Control
// Copyright (C) 2020 Enrico Schörnick
// Licensed under the MIT License
//--------------------------------------------------------------------------------------------------

#ifndef TOPMISCMANAGER_HPP
#define TOPMISCMANAGER_HPP

#include "Drawer.hpp"
#include "Drawable.hpp"
#include "Plant.hpp"
#include "Tunnel.hpp"

class TopMiscManager
{
public:
    TopMiscManager(Drawer* drawer, Tunnel tunnel, Plant plant);
    void redraw();

private:
    Drawer* drawer;

    Tunnel tunnel;
    Plant plant;
};

#endif
