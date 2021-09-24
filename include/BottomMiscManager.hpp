//--------------------------------------------------------------------------------------------------
// LED-Panel-Control
// Copyright (C) 2020 Enrico Schörnick
// Licensed under the MIT License
//--------------------------------------------------------------------------------------------------

#ifndef BOTTOMMISCMANAGER_HPP
#define BOTTOMMISCMANAGER_HPP

#include "Drawer.hpp"
#include "Drawable.hpp"

class BottomMiscManager
{
public:
    BottomMiscManager(Drawer* drawer, Drawable plantBigOpen, Drawable plantBigClosed) : plantBigOpen{plantBigOpen}, plantBigClosed{plantBigClosed} {this->drawer = drawer;};
    void redraw();

private:
    Drawer* drawer;

    Drawable plantBigOpen;
    Drawable plantBigClosed;

    int posX = 63;
    const int posY = 51;
    bool isOpen = true;
    int framesUntilSwitch = 6;

    void adjustCounters();
};

#endif
