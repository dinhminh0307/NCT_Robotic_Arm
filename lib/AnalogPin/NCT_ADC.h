#ifndef ANALOG_H
#define ANALOG_H
/*
The Robot Arm using 4 Servo for 4 part of the arm
 . Servo1 - Shoulder - PORTB1
 . Servo2 - Elbow - PORTB2
 . Servo3 - Waist - PORTB3
 . Servo4 - Fingers - PORTB4

-----------------------------------
And the Arduino has 4 analog pin to handle the servos
 . Servo1 - ADC1
 . Servo2 - ADC2
 . Servo3 - ADC3
 . Servo4 - ADC4

 ------------------------From DataSheet -------------------------
 ADC = (Vin / Vref) * 1023
 .Always enable EDAN bit for ADC conversion
 . Bit 6 – ADSC: ADC Start Conversion always write this bit to 1 in each conversion to start it
 . Always select pin channel before starting conversion
 . Vref is the maximum voltage that ADC can convert. For Example arduno is 5V, so we need to enable REFS0 bit
 . For AVR 8 bit we need to set the adc prescaler to 8 ADPS[2:0] = 011
 . Because whe choose A1,A2,A3 so the AMUX to these must plus one
 -------------------------Note-------------------------------
 . Map function is used to convert ref to another ref. Ex: 1023 -> 5V
*/
// #include <avr/interrupt.h>
// #include <avr/io.h>
#include <Arduino.h>
//------------Define AnalogPin---------------//
#define Ana1 0
#define Ana2 1
#define Ana3 2
#define Ana4 3

void REFS0_Config();
void Analog_Init();
void ADC_Config();
void ADC_Disable();
float NCT_StartConversion();
void ADMUX_Reset();
void set_result_wave();
void clear_result_wave();
void ADC_init();
#endif