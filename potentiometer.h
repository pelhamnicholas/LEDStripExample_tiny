#ifndef POT_H
#define POT_H

#include "component.h"

class Potentiometer : public Component {
	private:
		int val;

	public:
                Potentiometer();
		Potentiometer(unsigned char );
		int update();
};

#endif
