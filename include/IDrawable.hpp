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

class IDrawable
{
public:
    virtual ~IDrawable() = default;
    virtual void redraw(Frame &frame) = 0;

protected:
    //explicit IDrawable(std::shared_ptr<RenderManager> renderManager) : renderManager{std::move(renderManager)}{};
    IDrawable() = default;
    IDrawable(const IDrawable &) = default;
    IDrawable &operator=(const IDrawable &) = default;
    IDrawable(IDrawable &&) noexcept = default;
    IDrawable &operator=(IDrawable &&) noexcept = default;
};

#endif