//--------------------------------------------------------------------------------------------------
// LED-Panel-Control
// Copyright (C) 2020 Enrico Schörnick
// Licensed under the MIT License
//--------------------------------------------------------------------------------------------------

#ifndef CHARACTERMANAGER_HPP
#define CHARACTERMANAGER_HPP

#include "Drawer.hpp"
#include "Drawable.hpp"

class CharacterManager
{
public:
    CharacterManager(Drawer* drawer, Drawable mario) : mario{mario} {this->drawer = drawer;};
    void redraw();
    
private:
    Drawer* drawer;
    
    Drawable mario;

    const int lowerLimit = 25;
    const int upperLimit = 10;

    int posX = 0;
    int posY = upperLimit;
};

#endif
