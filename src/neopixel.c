
#include "neopixel.h"


ws2811_led_t* matrix;

ws2811_t ledstring =
{
    .channel =
    {
        [0] =
        {
            .invert = 0,
            .brightness = 32  ,
        },
        [1] =
        {
            .gpionum = 0,
            .count = 0,
            .invert = 0,
            .brightness = 0,
        },
    },
};


int neopixel_init(int stripType, int targetFreq, int dmaChannel, int gpioPin, int ledCount) { 
    matrix = malloc(sizeof(ws2811_led_t) * ledCount);

    ledstring.dmanum=dmaChannel;
    ledstring.freq=targetFreq;

    ledstring.channel[0].gpionum = gpioPin;
    ledstring.channel[0].count = ledCount;
    ledstring.channel[0].strip_type = stripType;

    return ws2811_init(&ledstring, PWM);

}

const char *neopixel_error(int ret) {
    return ws2811_get_return_t_str(ret);
}
    


void neopixel_setBrighness(int brightness) {
    ledstring.channel[0].brightness=brightness;
}

void neopixel_invert(int flag) {
    ledstring.channel[0].invert=flag;
}


int neopixel_render(void) {
    int ret;

    for (int i = 0; i < ledstring.channel[0].count; i++) {
        ledstring.channel[0].leds[i] = matrix[i];
    }

    if ((ret = ws2811_render(&ledstring)) != WS2811_SUCCESS) {
        fprintf(stderr, "neopixel render failed: %s\n", ws2811_get_return_t_str(ret));
    }
    return ret;
}

int neopixel_clear(void) {
    int ret;
    for (int i = 0; i < ledstring.channel[0].count; i++) {
        ledstring.channel[0].leds[i] = 0;
    }
    if ((ret = ws2811_render(&ledstring)) != WS2811_SUCCESS) {
        fprintf(stderr, "neopixel render failed: %s\n", ws2811_get_return_t_str(ret));
    }
    return ret;
}

int neopixel_wheel(unsigned char color) {

        if (color<0 || color>255) {
                return 0;
        }

        int r,g,b;
        r=g=b=0;

        if (color<85) {
                r=color*3;
                g=255-color*3;
                b=0;
        } else if (color<170) {
                color-= 85;
                r = 255 - color * 3;
                g = 0;
                b = color * 3;
        } else {
                color -= 170;
                r = 0;
                g = color * 3;
                b = 255 - color * 3;
        }

        int clr=(r<<16)+(g<<8)+b;
        return clr;
}

void neopixel_close() {
    ws2811_fini(&ledstring);
}

void neopixel_setPixel(int pixel,int color) {
    matrix[pixel]=color;
}