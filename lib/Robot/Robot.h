#ifndef ROBOT_H
#define ROBOT_H
#include "./NCT_PWM.h"
#include <Servo.h>
//------------Define Servo pins---------------//
#define SERVO1 1
#define SERVO2 2
#define SERVO3 3
#define SERVO4 4

class Robot {
    public:
        Servo servo1;
        Servo servo2;
        Servo servo3;
        Servo servo4;
        void init();
        void moveGripper();
        
};
#endif