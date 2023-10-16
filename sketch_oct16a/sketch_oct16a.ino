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
*/
#include <avr/io.h>
//------------Define Servo pins---------------//
#define SERVO1 1
#define SERVO2 2
#define SERVO3 3
#define SERVO4 4
//------------Define AnalogPin---------------//
#define Ana1 1
#define Ana2 2
#define Ana3 3
#define Ana4 4

//---------Define Functions for the Analog---------//
void Analog_Init() {
  DDRC &= ~((1 << Ana1) | (1 << Ana2) | (1 << Ana3) | (1 << Ana4)); // Set as input
}
void ADC_Config() {
  ADCSRA |= (1 << ADEN); // Enable the ADC

}
//---------Define Function for the Servo----------//
void Arm_Config() {
  DDRB |= ((1 << SERVO1) | (1 << SERVO2) | (1 << SERVO3) | (1 << SERVO4));
}
int main(void) {
  Arm_Config();
  ADC_Config();
  Analog_Init();
  while(1);
}

