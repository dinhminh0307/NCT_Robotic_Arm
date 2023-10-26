/*
The Robot Arm using 4 Servo for 4 part of the arm
 . Servo1 - Shoulder - PORTB1
 . Servo2 - Elbow - PORTB2
 . Servo3 - Waist - PORTB3
 . Servo4 - Fingers - PORTB4

-----------------------------------
And the Arduino has 4 analog pin to handle the servos
 . Servo1 - ADC3
 . Servo2 - ADC4
 . Servo3 - ADC5
 . Servo4 - PORTB5

-----------For the potentiometer reading input: PWM/ADC------------------
 . ADC3 - ADC0
 . ADC4 - ADC1
 . ADC5 - ADC2
 ------------------------From DataSheet -------------------------
 ADC = (Vin / Vref) * 1023
 .Always enable EDAN bit for ADC conversion
 . Bit 6 – ADSC: ADC Start Conversion always write this bit to 1 in each conversion to start it
 . Always select pin channel before starting conversion
 . Vref is the maximum voltage that ADC can convert. For Example arduno is 5V, so we need to enable REFS0 bit
 . For AVR 8 bit we need to set the adc prescaler to 8 ADPS[2:0] = 011
 -------------------------Note-------------------------------
 . Map function is used to convert ref to another ref. Ex: 1023 -> 5V
*/
#include <AnaLogPin.h>
//------------Define Servo pins---------------//
#define SERVO1 1
#define SERVO2 2
#define SERVO3 3
#define SERVO4 4


//---------Define Function for the Servo----------//
void Arm_Config() {
  DDRB |= ((1 << SERVO1) | (1 << SERVO2) | (1 << SERVO3) | (1 << SERVO4));
}
//---------Enable the Pin Change Interupt mode-----//
void PCINT_Enable() { // This function to receive input from analog pins
  // Enable pin change interupt regiter 0 bc it suitable fro PC[0:7]
  PCICR |= (1 << PCIE0);
  sei();
}

int main(void) {
  Arm_Config();
  ADC_init();
  Serial.begin(9600);
  DDRB |= (1 << 5);
  while(1) {
    Serial.println(startConversion());
    // delay(500);
  }
}

