//--------------------------------------------------------------------------------------------------
// LED-Panel-Control
// Copyright (C) 2020 Enrico Schörnick
// Licensed under the MIT License
//--------------------------------------------------------------------------------------------------

#ifndef PANEL_HPP
#define PANEL_HPP

#include "led-matrix.h"

using namespace rgb_matrix;

class Panel
{
public:
    ~Panel();
    bool initialize();
private:
    RGBMatrix *matrix;
    FrameCanvas *frame;
    const int cols{64};
    const int rows{32};
    int brightness{80};
};

#endif