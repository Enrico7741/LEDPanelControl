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

#include <stdint.h>
#include <array>

class Scene
{
public:
    Scene(Background* background, Clouds* clouds, Mario* character);
    Frame getNextFrame();
private:
    Frame frame;
    IDrawable* background;
    IDrawable* clouds;
    Mario* character;
    void drawBackground();
    void drawClouds();
    void drawCharacter();
};

#endif