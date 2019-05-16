#ifndef MBED_STEPPER_H
#define MBED_STEPPER_H
#include "mbed.h"


class Stepper {
    
    public:
        Stepper(PinName _en, PinName _ms1, PinName _ms2, PinName _ms3, PinName _stepPin, PinName dir);
        void step(int microstep, int dir, float speed);
        void enable();
        void disable();
        void lock();
        void unlock();
    
    private:
        DigitalOut en;
        DigitalOut ms1;
        DigitalOut ms2;
        DigitalOut ms3;
        DigitalOut stepPin;
        DigitalOut direction;
          
};
#endif