// C64 Matrix
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include "c64.h"

void initScreen() {
    int i;
    char *screen = (char *)BASE_SCREEN_ADDRESS;
    CLRSCR;
    SET_COLORS(C64_COLOR_BLACK,C64_COLOR_BLACK,C64_COLOR_GREEN);
    GRAPHICS_OFF;
    memset((char *)BASE_COLOR_ADDRESS, C64_COLOR_GREEN, 1000);
    for(i = 0; i < 40; i++) {
        memset(screen+i, (rand() % 50) + 32, 1);
    }
}

bool pollInput() {
    unsigned char key, joy1, joy2;

    key = GET_PKEY_VIEW;
    joy1 = GET_JOY1;
    joy2 = GET_JOY2;


    if((joy1 & C64_JOYSTICK_BUTTON) == 0) {
        return false;
    }
    if((joy2 & C64_JOYSTICK_BUTTON) == 0) {
        return false;
    }

    switch(key) {
    case PKEY_NOKEY: break;
    case PKEY_Q: return false; break;
    default: break;
    }

    CLRKEY;
    return true;
}

int main(void) {
    bool isRunning = true, drawAltScr = false;
    int i = 0;
    char *target, *source;
    char newchar;

    _randomize();
    initScreen();

    // Main Loop
    while(isRunning) {
        // Copy source to dest, but one row lower
        source = (char *)BASE_SCREEN_ADDRESS;
        target = (char *)BASE_SCREEN_ADDRESS;
        for(i=24; i>=0; i--) {
            memcpy(target+((i+1)*40), source+(i*40), 40);
        }
        // New first row
        for(i = 0; i < 40; i++) {
            newchar = (rand() % 3) == 0 ? 32 : (rand() % 50) + 32;
            memset(target+i, newchar, 1);
        }
        isRunning = pollInput();
    }

    GRAPHICS_ON;
    CLRSCR;
    return 0;
}
