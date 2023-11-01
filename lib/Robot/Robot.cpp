#include "Robot.h"

void Robot::init() {
    DDRB |= ((1 << SERVO1) | (1 << SERVO2) | (1 << SERVO3) | (1 << SERVO4));
    servo1.attach(8);
    servo2.attach(9);
    servo3.attach(10);
    servo4.attach(11);
}

void Robot::moveGripper() { // for channle A3 input and Servo 4 output
    ADC_init(A3);
    float val = NCT_StartConversion();
    val = map(val, 0, 1023, 0, 180); // convert ADC to degree
    servo4.write(val); // while the position of degree to servo
    delay(100);
}