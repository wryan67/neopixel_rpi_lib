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

#include <vector>

using namespace std;

// defaults for cmdline options
// * you may want to check out Jeremy's project for further clarification
//   on the target frequency options, as well as the strip options
//   https://github.com/jgarff/rpi_ws281x
//
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

//    int ledType = WS2811_TARGET_FREQ;
    int ledType = WS2811_STRIP_GRB;

    int ret=neopixel_init(ledType, WS2811_TARGET_FREQ, DMA, GPIO_PIN, led_count*2);

    if (ret!=0) {
        fprintf(stderr, "neopixel initialization failed: %s\n", neopixel_error(ret));
        return 9;
    }

    if (argc==3 && strcmp(argv[1],"-b")==0) {
      int brightness=24;
      sscanf(argv[2],"%d",&brightness);
      printf("brightness set to %d\n",brightness);
      neopixel_setBrightness(brightness);   // valid values are 0 to 255
    } else {
      printf("brightness set to 10\n");
      neopixel_setBrightness(10);   // valid values are 0 to 255
    }



// printf("  %03d, #%06x  (%03d,%03d,%03d)\n"
//,i,wheelColor, wheelColor>>16, (wheelColor>>8)&0xff, wheelColor&0xff);


    vector<uint32_t> shades;

//                     RRGGBB
    shades.push_back(0x004000);
    shades.push_back(0x004000);
    shades.push_back(0x001000);
    shades.push_back(0x100000);
    shades.push_back(0x450000);
    shades.push_back(0xFF0000);

    int steps=shades.size();

    while (true) {
        for (int i=0; i<steps*2+3; ++i) {
            // printf("\nsteps=%d\n",steps);
            int k=16;
            for (int n=0;n<(led_count+32)/k;++n)
            for (int j=0;j<steps;++j) {
                int p=i+j+(n*k);
                // int g=(shades[j] & 0x00ff00 )>>8;
                // int r=(shades[j] & 0xff0000 )>>16;
                // printf("before:  p=%03d; g=%03d; r=%03d %08lx\n", p,g,r,shades[j]);
                neopixel_setPixel(p, shades[j]);  
            }
            neopixel_render();
            usleep(20*1000);
        }
    }
    int r=0;
    for (int i=0;i<255;++i) {
        r+=(256/steps);
        if (r==256) r=255;
        if (r>256) r=0;
        uint32_t c=(r<<16);
        neopixel_setPixel(i,c);  
    }
    neopixel_render();
    return 0;

// not necessary
    neopixel_clear();     // turn off all pixels
    neopixel_render();

// graceful DMA cleanup; not necessary for most applications
    neopixel_close();

    return ret;
}
