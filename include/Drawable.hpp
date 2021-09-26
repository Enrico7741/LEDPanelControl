//--------------------------------------------------------------------------------------------------
// LED-Panel-Control
// Copyright (C) 2020 Enrico Schörnick
// Licensed under the MIT License
//--------------------------------------------------------------------------------------------------

#ifndef DRAWABLE_HPP
#define DRAWABLE_HPP

#include <vector>
#include <stdint.h>
#include <array>

struct Pixel
{
    uint8_t R{};
    uint8_t G{};
    uint8_t B{};
};

struct Frame
{
    std::array<std::array<Pixel, 64>, 64> pixel{};
};

class Drawable
{
public:
    Drawable(std::vector<std::vector<Pixel>> pixel) : pixel{pixel} {};
    const std::vector<std::vector<Pixel>>& getPixels() const { return pixel; }
    int width() const { return pixel.size(); }
    int height() const { return pixel[0].size(); }

private:
    std::vector<std::vector<Pixel>> pixel;
};

#endif