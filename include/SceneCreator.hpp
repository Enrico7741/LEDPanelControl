//--------------------------------------------------------------------------------------------------
// LED-Panel-Control
// Copyright (C) 2020 Enrico Schörnick
// Licensed under the MIT License
//--------------------------------------------------------------------------------------------------

#ifndef SCENECREATOR_HPP
#define SCENECREATOR_HPP

#include "Drawer.hpp"
#include "Scene.hpp"
#include "Drawable.hpp"

#include <string>
#include <vector>

class SceneCreator
{
public:
    SceneCreator();
    Scene* scene;
    void createMarioKartScene();

private:
    Drawable readSprite(const std::string& path);
};

#endif
