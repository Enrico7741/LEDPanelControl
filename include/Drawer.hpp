//--------------------------------------------------------------------------------------------------
// LED-Panel-Control
// Copyright (C) 2020 Enrico Schörnick
// Licensed under the MIT License
//--------------------------------------------------------------------------------------------------

#ifndef DRAWER_HPP
#define DRAWER_HPP

#include "Drawable.hpp"

class Drawer
{
public:
    Frame& getCurrentFrame();
    void draw(Drawable& sprite, int xPos, int yPos);
    void draw(Drawable& sprite, int shift);

private:
    Frame frame;
};

#endif