//--------------------------------------------------------------------------------------------------
// LED-Panel-Control
// Copyright (C) 2020 Enrico Schörnick
// Licensed under the MIT License
//--------------------------------------------------------------------------------------------------

#include "Scene.hpp"

#include <cstring>
#include <iostream>

Scene::Scene(Background* background, Clouds* clouds, Mario* character)
{
    this->background = background;
    this->clouds = clouds;
    this->character = character;
}

void Scene::drawBackground()
{
    background->redraw(frame);
}

void Scene::drawClouds()
{
    clouds->redraw(frame);
}

void Scene::drawCharacter()
{
    character->redraw(frame);
}

Frame Scene::getNextFrame()
{
    drawBackground();
    drawClouds();
    //drawMics();
    drawCharacter();
    
    return frame;
}