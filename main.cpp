#include "mbed.h"
#include "Stepper.h"
#include "ADXL345.h"

//Stepper motors A and B
Stepper motor_A(p27, p28, p29, p30, p20, p19);
Stepper motor_B(p21, p22, p23, p24, p25, p26);

//Accelerometer
ADXL345 accelerometer(p5, p6, p7, p8);

//Serial out
Serial pc(USBTX, USBRX);

void init_chappie() {
    accelerometer.setPowerControl(0x00);
    accelerometer.setDataFormatControl(0x0B);
    accelerometer.setDataRate(ADXL345_3200HZ);
    accelerometer.setPowerControl(0x08);
    motor_A.enable();
    motor_B.enable();
}

void move_forward(int steps, float speed) {
    int step_count = 1;
    while(step_count <= steps) {
        motor_A.step(16, 0, speed);
        motor_B.step(16, 1, speed);
        step_count++;
    }
}
void move_backward(int steps, float speed) {
    int step_count = 1;
    while(step_count <= steps) {
        motor_A.step(16, 1, speed);
        motor_B.step(16, 0, speed);
        step_count++;
    }
}

//fetches accelerometer data
int get_z() {
    float sum = 0.0;
    int count = 0;
    while(count < 100) {
        int readings[3] = {0, 0, 0};
        accelerometer.getOutput(readings);
//        float x = (int16_t)readings[0]*1.77;   
//        float y = (int16_t)readings[1]*1.77;     
        float z = (int16_t)readings[2]*1.47;
        sum +=  z;
        count += 1;
    }  
    return int(sum/100);
}










int main() {
    init_chappie();
    while(1) {  
        int z = get_z();
        
        //forward is lower (200)
        //backwards is higher (600)
        int center = 470;

        //if chappie lean forward
        if (z < center-15) {
            move_backward((center-z)*4, (center-z+20)*90);
        }
        
        //if chappie lean backward
        if (z > center+15) {
            move_forward((z-center)*4, (z-center+20)*90);    
        }
           
    }
}

