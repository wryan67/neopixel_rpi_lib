
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <signal.h>
#include <stdarg.h>
#include <getopt.h>


#include "clk.h"
#include "gpio.h"
#include "dma.h"
#include "pwm.h"
#include "version.h"

#include "ws2811.h"

#ifndef __neopixel_h__
#define __neopixel_h__


#ifdef __cplusplus
extern "C" {
#endif

int neopixel_init(int stripType, int targetFreq, int dmaChannel, int gpioPin, int ledCount);

int neopixel_clear(void);
int neopixel_render(void);
int neopixel_wheel(unsigned char color);                  
void neopixel_setBrighness(int);
void neopixel_setPixel(int pixel,int color);
void neopixel_close();

const char *neopixel_error(int ret);

#ifdef __cplusplus
}
#endif

#endif /* __WS2811_H__ */
