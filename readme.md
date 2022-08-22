# NeoPixel Raspberry Pi Library

This library will allow you to control NeoPixels via hardware PWM on the Raspberry Pi.  It is based on [Jeremy Garff](https://github.com/jgarff/rpi_ws281x)'s driver, however, this libarary will install install itself as a dynamic library which will allow you to create many different projects without needing to copy the neopixel source files into every project you create.

Note:  If you're looking for a driver for a NeoPixel matrix (8x8 grid or various other sizes), you might consider checking out the [universal display driver](https://github.com/wryan67/udd_rpi_lib), which supports NeoPixel matrices, and can draw lines, circles, text, and can also display bmp images.

The Raspberry Pi is not a good source of power for NeoPixels becuase they draw a lot of power.  See the docutmentaion for your NeoPixels to see what type of power supply you will need to power them.   Also, you will need to use a logic level converter to go from the GPIO pin to the NeoPixel data pin.  Below is a suggested circuit diagram.  As is typical, I am not responsible for any damage done to your equipment by this circuit diagram or code library.  

Copyright (c) 2020 Wade Ryan


## Requirements
This library currently only supports pwm on RPi's header pin 12 (BCM-18).


## Download

$ git clone https://github.com/wryan67/neopixel_rpi_lib.git


## Install
To compile this library, navigate into the src folder and use the make utility to compile 
and install the library.

    $ cd neopixel_rpi_lib
    $ make install


## Compiling
Complie your applications using these command line arguments: -lNeoPixelRPi

## Example
The install should have also compiled the demo programs to the bin folder.  Check the example folder for the source code examples to use in your programs.  Since the library used DMA, the programs need to be run via sudo:

    $ sudo bin/rainbow


## Supports
 
* ws2811
* ws2812
* ws2812b


## Color Wheel

The user may create their own colors or use the color chart below to choose colors from.  The method neopixel_wheel(int color), where color is a number betweeen 0 and 255, will return a valid RGB color which matches the chart below. 

![thumbnail](https://raw.githubusercontent.com/wryan67/neopixel_rpi_lib/master/readme/ColorWheel.png)

Here are the numbers which represent the associated "pure" colors:


| Color   | Num |HTML   |RGB          |
| ------- | --- |-------|-------------|
| Green   |   0 |#00ff00|(000,255,000)|
| Yellow  |  42 |#7e8100|(126,129,000)|
| Red     |  85 |#ff0000|(255,000,000)|
| Magenta | 128 |#7e0081|(126,000,129)|
| Blue    | 170 |#0000ff|(000,000,255)|
| Cyan    | 212 |#007e81|(000,126,129)|

## Circuit diagram

Again be sure to use a seperate power source for your NeoPixels as the RPi is not strong enough to drive them.

![thumbnail](https://raw.githubusercontent.com/wryan67/neopixel_rpi_lib/master/readme/circuit%20diagram%20ws2812.png)
