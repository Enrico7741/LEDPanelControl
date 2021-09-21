//--------------------------------------------------------------------------------------------------
// LED-Panel-Control
// Copyright (C) 2020 Enrico Schörnick
// Licensed under the MIT License
//--------------------------------------------------------------------------------------------------

#ifndef SCENE_HPP
#define SCENE_HPP

#include "Background.hpp"
#include "Clouds.hpp"
#include "Mario.hpp"
#include "BottomMisc.hpp"
#include "TopMisc.hpp"

#include <stdint.h>
#include <array>

class Scene
{
public:
    Scene(Background* background, Clouds* clouds, Mario* character, BottomMisc* bottomMisc, TopMisc* topMisc);
    Frame getNextFrame();
private:
    Frame frame;
    Background* background;
    Clouds* clouds;
    Mario* character;
    BottomMisc* bottomMisc;
    TopMisc* topMisc;
    void drawBackground();
    void drawClouds();
    void drawTopMisc();
    void drawCharacter();
    void drawBottomMisc();
};

#endif