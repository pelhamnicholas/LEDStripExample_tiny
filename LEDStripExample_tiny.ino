#include "ledstrip.h"

Color red(0);
Color green(1);
Color blue(4);

Potentiometer pot(A1);

int color = 0;
bool colorChange = true;
int potVal;

void setup() {
        red.init(OUTPUT);
        green.init(OUTPUT);
        blue.init(OUTPUT);
        pot.init(INPUT);
        Color::assignDelayPot(pot, 1);
        initPWM();
}

void loop() {
        potVal = pot.update();
        if (potVal < 128) {
                fadeColors();
        } else if (potVal < 256) {
                green = blue = 0;
                red = map(potVal, 128, 255, 0, 255);
        } else if (potVal < 384) {
                red = blue = 0;
                green = map(potVal, 256, 383, 0, 255);
        } else if (potVal < 512) {
                red = green = 0;
                blue = map(potVal, 384, 511, 0, 255);
        } else if (potVal < 640) {
                blue = 0;
                red = green = map(potVal, 512, 639, 0, 255);
        } else if (potVal < 768) {
                red = 0;
                green = blue = map(potVal, 640, 767, 0, 255);
        } else if (potVal < 896) {
                green = 0;
                blue = red = map(potVal, 768, 895, 0, 255);
        } else if (potVal < 1000) {
                red = green = blue = map(potVal, 896, 999, 0, 255);
        } else {
                flashColors(potVal * 1000);
        }
}
/*
void potRed() {
        green = blue = 0;
        red = map(pot.update(), 128, 255, 0, 255);
}

void potGreen() {
        red = blue = 0;
        green = map(pot.update(), 256, 511, 0, 255);
}

void potBlue() {
        red = green = 0;
        blue = map(pot.update(), 512, 999, 0, 255);
}
*/
void fadeColors() {
        switch(color) {
                case 0:
                        if (red.getIntensity() == MAX) {//if (!red.stepTo(MAX))
                                color++;                //        color++;
                                break;                  //break;
                        }
                        red.stepTo(MAX);
                        break;
                case 1:
                        if (blue.getIntensity() == MIN) {
                                color++;
                                break;
                        }
                        blue.stepTo(MIN);
                        break;
                case 2:
                        if (green.getIntensity() == MAX) {
                                color++;
                                break;
                        }
                        green.stepTo(MAX);
                        break;
                case 3:
                        if (red.getIntensity() == MIN) {
                                color++;
                                break;
                        }
                        red.stepTo(MIN);
                        break;
                case 4:
                        if (blue.getIntensity() == MAX) {
                                color++;
                                break;
                        }
                        blue.stepTo(MAX);
                        break;
                case 5:
                        if (green.getIntensity() == MIN) {
                                color++;
                                break;
                        }
                        green.stepTo(MIN);
                        break;
                default:
                        if (red.stepTo(MIN) && green.stepTo(MIN) && blue.stepTo(MIN))
                                break;
                        color = 0;
                        break;
        }
}

void flashColors(unsigned int delayVal) {
        red.setDelayVal(delayVal);
        green.setDelayVal(delayVal);
        blue.setDelayVal(delayVal);
        switch (color) {
                case 0:
                        if (red.cycleCheck()) {
                                if (!colorChange) {
                                        colorChange = true;
                                        color++;
                                        break;
                                }
                                colorChange = false;
                                red = MAX;
                                green = blue = MIN;
                        } 
                        break;
                case 1:
                        if (green.cycleCheck()) {
                                if (!colorChange) {
                                        colorChange = true;
                                        color++;
                                        break;
                                }
                                colorChange = false;
                                green = MAX;
                                red = blue = MIN;
                        } 
                        break;
                case 2:
                        if (blue.cycleCheck()) {
                                if (!colorChange) {
                                        colorChange = true;
                                        color++;
                                        break;
                                }
                                colorChange = false;
                                blue = MAX;
                                green = red = MIN;
                        } 
                        break;
                case 3:
                        if (red.cycleCheck()) {
                                if (!colorChange) {
                                        colorChange = true;
                                        color++;
                                        break;
                                }
                                colorChange = false;
                                red = green = MAX;
                                blue = MIN;
                        } 
                        break;
                case 4:
                        if (green.cycleCheck()) {
                                if (!colorChange) {
                                        colorChange = true;
                                        color++;
                                        break;
                                }
                                colorChange = false;
                                green = blue = MAX;
                                red = MIN;
                        } 
                        break;
                case 5:
                        if (blue.cycleCheck()) {
                                if (!colorChange) {
                                        colorChange = true;
                                        color++;
                                        break;
                                }
                                colorChange = false;
                                blue = red = MAX;
                                green = MIN;
                        } 
                        break;
                case 6:
                        if (blue.cycleCheck()) {
                                if (!colorChange) {
                                        colorChange = true;
                                        color++;
                                        break;
                                }
                                colorChange = false;
                                green = red = blue = MAX;
                        } 
                        break;
                default:
                        if (blue.cycleCheck()) {
                                if (!colorChange) {
                                        colorChange = true;
                                        color = 0;
                                        break;
                                }
                                colorChange = false;
                                green = red = blue = MIN;
                        } 
                        break;
        }
        
}
