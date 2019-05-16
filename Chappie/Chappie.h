#ifndef MBED_CHAPPIE_H
#define MBED_CHAPPIE_H
#include "Stepper.h"
#include "ADXL345.h"
#include "mbed.h"


class Chappie {
    
    public:
        Chappie(Stepper _motor_A, Stepper _motor_B, ADXL345 _accelerometer);
        void init_chappie();
        void move_forward(int steps, float speed);
        void move_backward(int steps, float speed);
        
    private:
        Stepper motor_A;
        Stepper motor_B;
        ADXL345 accelerometer;
        
};
#endif