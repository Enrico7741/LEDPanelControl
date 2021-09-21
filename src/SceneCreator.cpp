//--------------------------------------------------------------------------------------------------
// LED-Panel-Control
// Copyright (C) 2020 Enrico Schörnick
// Licensed under the MIT License
//--------------------------------------------------------------------------------------------------

#include "SceneCreator.hpp"

#include <Magick++.h>
#include <magick/image.h>

void SceneCreator::createMarioKartScene()
{
    Magick::InitializeMagick(NULL);

    Frame background;
    Magick::Image bg("/home/pi/Documents/LEDPanelControl/bin/sprites/backgrounds/background.png");
    for (size_t y = 0; y < 64; ++y)
    {
        for (size_t x = 0; x < 64; ++x)
        {
            const Magick::Color &c = bg.pixelColor(x, y);
            if (c.alphaQuantum() < 256)
            {
                Pixel p{ScaleQuantumToChar(c.redQuantum()), ScaleQuantumToChar(c.greenQuantum()), 
                ScaleQuantumToChar(c.blueQuantum())};      
                background.pixel[x][y] = p;
            }
        }
    }

    Frame clouds;
    Magick::Image cloud("/home/pi/Documents/LEDPanelControl/bin/sprites/clouds/clouds.png");
    for (size_t y = 0; y < 64; ++y)
    {
        for (size_t x = 0; x < 64; ++x)
        {
            const Magick::Color &c = cloud.pixelColor(x, y);
            if (c.alphaQuantum() < 256)
            {
                Pixel p{ScaleQuantumToChar(c.redQuantum()), ScaleQuantumToChar(c.greenQuantum()), 
                ScaleQuantumToChar(c.blueQuantum())};      
                clouds.pixel[x][y] = p;
            }
        }
    }

    CharacterFrame marioFrame;
    Magick::Image mario("/home/pi/Documents/LEDPanelControl/bin/sprites/drivers/mario.png");
    for (size_t y = 0; y < 30; ++y)
    {
        for (size_t x = 0; x < 28; ++x)
        {
            const Magick::Color &c = mario.pixelColor(x, y);
            if (c.alphaQuantum() < 256)
            {
                Pixel p{ScaleQuantumToChar(c.redQuantum()), ScaleQuantumToChar(c.greenQuantum()), 
                ScaleQuantumToChar(c.blueQuantum())};    
                marioFrame.pixel[x][y] = p;
            }
        }
    }

    PlantBig plantBigOpen;
    Magick::Image pbOpen("/home/pi/Documents/LEDPanelControl/bin/sprites/misc/plantBigOpen.png");
    for (size_t y = 0; y < 12; ++y)
    {
        for (size_t x = 0; x < 11; ++x)
        {
            const Magick::Color &c = pbOpen.pixelColor(x, y);
            if (c.alphaQuantum() < 256)
            {
                Pixel p{ScaleQuantumToChar(c.redQuantum()), ScaleQuantumToChar(c.greenQuantum()), 
                ScaleQuantumToChar(c.blueQuantum())};    
                plantBigOpen.pixel[x][y] = p;
            }
        }
    }

    PlantBig plantBigClosed;
    Magick::Image pbClosed("/home/pi/Documents/LEDPanelControl/bin/sprites/misc/plantBigClosed.png");
    for (size_t y = 0; y < 12; ++y)
    {
        for (size_t x = 0; x < 11; ++x)
        {
            const Magick::Color &c = pbClosed.pixelColor(x, y);
            if (c.alphaQuantum() < 256)
            {
                Pixel p{ScaleQuantumToChar(c.redQuantum()), ScaleQuantumToChar(c.greenQuantum()), 
                ScaleQuantumToChar(c.blueQuantum())};    
                plantBigClosed.pixel[x][y] = p;
            }
        }
    }

    Tunnel tunnel;
    Magick::Image tunnelImage("/home/pi/Documents/LEDPanelControl/bin/sprites/misc/tunnel.png");
    for (size_t y = 0; y < 18; ++y)
    {
        for (size_t x = 0; x < 14; ++x)
        {
            const Magick::Color &c = tunnelImage.pixelColor(x, y);
            if (c.alphaQuantum() < 256)
            {
                Pixel p{ScaleQuantumToChar(c.redQuantum()), ScaleQuantumToChar(c.greenQuantum()), 
                ScaleQuantumToChar(c.blueQuantum())};    
                tunnel.pixel[x][y] = p;
            }
        }
    }

    this->scene = new Scene(new Background(background), new Clouds(clouds), new Mario(marioFrame), new BottomMisc(plantBigOpen, plantBigClosed), new TopMisc(tunnel));
}