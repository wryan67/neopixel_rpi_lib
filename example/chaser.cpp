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

int step=8;

// defaults for cmdline options
// * you may want to check out Jeremy's project for further clarification
//   on the target frequency options, as well as the strip options
//   https://github.com/jgarff/rpi_ws281x
//
#define STRIP_TYPE              WS2812_STRIP
#define TARGET_FREQ             WS2811_TARGET_FREQ
#define GPIO_PIN                18   // BCM numbering system
#define DMA                     10   // DMA=Direct Memory Access
int led_count =                144+(256/step);  // number of pixels in your led strip
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

    int Green=0xff;
    int Red=0xff;

    for (int i=0; i<144; ++i) {
//            neopixel_setPixel(i,neopixel_wheel(Green));  
             
            neopixel_setPixel(i,Green<<8);  
    }
    neopixel_render();

// printf("  %03d, #%06x  (%03d,%03d,%03d)\n"
//,i,wheelColor, wheelColor>>16, (wheelColor>>8)&0xff, wheelColor&0xff);

    while (true) {
        for (int i=0; i<144+(256/step); ++i) {

            int g=0x00;
            int r=0xff;
            int p=0;
            int j=0;

            printf("\n");

            p=i+(256/step);
            for (int j=0;j<(256/step);++j) {
                uint32_t c=(r<<16)+(g<<8);
                printf("before:  p=%d; g=%d; r=%d %08x\n", p,g,r,c);
                neopixel_setPixel(p,c);  
                g+=step;
                r-=step;
                --p;
            }
            printf("after:   p=%d; g=%d; r=%d\n", i+p,Green,0);
            neopixel_setPixel(((256/step)+i)-p,(Green<<8));  
            
            neopixel_render();
            usleep(25*1000);

        }
    }

// not necessary
    neopixel_clear();     // turn off all pixels
    neopixel_render();

// graceful DMA cleanup; not necessary for most applications
    neopixel_close();

    return ret;
}
