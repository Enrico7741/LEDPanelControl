//--------------------------------------------------------------------------------------------------
// LED-Panel-Control
// Copyright (C) 2020 Enrico Schörnick
// Licensed under the MIT License
//--------------------------------------------------------------------------------------------------

#include "CharacterManager.hpp"

void CharacterManager::redraw()
{
    drawer->draw(mario, posX, posY);
}
