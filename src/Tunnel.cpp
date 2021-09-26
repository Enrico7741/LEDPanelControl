//--------------------------------------------------------------------------------------------------
// LED-Panel-Control
// Copyright (C) 2020 Enrico Schörnick
// Licensed under the MIT License
//--------------------------------------------------------------------------------------------------

#include "Tunnel.hpp"

#include <ctime>
#include <cstdlib>

void Tunnel::init(int yBaseLine)
{
    this->yBaseLine = yBaseLine;
    srand((unsigned) time(0));
    reset();
}

Drawable& Tunnel::getSprite()
{
    return tunnel;
}

int Tunnel::getXPos()
{
    return x;
}

int Tunnel::getYPos()
{
    return y;
}

void Tunnel::step()
{
    x--;
}

bool Tunnel::isOffScreen()
{
    return (tunnel.width() + x) <= 0;
}

void Tunnel::reset()
{
    x = 63;
    y = yBaseLine + (rand() % 2);
}