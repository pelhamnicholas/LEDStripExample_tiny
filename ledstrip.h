#include "potentiometer.h"
#include "color.h"

#define MAX 255
#define MIN 0

Potentiometer * Color::delayPot;
unsigned char Color::delayScale = 1;


void initPWM() {        
        // Timer 0, A side
        TCCR0A = (1<<WGM00) | (1<<WGM01) | (1<<COM0A1) | (1<<COM0B1);
        TCCR0B = (1<<CS00);
        OCR0A = MIN; // duty cycle // pulse width

        // Timer 0 B side
        //TCCR0A |= _BV (COM0B1);
        OCR0B = MIN; // duty cycle // pulse width

        // Timer 1
        TCCR1 = (1<<CS10);
        GTCCR = (1<<COM1B1) | (1<<PWM1B);
        OCR1B = MIN; // duty cycle // pulse width
        OCR1C = MAX; // frequency
}

