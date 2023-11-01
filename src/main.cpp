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
#include <Robot.h>


Robot NCT_Robot;
int selectedChannel = A0;
float Vout = 0.0;
//---------Define Function for the Servo----------//

//---------Enable the Pin Change Interupt mode-----//
void PCINT_Enable() { // This function to receive input from analog pins
  // Enable pin change interupt regiter 0 bc it suitable fro PC[0:7]
  PCICR |= (1 << PCIE0);
  sei();
}

float convertV2Bit(float V, float Vout) {
  V += Vout;
  return (V / 5.) * 255;
}



int main(void) {
  // ADC_init(selectedChannel);
  // Serial.begin(9600);
  // DDRB |= (1 << 5);
  // while(1) {
  //   float V = 0.0;
  //   Vout = NCT_StartConversion();
  //   V = convertV2Bit(V, Vout);
  //   Serial.println(Vout);
  //   PWM_Write(5, 255);

  //   // delay(500);
  // }
  NCT_Robot.init();
  while(1) {
    NCT_Robot.moveGripper();
  }
}

