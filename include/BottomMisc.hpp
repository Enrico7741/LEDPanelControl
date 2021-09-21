//--------------------------------------------------------------------------------------------------
// LED-Panel-Control
// Copyright (C) 2020 Enrico Schörnick
// Licensed under the MIT License
//--------------------------------------------------------------------------------------------------

#ifndef BOTTOMMISC_HPP
#define BOTTOMMISC_HPP

#include "IDrawable.hpp"

class BottomMisc
{
public:
    BottomMisc(PlantBig plantBigOpen, PlantBig plantBigClosed);
    void redraw(Frame &frame);
private:
    PlantBig plantBigOpen;
    PlantBig plantBigClosed;
    bool isOpen = true;
    int lastSwitch = 0;
    const int bottomLine = 62;
    const int posY = bottomLine - 12;
    int posX = 63;
};

#endif