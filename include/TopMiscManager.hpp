//--------------------------------------------------------------------------------------------------
// LED-Panel-Control
// Copyright (C) 2020 Enrico Schörnick
// Licensed under the MIT License
//--------------------------------------------------------------------------------------------------

#ifndef TOPMISCMANAGER_HPP
#define TOPMISCMANAGER_HPP

#include "Drawer.hpp"
#include "Drawable.hpp"

class TopMiscManager
{
public:
    TopMiscManager(Drawer* drawer, Drawable tunnel, Drawable plantOpen, Drawable plantClosed) : tunnel{tunnel}, plantOpen{plantOpen}, plantClosed{plantClosed} {this->drawer = drawer;};
    void redraw();

private:
    Drawer* drawer;

    Drawable tunnel;
    Drawable plantOpen;
    Drawable plantClosed;

    const int tunnelY = 13;
    int tunnelX = 20;
    
    int plantX = 45;
    const int plantY = 20;

    bool isOpen = true;
    int framesUntilSwitch = 4;
    
    void adjustCounters();
};

#endif
