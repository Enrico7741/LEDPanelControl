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

class Animation
{
public:
  Animation(const std::string& path, rgb_matrix::FrameCanvas *frame);
  int animationDurationMs{5000};
  int animationDelayMs{45};
  rgb_matrix::StreamIO *contentStream;
private:
    bool LoadAnimation(const std::string& image, std::vector<Magick::Image>& imageSequence);
    void StoreInStream(const Magick::Image &img, int delay_time_us,
                          bool do_center,
                          rgb_matrix::FrameCanvas *scratch,
                          rgb_matrix::StreamWriter *output);
};

#endif