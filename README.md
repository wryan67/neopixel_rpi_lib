# NeoPixel Raspberry Pi Library

This library will allow you to control neopixels via hardware PWM on the Raspberry Pi.  It is based on [Jeremy Garff](https://github.com/jgarff/rpi_ws281x)'s driver, however, this libarary will install install itself as a dynamic library which will allow you to create many different projects without needing to copy the neopixel source files into every project you create.

Copyright (c) 2020 Wade Ryan


## Requirements
This library currently only supports pwm on RPi's header pin 12 (BCM-18).


## Install
To compile this library, navigate into the src folder and use the make utility to compile 
and install the library.

    $ cd [project folder]
    $ cd src
    $ make && sudo make install


## Compiling
Complie your applications using these command line arguments: -lNeoPixelRPi


## Example
To run the example program, nagaviate into the example folder and use make to compile the program.  The timestamp 

    $ sudo bin/demo
    $ $ accessing ads1115 chip on i2c address 48
    $ Timestamp       Delta       A0       A1       A2       A3
    $ 1575219689268      44     1.73     3.91     0.00     0.00