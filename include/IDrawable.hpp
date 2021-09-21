//--------------------------------------------------------------------------------------------------
// LED-Panel-Control
// Copyright (C) 2020 Enrico Schörnick
// Licensed under the MIT License
//--------------------------------------------------------------------------------------------------

#ifndef IDRAWABLE_HPP
#define IDRAWABLE_HPP

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

struct CharacterFrame
{
  std::array<std::array<Pixel, 30>, 28> pixel{};
};

struct PlantBig
{
  std::array<std::array<Pixel, 12>, 11> pixel{};
};

struct Tunnel
{
  std::array<std::array<Pixel, 18>, 14> pixel{};
};

#endif