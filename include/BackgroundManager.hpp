//--------------------------------------------------------------------------------------------------
// LED-Panel-Control
// Copyright (C) 2020 Enrico Schörnick
// Licensed under the MIT License
//--------------------------------------------------------------------------------------------------

#ifndef BACKGROUNDMANAGER_HPP
#define BACKGROUNDMANAGER_HPP

#include "Drawer.hpp"
#include "Drawable.hpp"

class BackgroundManager
{
public:
    BackgroundManager(Drawer* drawer, Drawable background) : background{background} {this->drawer = drawer;};
    void redraw();
    
private:
    Drawer* drawer;
    
    Drawable background;
    int backgroundShift = 0;
};

#endif