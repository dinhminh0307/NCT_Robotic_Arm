#include "AnalogPin.h"

int analFlag = 0;
bool testVar = false;
const int numberOfChanel = 3;
const float ADC_2V = 5 * 1/1023.0;
int counter = 0;
int n = 50;
float sum = 0;
//---------Define Functions for the Analog---------//
void REFS0_Config() {
  ADMUX &= ~((1 << REFS1) | (1 << REFS0)); // Specify Vref
  ADMUX &= ~((1 << MUX3) | (1 << MUX2) | (1 << MUX1) | (1 << MUX0)); // choose pin A1 as the analog pin
  sei(); // Enable interupt
}
void Analog_Init() {
  DDRC &= ~((1 << Ana1) | (1 << Ana2) | (1 << Ana3) | (1 << Ana4)); // Set as input
}
void ADC_Config() {
  ADCSRA |= ((1 << ADEN) | (1 << ADPS1) | (1 << ADPS0)); // Enable the ADC
  ADCSRA &= ~(1 << ADPS2); // Set up prescaler 8
}

void ADC_Disable() {
  ADCSRA &= ~(1 << ADEN); // Disable the ADC
}

void startConversion() {
  ADCSRA |=  (1<<ADSC);
  while(counter < numberOfChanel) { // Start conversion for each pin
    for(int k = 0; k < n; k++) {
      while (ADCSRA & (1 <<ADSC)) { // Check if the conversion is already in progress, if the progress done, ADSC bit become 0
        
      }
      sum = sum + ADC;
    }
    ADMUX += 1; // go incrementally from 1 to 4
    counter++;
  }
  
}