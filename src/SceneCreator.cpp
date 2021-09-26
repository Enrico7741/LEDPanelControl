//--------------------------------------------------------------------------------------------------
// LED-Panel-Control
// Copyright (C) 2020 Enrico Schörnick
// Licensed under the MIT License
//--------------------------------------------------------------------------------------------------

#include "SceneCreator.hpp"

#include "Plant.hpp"
#include "Tunnel.hpp"

#include <Magick++.h>
#include <magick/image.h>

#include <iostream>

SceneCreator::SceneCreator()
{
    Magick::InitializeMagick(NULL);
}

void SceneCreator::createMarioKartScene()
{
    auto drawer = new Drawer();

    auto background = readSprite("/home/pi/Documents/LEDPanelControl/bin/sprites/backgrounds/background.png");
    auto clouds = readSprite("/home/pi/Documents/LEDPanelControl/bin/sprites/clouds/clouds.png");

    auto mario = readSprite("/home/pi/Documents/LEDPanelControl/bin/sprites/drivers/mario.png");
    auto luigi = readSprite("/home/pi/Documents/LEDPanelControl/bin/sprites/drivers/luigi.png");
    auto peach = readSprite("/home/pi/Documents/LEDPanelControl/bin/sprites/drivers/peach.png");
    auto bowser = readSprite("/home/pi/Documents/LEDPanelControl/bin/sprites/drivers/bowser.png");
    auto yoshi = readSprite("/home/pi/Documents/LEDPanelControl/bin/sprites/drivers/yoshi.png");
    auto toad = readSprite("/home/pi/Documents/LEDPanelControl/bin/sprites/drivers/toad.png");
    auto koopa = readSprite("/home/pi/Documents/LEDPanelControl/bin/sprites/drivers/koopa.png");
    auto donkey = readSprite("/home/pi/Documents/LEDPanelControl/bin/sprites/drivers/donkey.png");

    auto bigPlant = Plant(readSprite("/home/pi/Documents/LEDPanelControl/bin/sprites/misc/plantBigOpen.png"),
                        readSprite("/home/pi/Documents/LEDPanelControl/bin/sprites/misc/plantBigClosed.png"));

    auto tunnel = Tunnel(readSprite("/home/pi/Documents/LEDPanelControl/bin/sprites/misc/tunnel.png"));

    auto smallPlant = Plant(readSprite("/home/pi/Documents/LEDPanelControl/bin/sprites/misc/plantSmallOpen.png"), 
                            readSprite("/home/pi/Documents/LEDPanelControl/bin/sprites/misc/plantSmallClosed.png"));

    this->scene = new Scene(drawer, 
                            new BackgroundManager(drawer, background), 
                            new CloudManager(drawer, clouds), 
                            new CharacterManager(drawer, mario), 
                            new BottomMiscManager(drawer, bigPlant), 
                            new TopMiscManager(drawer, tunnel, smallPlant));
}

Drawable SceneCreator::readSprite(const std::string& path)
{
    std::vector<std::vector<Pixel>> pixels;
    Magick::Image image(path);
    for (size_t x = 0; x < image.baseColumns(); x++)
    {
        std::vector<Pixel> pixelColumn;
        for (size_t y = 0; y < image.baseRows(); y++)
        {
            const Magick::Color &c = image.pixelColor(x, y);
            if (c.alphaQuantum() < 256)
            {
                Pixel p{ScaleQuantumToChar(c.redQuantum()), ScaleQuantumToChar(c.greenQuantum()), 
                ScaleQuantumToChar(c.blueQuantum())};
                pixelColumn.push_back(p);
            }
        }
        pixels.push_back(pixelColumn);
    }

    return Drawable(pixels);
}