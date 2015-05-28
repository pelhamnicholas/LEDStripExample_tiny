#include "component.h"

Component::Component(unsigned char pin) : pinNum(pin), delayVal(30) {
        lastMillis = 0;
}

Component::Component(unsigned char pin, unsigned int dVal) : pinNum(pin), delayVal(dVal) {
        lastMillis = 0;
}

void Component::init(unsigned char mode) {
	pinMode(pinNum, mode);
}

unsigned char Component::writeVal(unsigned char newVal) {
        switch(pinNum) {
                case 0:
                        OCR0A = newVal;
                        break;
                case 1: 
                        OCR0B = newVal;
                        break;
                case 4: 
                        OCR1B = newVal;
                        break;
                default:
                        break;
        }
        return newVal;
}

unsigned long Component::setMillis() {
        lastMillis = millis();
        return lastMillis;
}

bool Component::cycleCheck() {
        unsigned long currentMillis = millis();
        if(currentMillis - lastMillis >= delayVal)
        {
                lastMillis = currentMillis;
                return true;
        } else {
                return false;
        }
}
