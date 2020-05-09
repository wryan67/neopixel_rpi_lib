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
    ws2811_return_t ret;


    if (neopixel_init(WS2812_STRIP, WS2811_TARGET_FREQ, DMA, GPIO_PIN, led_count)!=0) {
        fprintf(stderr, "ws2811_init failed: %s\n", neopixel_error(ret));
        return 9;
    }
    

    neopixel_clear();
    neopixel_render();
    neopixel_close();

    printf("\n");
    return ret;
}
