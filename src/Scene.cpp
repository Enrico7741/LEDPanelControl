//--------------------------------------------------------------------------------------------------
// LED-Panel-Control
// Copyright (C) 2020 Enrico Schörnick
// Licensed under the MIT License
//--------------------------------------------------------------------------------------------------

#include "Scene.hpp"

#include <cstring>
#include <iostream>

Scene::Scene(Background* background, Clouds* clouds, Mario* character, BottomMisc* bottomMisc, TopMisc* topMisc)
{
    this->background = background;
    this->clouds = clouds;
    this->character = character;
    this->bottomMisc = bottomMisc;
    this->topMisc = topMisc;
}

void Scene::drawBackground()
{
    background->redraw(frame);
}

void Scene::drawClouds()
{
    clouds->redraw(frame);
}

void Scene::drawTopMisc()
{
    topMisc->redraw(frame);
}

void Scene::drawCharacter()
{
    character->redraw(frame);
}

void Scene::drawBottomMisc()
{
    bottomMisc->redraw(frame);
}

Frame Scene::getNextFrame()
{
    drawBackground();
    drawClouds();
    drawTopMisc();
    drawCharacter();
    drawBottomMisc();
    
    return frame;
}
