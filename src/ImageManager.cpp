#include "ImageManager.hpp"

#include <experimental/filesystem>
#include <iostream>
#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <cstring>

bool ImageManager::initialize(rgb_matrix::FrameCanvas *frame)
{
    readDirectory(pokemonDir, pokemons, frame);
    readDirectory(otherDir, other, frame);
    return true;
}

void ImageManager::readDirectory(const std::string& dir, std::vector<Animation>& animations, rgb_matrix::FrameCanvas *frame)
{
    DIR* dirp = opendir(dir.c_str());
    struct dirent * dp;
    while ((dp = readdir(dirp)) != NULL)
    {
        if(dp->d_name[0] != '.')
        {
            animations.push_back(Animation(dir + dp->d_name, frame));
        }
    }
    closedir(dirp);
}

Animation& ImageManager::getImage()
{
    static int i = 0;
    if (i < pokemons.size())
    {
        return pokemons[i++];
    }
    else
    {
        i = 0;
        return pokemons[i++];
    }

}
