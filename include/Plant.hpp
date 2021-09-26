//--------------------------------------------------------------------------------------------------
// LED-Panel-Control
// Copyright (C) 2020 Enrico Schörnick
// Licensed under the MIT License
//--------------------------------------------------------------------------------------------------

#ifndef PLANT_HPP
#define PLANT_HPP

#include "Drawable.hpp"

class Plant
{
public:
    Plant(Drawable open, Drawable closed) : open{open}, closed{closed} {};
    void init(int yBaseLine);
    Drawable& getSprite();
    int getXPos();
    int getYPos();
    void step();
    bool isOffScreen();
    void reset();

private:
    Drawable open;
    Drawable closed;

    const int minDisplayTime = 4;
    int displayFor = minDisplayTime;
    int yBaseLine = 0;

    int x = 63;
    int y = 0;

    bool isOpen = true;
    int displayedForFrames = 0;  
};

#endif