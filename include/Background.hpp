//--------------------------------------------------------------------------------------------------
// LED-Panel-Control
// Copyright (C) 2020 Enrico Schörnick
// Licensed under the MIT License
//--------------------------------------------------------------------------------------------------

#ifndef BACKGROUND_HPP
#define BACKGROUND_HPP

#include "IDrawable.hpp"

class Background : public IDrawable
{
public:
    Background(Frame background);

    //explicit Background(std::shared_ptr<RenderManager> renderManager) : ISection(std::move(renderManager)){};

    // Background should be unique and local -- no copy/move operators
    Background(const Background &) = delete;
    Background &operator=(const Background &) = delete;
    Background(Background &&) noexcept = delete;
    Background &operator=(Background &&) noexcept = delete;

    void redraw(Frame &frame) override;
private:
    Frame background;
};

#endif