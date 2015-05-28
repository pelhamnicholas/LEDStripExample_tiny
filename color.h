#ifndef COLOR_H
#define COLOR_H

#include "component.h"
#include "potentiometer.h"

class Color : public Component {
	private:
                unsigned char maxIntensity;
		unsigned char intensity;
                Potentiometer * intensityPot;
                static Potentiometer * delayPot;
                static unsigned char delayScale;
	public:
                Color();
		Color(unsigned char );
                Color(unsigned char, Potentiometer& );
		void init(unsigned char );
                static void assignDelayPot(Potentiometer & pot) {delayPot = &pot;};
                static void assignDelayPot(Potentiometer & , unsigned char );
		void fadeTo(unsigned char );
		bool stepTo(unsigned char );
                unsigned char updateMaxIntensity();
		unsigned int updateDelay();
		int getPinNum() {return pinNum;}
                int getIntensity() {return intensity;};
                int operator=(unsigned char );
                int operator=(Color & );
                int operator+(unsigned char );
                int operator+=(unsigned char opIntensity) {return operator+(opIntensity);};
                int operator-(unsigned char );
                int operator-=(unsigned char opIntensity) {return operator-(opIntensity);};
		int operator++();
		int operator--();
};

#endif
