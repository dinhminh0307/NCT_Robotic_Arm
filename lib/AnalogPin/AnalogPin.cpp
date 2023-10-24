#include "AnalogPin.h"

volatile int j = 0;
int analFlag = 0;
bool testVar = false;
const int numberOfChanel = 3;
const float ADC_2V = 5 * 1/1023.0;
int counter = 0;
volatile float ADC_Pins[3] = {0,0,0}; // store the voltage value from pins
int n = 50; // samples
volatile float sum = 0;
volatile int result = 0;
float t = 0;

//---------Define Functions for the Analog---------//
void REFS0_Config() {
  cli();
  ADMUX &= ~((1 << REFS1) | (1 << REFS0)); // Specify Vref
  ADMUX &= ~((1 << MUX3) | (1 << MUX2) | (1 << MUX1) | (1 << MUX0)); // choose pin A0 as the analog pin
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

void ADMUX_Reset() { // Reset when finish the conversion for 3 pins
  ADMUX &= ~((1 << REFS1) | (1 << REFS0)); // Specify Vref
  ADMUX &= ~((1 << MUX3) | (1 << MUX2) | (1 << MUX1) | (1 << MUX0)); // choose pin A0 as the analog pin
}
float startConversion() {
  ADCSRA |=  (1<<ADSC);
  while (ADCSRA & (1 <<ADSC)); // Wait for the conversion to complete
  result =ADCL;
  result |= (ADCH << 8);
  sum = (float) result * ADC_2V;
  return sum;
}

void set_result_wave() {
  for(int i = 0; i < 3; i++) {
    final_result[i] = ADC_Pins[i];
  }
}

void clear_result_wave() {
  for(int i = 0; i < 3; i++) {
    final_result[i] = 0;
  }
}