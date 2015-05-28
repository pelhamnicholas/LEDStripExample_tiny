#ifndef COMPONENT_H
#define COMPONENT_H

#include <Arduino.h>

class Component {
        private:
                unsigned long lastMillis;

        protected:
                unsigned char pinNum;
                unsigned int delayVal;

        public:
                Component();
                Component(unsigned char );
                Component(unsigned char, unsigned int );
		void init(unsigned char );
                unsigned char writeVal(unsigned char );
                unsigned long setMillis();
                bool cycleCheck();
                unsigned int setDelayVal(unsigned int dVal) {return delayVal = dVal;};
                unsigned int getDelayVal() {return delayVal;}
};

#endif
