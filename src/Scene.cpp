//--------------------------------------------------------------------------------------------------
// LED-Panel-Control
// Copyright (C) 2020 Enrico Schörnick
// Licensed under the MIT License
//--------------------------------------------------------------------------------------------------

#include "Scene.hpp"

#include <cstring>
#include <iostream>

Scene::Scene(Drawer* drawer, BackgroundManager* background, CloudManager* clouds, CharacterManager* character, BottomMiscManager* bottomMisc, TopMiscManager* topMisc)
{
    this->drawer = drawer;
    this->background = background;
    this->clouds = clouds;
    this->character = character;
    this->bottomMisc = bottomMisc;
    this->topMisc = topMisc;
}

Frame& Scene::getNextFrame()
{
    background->redraw();
    clouds->redraw();
    topMisc->redraw();
    character->redraw();
    bottomMisc->redraw();
    
    return drawer->getCurrentFrame();
}