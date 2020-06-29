/****************************************
 * rainbow demo                        
 * wade ryan
 * May 2020
 *
 * Compile with gcc or g++:
 * $ g++ -lwiringPi -lNeoPixelRPi rainbow.cpp -o ../bin/rainbow
 *
 * Executed with:
 * $ sudo ../bin/rainbow
 *
 ****************************************/

#include <stdio.h>
#include <neopixel.h>  


// defaults for cmdline options
// * you may want to check out Jeremy's project for further clarification
//   on the target frequency options, as well as the strip options
//   https://github.com/jgarff/rpi_ws281x
//
#define STRIP_TYPE              WS2812_STRIP
#define TARGET_FREQ             WS2811_TARGET_FREQ
#define GPIO_PIN                18   // BCM numbering system
#define DMA                     10   // DMA=Direct Memory Access
int led_count =                144;  // number of pixels in your led strip
                                     // If you have a matrix, you should use
                                     // the universal display driver as it 
                                     // supports neopixel matrices and 
                                     // drawing lines, circles, text, and 
                                     // even bmp images
                                     // https://github.com/wryan67/udd_rpi_lib


int main(int argc, char* argv[]) {

    int ret=neopixel_init(STRIP_TYPE, WS2811_TARGET_FREQ, DMA, GPIO_PIN, led_count);

    if (ret!=0) {
        fprintf(stderr, "neopixel initialization failed: %s\n", neopixel_error(ret));
        return 9;
    }

    if (argc==3 && strcmp(argv[1],"-b")==0) {
      int brightness=10;
      sscanf(argv[2],"%d",&brightness);
      printf("brightness set to %d\n",brightness);
      neopixel_setBrightness(brightness);   // valid values are 0 to 255
    } else {
      printf("brightness set to 10\n");
      neopixel_setBrightness(10);   // valid values are 0 to 255
    }

    int count = -1;
    while (true) {  
        ++count;

        int color = count % 256;      // starting color is between 0 & 255 

        for (int i = 0; i < led_count; ++i) {
            // set pixel only changes the colors in memory
            neopixel_setPixel(i,neopixel_wheel((i + color) % 256));  
        }

        // render physically updates the neopixels
        neopixel_render();

        // frames/sec delay
        usleep(1000000 / 60);
    }

// not necessary
    neopixel_clear();     // turn off all pixels
    neopixel_render();

// graceful DMA cleanup; not necessary for most applications
    neopixel_close();

    return ret;
}
