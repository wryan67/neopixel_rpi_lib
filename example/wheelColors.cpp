#include <stdio.h>
#include <neopixel.h>  

// gcc -lNeoPixelRPi wheelColors.cpp  -o wheelColors


int main(int argc, char* argv[]) {

//  233, #00bd42 (000,189,066)
    printf("Wheel  HashTag    RGB Color\n");
    printf("Color    Color  (Red,Grn,Blu)\n");
    printf("-----  -------  -------------\n");


    for (int i=0;i<256;++i) {
        int wheelColor=neopixel_wheel(i);
        printf("  %03d, #%06x  (%03d,%03d,%03d)\n",i,wheelColor, wheelColor>>16, (wheelColor>>8)&0xff, wheelColor&0xff);
    }

    return 0;
}
