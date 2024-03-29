//--------------------------------------------------------------------------------------------------
// LED-Panel-Control
// Copyright (C) 2020 Enrico Schörnick
// Licensed under the MIT License
//--------------------------------------------------------------------------------------------------

#ifndef BOTTOMMISCMANAGER_HPP
#define BOTTOMMISCMANAGER_HPP

#include "Drawer.hpp"
#include "Drawable.hpp"
#include "Plant.hpp"

class BottomMiscManager
{
public:
    BottomMiscManager(Drawer* drawer, Plant plant);
    void redraw();

private:
    Drawer* drawer;
    Plant plant;
    bool isOnScreen = true;
    int reappearDelay = 0;
};

#endif
