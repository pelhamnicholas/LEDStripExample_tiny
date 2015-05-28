#include "potentiometer.h"

Potentiometer::Potentiometer(unsigned char pin) : Component(pin), val(0) {
}

int Potentiometer::update() {
	return val = analogRead(pinNum);
}
