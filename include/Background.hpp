//--------------------------------------------------------------------------------------------------
// LED-Panel-Control
// Copyright (C) 2020 Enrico Schörnick
// Licensed under the MIT License
//--------------------------------------------------------------------------------------------------

#ifndef BACKGROUND_HPP
#define BACKGROUND_HPP

#include "IDrawable.hpp"

class Background
{
public:
    Background(Frame background);
    void redraw(Frame &frame);
private:
    Frame background;
};

#endif