//--------------------------------------------------------------------------------------------------
// LED-Panel-Control
// Copyright (C) 2020 Enrico Schörnick
// Licensed under the MIT License
//--------------------------------------------------------------------------------------------------

#ifndef ANIMATION_HPP
#define ANIMATION_HPP

#include "led-matrix.h"
#include "content-streamer.h"
#include <Magick++.h>
#include <magick/image.h>
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

class Animation
{
public:
  Animation(const std::string& path);
  int animationDurationMs{5000};
  int animationDelayMs{45};
  std::vector<Frame> animation;
  Frame& getNextFrame();
private:
};

#endif