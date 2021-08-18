//--------------------------------------------------------------------------------------------------
// LED-Panel-Control
// Copyright (C) 2020 Enrico Schörnick
// Licensed under the MIT License
//--------------------------------------------------------------------------------------------------

#include "ImageManager.hpp"

#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <cstring>
#include <iostream>
#include <experimental/filesystem>

bool ImageManager::initialize()
{
    readDirectory(imageDir, images);
    return true;
}

void ImageManager::readDirectory(const std::string& dir, std::vector<Animation>& animations)
{
    DIR* dirp = opendir(dir.c_str());
    struct dirent * dp;
    while ((dp = readdir(dirp)) != NULL)
    {
        if(dp->d_name[0] != '.')
        {
            animations.push_back(Animation(dir + dp->d_name));
        }
    }
    closedir(dirp);
}

Animation& ImageManager::getImage()
{
    if (index < images.size() - 1)
    {
        index++;
    }
    else
    {
        index = 0;
    }

    return images[index];
}

Animation& ImageManager::getPrevImage()
{
    if (index > 0)
    {
        index--;
    }
    else
    {
        index = images.size() - 1;
    }

    return images[index];
}