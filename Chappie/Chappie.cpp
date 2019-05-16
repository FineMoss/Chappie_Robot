#include "Chappie.h"
#include "Stepper.h"
#include "ADXL345.h"
#include "mbed.h"


//Chappie::Chappie(Stepper _motor_A, Stepper _motor_B, ADXL345 _accelerometer):
//    motor_A(_motor_A),
//    motor_B(_motor_B),
//    accelerometer(accelerometer) {}
//
//void Chappie::init_chappie() {
//    accelerometer.setPowerControl(0x00);
//    accelerometer.setDataFormatControl(0x0B);
//    accelerometer.setDataRate(ADXL345_3200HZ);
//    accelerometer.setPowerControl(0x08);
//    motor_A.enable();
//    motor_B.enable();
//    motor_A.lock();
//    motor_B.lock();
//    
//    int chappie_down = 1;
//    while(chappie_down) {
//        //if chappie up {
//            chappie_down = 0;
//        //}
//    }
//    motor_A.unlock();
//    motor_B.unlock();
//}
//
//void Chappie::move_forward(int steps, float speed) {
//    int step_count = 1;
//    while(step_count <= steps) {
//        motor_A.step(16, 0, speed);
//        motor_B.step(16, 1, speed);
//        step_count++;
//    }
//}
//void Chappie::move_backward(int steps, float speed) {
//    int step_count = 1;
//    while(step_count <= steps) {
//        motor_A.step(16, 1, speed);
//        motor_B.step(16, 0, speed);
//        step_count++;
//    }
//}
