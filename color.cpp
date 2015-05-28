#include "color.h"

Color::Color(unsigned char pin) : Component(pin, 50), maxIntensity(255), intensity(0) {
}

Color::Color(unsigned char pin, Potentiometer & pot) : Component(pin), maxIntensity(255), intensity(0) {
        intensityPot = &pot;
}

void Color::init(unsigned char mode){
        Component::init(mode);
        writeVal(intensity);
}

void Color::assignDelayPot(Potentiometer & pot, unsigned char scale) {
        delayPot = &pot;
        delayScale = scale;
}

void Color::fadeTo(unsigned char intensityFinal) {
        if (intensityPot && intensityFinal > updateMaxIntensity()) {
                intensityFinal = maxIntensity;
        }
	while (intensity != intensityFinal) {
                if (cycleCheck()) {
        		if (intensity < intensityFinal) {
	        		writeVal(++intensity);
		        } else if (intensity > intensityFinal) {
			        writeVal(--intensity);
		        }
                }
                updateDelay();
	}
}

bool Color::stepTo(unsigned char intensityFinal) {
        if (intensityPot && intensityFinal > updateMaxIntensity()) {
                intensityFinal = maxIntensity;
        }
        if (cycleCheck()) {
		if (intensity < intensityFinal) {
	        	++intensity;
		} else if (intensity > intensityFinal) {
		        --intensity;
		}
                writeVal(intensity);
	        updateDelay();
        }
	return (intensity == intensityFinal) ? false : true;
}

unsigned char Color::updateMaxIntensity() {
        return maxIntensity = (intensityPot->update() / 4);
}

unsigned int Color::updateDelay() {
        if (delayPot) {
	        return delayVal = (delayPot->update() / delayScale);
        }
        return delayVal;
}

int Color::operator=(unsigned char opIntensity) {
        intensity = opIntensity;
        writeVal(intensity);
}

int Color::operator=(Color & opColor) {
        intensity = opColor.getIntensity();
}

int Color::operator+(unsigned char opIntensity) {
        if (intensity < (256 - opIntensity)) {
                intensity += opIntensity;
                writeVal(intensity);
        }
        return intensity;
}

int Color::operator-(unsigned char opIntensity) {
        if (intensity > (0 + opIntensity)) {
                intensity -= opIntensity;
                writeVal(intensity);
        }
        return intensity;
}

int Color::operator++() {
	if (intensity < 256) {
		writeVal(++intensity);
	}
	return intensity;
}

int Color::operator--() {
	if (intensity > 0) {
		writeVal(--intensity);
	}
	return intensity;
}
