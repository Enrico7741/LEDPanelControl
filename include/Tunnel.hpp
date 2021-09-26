//--------------------------------------------------------------------------------------------------
// LED-Panel-Control
// Copyright (C) 2020 Enrico Schörnick
// Licensed under the MIT License
//--------------------------------------------------------------------------------------------------

#ifndef TUNNEL_HPP
#define TUNNEL_HPP

#include "Drawable.hpp"

class Tunnel
{
public:
    Tunnel(Drawable tunnel) : tunnel{tunnel} {};
    void init(int yBaseLine);
    Drawable& getSprite();
    int getXPos();
    int getYPos();
    void step();
    bool isOffScreen();
    void reset();

private:
    Drawable tunnel;

    int yBaseLine = 0;

    int x = 63;
    int y = 0;
};

#endif