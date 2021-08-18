//--------------------------------------------------------------------------------------------------
// LED-Panel-Control
// Copyright (C) 2020 Enrico Schörnick
// Licensed under the MIT License
//--------------------------------------------------------------------------------------------------

#ifndef PANEL_HPP
#define PANEL_HPP

#include "Animation.hpp"
#include "SafeQueue.hpp"
#include "ImageManager.hpp"
#include "led-matrix.h"

#include "string"

class Panel
{
public:
  Panel(SafeQueue<std::string>& msgQueue) : messageQueue(msgQueue) {};
  ~Panel();
  bool initialize();
  void run(ImageManager& imageManager);
  rgb_matrix::FrameCanvas *frame;

private:
  rgb_matrix::RGBMatrix *matrix;
  const int cols{64};
  const int rows{64};
  const int brightness{100};
  SafeQueue<std::string>& messageQueue;
  void displayFrame(Frame& animationFrame);
};

#endif
