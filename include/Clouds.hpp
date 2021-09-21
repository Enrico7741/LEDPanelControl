//--------------------------------------------------------------------------------------------------
// LED-Panel-Control
// Copyright (C) 2020 Enrico Schörnick
// Licensed under the MIT License
//--------------------------------------------------------------------------------------------------

#ifndef CLOUDS_HPP
#define CLOUDS_HPP

#include "IDrawable.hpp"

class Clouds
{
public:
    Clouds(Frame clouds);
    void redraw(Frame &frame);
private:
    Frame clouds;
};

#endif