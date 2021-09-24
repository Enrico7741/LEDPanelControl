//--------------------------------------------------------------------------------------------------
// LED-Panel-Control
// Copyright (C) 2020 Enrico Schörnick
// Licensed under the MIT License
//--------------------------------------------------------------------------------------------------

#ifndef CLOUDMANAGER_HPP
#define CLOUDMANAGER_HPP

#include "Drawer.hpp"
#include "Drawable.hpp"

class CloudManager
{
public:
    CloudManager(Drawer* drawer, Drawable clouds) : clouds{clouds} {this->drawer = drawer;};
    void redraw();
    
private:
    Drawer* drawer;
    
    Drawable clouds;
    int framesUntilShift = 20;
    int cloudShift = 0;

    void adjustCounters();
};

#endif