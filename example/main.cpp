#include <stdio.h>
#include <stdarg.h>
#include <getopt.h>

#include <neopixel.h>


// defaults for cmdline options
#define TARGET_FREQ             WS2811_TARGET_FREQ
#define GPIO_PIN                18
#define DMA                     10
int led_count =                144;







int main(int argc, char* argv[]) {
    int ret;


    if (neopixel_init(WS2812_STRIP, WS2811_TARGET_FREQ, DMA, GPIO_PIN, led_count)!=0) {
        fprintf(stderr, "ws2811_init failed: %s\n", neopixel_error(ret));
        return 9;
    }

    neopixel_setBrighness(8);

    int count = -1;
    while (true) {
        ++count;

        int clr = count % 256;
        int pixelColor =  neopixel_wheel(clr);

//        printf("clr=%3d  0x%06x\r", clr, pixelColor);  fflush(stdout);

        for (int i = 0; i < led_count; ++i) {
            neopixel_setPixel(i,neopixel_wheel((i + count) % 256));
          
        }



        neopixel_render();
        // frames/sec
        usleep(1000000 / 60);

    }

    neopixel_clear();
    neopixel_render();
    neopixel_close();

    printf("\n");
    return ret;
}
