//--------------------------------------------------------------------------------------------------
// LED-Panel-Control
// Copyright (C) 2020 Enrico Schörnick
// Licensed under the MIT License
//--------------------------------------------------------------------------------------------------

#ifndef IMAGEMANAGER_HPP
#define IMAGEMANAGER_HPP

#include <vector>
#include <string>

#include "Animation.hpp"

class ImageManager
{
private:
    void readDirectory(const std::string& dir, std::vector<Animation>& animations, rgb_matrix::FrameCanvas *frame);
public:
    bool initialize(rgb_matrix::FrameCanvas *frame);
    Animation& getImage();
    std::string pokemonDir{"/home/pi/Documents/LEDPanelControl/bin/pokemon/"};
    std::vector<Animation> pokemons;
    std::string otherDir{"/home/pi/Documents/LEDPanelControl/bin/other/"};
    std::vector<Animation> other;
};

#endif