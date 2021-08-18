//--------------------------------------------------------------------------------------------------
// LED-Panel-Control
// Copyright (C) 2020 Enrico Schörnick
// Licensed under the MIT License
//--------------------------------------------------------------------------------------------------

#ifndef IMAGEMANAGER_HPP
#define IMAGEMANAGER_HPP

#include "Animation.hpp"

#include <vector>
#include <string>

class ImageManager
{
private:
    void readDirectory(const std::string& dir, std::vector<Animation>& animations);
    int index = 0;

public:
    bool initialize();
    Animation& getImage();
    Animation& getPrevImage();
    std::string imageDir{"/home/pi/Documents/LEDPanelControl/bin/images/"};
    std::vector<Animation> images;
};

#endif