//--------------------------------------------------------------------------------------------------
// LED-Panel-Control
// Copyright (C) 2020 Enrico Schörnick
// Licensed under the MIT License
//--------------------------------------------------------------------------------------------------

#ifndef PANEL_HPP
#define PANEL_HPP

#include "Animation.hpp"
#include "SafeQueue.hpp"
#include "led-matrix.h"

#include "string"

class Panel
{
public:
  Panel(SafeQueue<std::string>& msgQueue) : messageQueue(msgQueue) {};
  ~Panel();
  bool initialize();
  void run(std::vector<Animation>& animations);
  rgb_matrix::FrameCanvas *frame;

private:
  void display(const Animation& animation);
  rgb_matrix::RGBMatrix *matrix;
  const int cols{64};
  const int rows{32};
  const int brightness{100};
  SafeQueue<std::string>& messageQueue;
};

#endif
