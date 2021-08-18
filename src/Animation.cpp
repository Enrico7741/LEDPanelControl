//--------------------------------------------------------------------------------------------------
// LED-Panel-Control
// Copyright (C) 2020 Enrico Schörnick
// Licensed under the MIT License
//--------------------------------------------------------------------------------------------------

#include "Animation.hpp"

#include <iostream>

Animation::Animation(const std::string& image)
{
    std::vector<Magick::Image> frames;
    readImages(&frames, image.c_str());
    std::vector<Magick::Image> imageSequence;
    Magick::coalesceImages(&imageSequence, frames.begin(), frames.end());

    for (size_t i = 0; i < imageSequence.size(); ++i)
    {
        const Magick::Image &img = imageSequence[i];
        const int xOffset = (64 - img.columns()) / 2;
        const int yOffset = img.rows() == 32 ? 0 : (64 - img.rows()) / 2;

        Frame frame;
        for (size_t y = 0; y < img.rows(); ++y)
        {
            for (size_t x = 0; x < img.columns(); ++x)
            {
                const Magick::Color &c = img.pixelColor(x, y);
                if (c.alphaQuantum() < 256)
                {
                    Pixel p{ScaleQuantumToChar(c.redQuantum()), ScaleQuantumToChar(c.greenQuantum()), 
                    ScaleQuantumToChar(c.blueQuantum())};      
                    frame.pixel[xOffset + x][yOffset + y] = p;
                }
            }
        }
                    animation.push_back(frame);
    }
}

Frame& Animation::getNextFrame()
{
    static int index = 0;
    if (index < animation.size() - 1)
    {
        index++;
    }
    else
    {
        index = 0;
    }

    return animation[index];
}