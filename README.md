# NeoPixel Raspberry Pi Library

This library will allow you to control NeoPixels via hardware PWM on the Raspberry Pi.  It is based on [Jeremy Garff](https://github.com/jgarff/rpi_ws281x)'s driver, however, this libarary will install install itself as a dynamic library which will allow you to create many different projects without needing to copy the neopixel source files into every project you create.

Note:  If you're looking for a driver for a NeoPixel matrix (8x8 grid or various other sizes), you might consider checking out the [universal display driver](https://github.com/wryan67/udd_rpi_lib), which supports NeoPixel matrices, and can draw lines, circles, text, and can also display bmp images.

Copyright (c) 2020 Wade Ryan


## Requirements
This library currently only supports pwm on RPi's header pin 12 (BCM-18).


## Download

$ git clone https://github.com/wryan67/neopixel_rpi_lib.git


## Install
To compile this library, navigate into the src folder and use the make utility to compile 
and install the library.

    $ cd neopixel_rpi_lib
    $ cd src
    $ make install


## Compiling
Complie your applications using these command line arguments: -lNeoPixelRPi


## Example
To run the example program, nagaviate into the example folder and use make to compile the program.  The timestamp 

    $ sudo bin/rainbow


## Supports
 
* ws2811
* ws2812
* ws2812b
