//--------------------------------------------------------------------------------------------------
// LED-Panel-Control
// Copyright (C) 2020 Enrico Schörnick
// Licensed under the MIT License
//--------------------------------------------------------------------------------------------------

#ifndef MARIO_HPP
#define MARIO_HPP

#include "IDrawable.hpp"

class Mario
{
public:
    Mario(CharacterFrame mario);
    void redraw(Frame &frame);
private:
    CharacterFrame mario;
    const int height = 28;
    const int bottomLine = 54;
    const int topLine = 40;
    const int lowerLimit = bottomLine - height;
    const int upperLimit = topLine - height;

    int posX;
    int posY = lowerLimit;

    bool up = true;

};

#endif