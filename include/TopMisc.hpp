//--------------------------------------------------------------------------------------------------
// LED-Panel-Control
// Copyright (C) 2020 Enrico Schörnick
// Licensed under the MIT License
//--------------------------------------------------------------------------------------------------

#ifndef TOPMISC_HPP
#define TOPMISC_HPP

#include "IDrawable.hpp"

class TopMisc
{
public:
    TopMisc(Tunnel tunnel, PlantSmall plantOpen, PlantSmall plantClosed);
    void redraw(Frame &frame);
private:
    Tunnel tunnel;
    PlantSmall plantOpen;
    PlantSmall plantClosed;
    const int bottomLine = 26;
    const int posY = bottomLine - 13;
    int posX = 20;
   int posXPlant = 45;
   const int posYPlant = bottomLine - 5;
   bool isOpen = true;
   int lastSwitch = 0;
};

#endif
