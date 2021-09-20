//--------------------------------------------------------------------------------------------------
// LED-Panel-Control
// Copyright (C) 2020 Enrico Schörnick
// Licensed under the MIT License
//--------------------------------------------------------------------------------------------------

#ifndef CLOUDS_HPP
#define CLOUDS_HPP

#include "IDrawable.hpp"

class Clouds : public IDrawable
{
public:
    Clouds(Frame clouds);

    //explicit Clouds(std::shared_ptr<RenderManager> renderManager) : ISection(std::move(renderManager)){};

    // Clouds should be unique and local -- no copy/move operators
    Clouds(const Clouds &) = delete;
    Clouds &operator=(const Clouds &) = delete;
    Clouds(Clouds &&) noexcept = delete;
    Clouds &operator=(Clouds &&) noexcept = delete;

    void redraw(Frame &frame) override;
private:
    Frame clouds;
};

#endif