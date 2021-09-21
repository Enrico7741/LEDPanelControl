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
    TopMisc(Tunnel tunnel);
    void redraw(Frame &frame);
private:
    Tunnel tunnel;
    const int bottomLine = 30;
    const int posY = bottomLine - 14;
    int posX = 20;
};

#endif