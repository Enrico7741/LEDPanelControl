//--------------------------------------------------------------------------------------------------
// LED-Panel-Control
// Copyright (C) 2020 Enrico Schörnick
// Licensed under the MIT License
//--------------------------------------------------------------------------------------------------

#ifndef SCENE_HPP
#define SCENE_HPP

#include "Drawer.hpp"
#include "BackgroundManager.hpp"
#include "CloudManager.hpp"
#include "CharacterManager.hpp"
#include "BottomMiscManager.hpp"
#include "TopMiscManager.hpp"

#include <array>
#include <stdint.h>

class Scene
{
public:
    Scene(Drawer* drawer, BackgroundManager* background, CloudManager* clouds, CharacterManager* character, BottomMiscManager* bottomMisc, TopMiscManager* topMisc);
    Frame& getNextFrame();

private:
    Drawer* drawer;

    BackgroundManager* background;
    CloudManager* clouds;
    CharacterManager* character;
    BottomMiscManager* bottomMisc;
    TopMiscManager* topMisc;
};

#endif