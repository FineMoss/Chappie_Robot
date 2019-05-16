#include "Stepper.h"
#include "mbed.h"


Stepper::Stepper(PinName _en, PinName _ms1, PinName _ms2, PinName _ms3, PinName _stepPin, PinName dir):en(_en),
    ms1(_ms1), ms2(_ms2), ms3(_ms3),
    stepPin(_stepPin),
    direction(dir) {}

void Stepper::step(int microstep, int dir, float speed) {
    if (microstep <= 1) { //Full step mode
        ms1 = 0;
        ms2 = 0;
        ms3 = 0;
    }
    else if (microstep == 2) { // Half step mode
        ms1 = 1;
        ms2 = 0;
        ms3 = 0;
    }
    else if (microstep == 4) { // Quater step mode
        ms1 = 0;
        ms2 = 1;
        ms3 = 0;
    }
    else if (microstep == 8) { // Eigth step mode
        ms1 = 1;
        ms2 = 1;
        ms3 = 0;
    }
    else if (microstep >= 16) { // Sixteeth step mode
        ms1 = 1;
        ms2 = 1;
        ms3 = 1;
    }
    if (dir == 1) {
        direction = 0;
    } else if (dir == 0) {
        direction = 1;
    }
    //  Step
    stepPin = 1;
    wait(1/speed);
    stepPin = 0;
    wait(1/speed);
}

void Stepper::enable() {
    en = 0;
}
void Stepper::disable() {
    en = 1;
}
void Stepper::lock() {
    //unimplemented function
}
void Stepper::unlock() {
    //unimplemented function
}