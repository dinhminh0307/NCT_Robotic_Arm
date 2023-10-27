#ifndef PWMLIB_H
#define PWMLB_H
#include "./NCT_ADC.h"
/*For this library, we use PWM registers in avr to control the signal sending to servo
Reference: http://arduino.vn/tutorial/1416-avr-xuat-xung-voi-tan-so-va-do-rong-theo-y-muon
*/

void PWM_Write(int pins, int val);
#endif