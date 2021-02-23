//--------------------------------------------------------------------------------------------------
// LED-Panel-Control
// Copyright (C) 2020 Enrico Schörnick
// Licensed under the MIT License
//--------------------------------------------------------------------------------------------------

#include "Animation.hpp"

Animation::Animation(const std::string& image, rgb_matrix::FrameCanvas *frame)
{
    std::vector<Magick::Image> imageSequence;
    LoadAnimation(image, imageSequence);
    contentStream = new rgb_matrix::MemStreamIO();
    rgb_matrix::StreamWriter out(contentStream);
    for (size_t i = 0; i < imageSequence.size(); ++i)
    {
        const Magick::Image &img = imageSequence[i];
        int64_t delay_time_us;

        delay_time_us = img.animationDelay() * 10000; // unit in 1/100s

        if (delay_time_us <= 0)
            delay_time_us = 100 * 1000; // 1/10sec
        StoreInStream(img, delay_time_us, false, frame, &out);
    }
}

bool Animation::LoadAnimation(const std::string& image, std::vector<Magick::Image>& imageSequence)
{
    std::vector<Magick::Image> frames;
    readImages(&frames, image.c_str());

    // Put together the animation from single frames. GIFs can have nasty
    // disposal modes, but they are handled nicely by coalesceImages()
    if (frames.size() > 1)
    {
        Magick::coalesceImages(&imageSequence, frames.begin(), frames.end());
    }
    else
    {
        imageSequence.push_back(frames[0]); // just a single still image.
    }

    return true;
}

void Animation::StoreInStream(const Magick::Image &img, int delay_time_us,
                          bool do_center,
                          rgb_matrix::FrameCanvas *scratch,
                          rgb_matrix::StreamWriter *output)
{
    scratch->Clear();
    const int x_offset = do_center ? (scratch->width() - img.columns()) / 2 : 0;
    const int y_offset = do_center ? (scratch->height() - img.rows()) / 2 : 0;
    for (size_t y = 0; y < img.rows(); ++y)
    {
        for (size_t x = 0; x < img.columns(); ++x)
        {
            const Magick::Color &c = img.pixelColor(x, y);
            if (c.alphaQuantum() < 256)
            {
                scratch->SetPixel(x + x_offset, y + y_offset,
                                  ScaleQuantumToChar(c.redQuantum()),
                                  ScaleQuantumToChar(c.greenQuantum()),
                                  ScaleQuantumToChar(c.blueQuantum()));
            }
        }
    }
    output->Stream(*scratch, delay_time_us);
}