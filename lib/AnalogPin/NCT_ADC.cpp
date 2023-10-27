#include "NCT_ADC.h"

float sum = 0;
uint16_t result = 0;
volatile int stored_pin;

//---------Define Functions for the Analog---------//
void REFS0_Config() {
  ADMUX &= ~((1 << REFS1) | (1 << REFS0)); // Specify Vref
  ADMUX &= ~(1 << ADLAR); // left adjust the result
  sei(); // Enable interupt
}
void Analog_Init() {
  DDRC &= ~((1 << Ana1) | (1 << Ana2) | (1 << Ana3)); // Set as input
}
void ADC_Config() {
  ADCSRA |= ((1 << ADEN) | (1 << ADPS1) | (1 << ADPS0)); // Enable the ADC
  ADCSRA &= ~(1 << ADPS2); // Set up prescaler 8
}

void ADC_Disable() {
  ADCSRA &= ~(1 << ADEN); // Disable the ADC
}

void ADMUX_Reset(int reset_pin) { // Reset when finish the conversion for 3 pins
  ADMUX |= (1 << REFS0); // Specify Vref
  ADMUX &= ~(1 << REFS1);
  resetChannel(reset_pin);
  stored_pin = 0;
}

void selectChannel(int channel) {
  switch (channel) {
    case A0:
      ADMUX &= ~((1 << MUX3) | (1 << MUX2) | (1 << MUX1) | (1 << MUX0)); // choose pin A0 as the analog pin
      stored_pin = A0;
      break;
    case A1:
      ADMUX &= ~((1 << MUX3) | (1 << MUX2) | (1 << MUX1));
      ADMUX |= (1 << MUX0);
      stored_pin = A1;
      break;
    case A2:
      ADMUX &= ~((1 << MUX3) | (1 << MUX2) | (1 << MUX0));
      ADMUX |= (1 << MUX1);
      stored_pin = A2;
      break;
    case A3:
      ADMUX &= ~((1 << MUX3) | (1 << MUX2));
      ADMUX |= ((1 << MUX1) | (1 << MUX0));
      stored_pin = A3;
      break;
    default:
      break;
  }
}

float NCT_StartConversion() {
  ADCSRA |=  (1<<ADSC);
  while (ADCSRA & (1 <<ADSC)); // Wait for the conversion to complete
  // for(int i = 0; i < 10;i++) { // transfer result from ADC to the 16 bit result
  //   if( i == 8 || i == 9) {
  //     if(ADCH & (1 << i)) {
  //       result |= (1 << i);
  //     }
  //     else {
  //       result &= ~(1 << i);
  //     }
  //   }
  //   else {
  //     if(ADCL & (1 << i)) {
  //       result |= (1 << i);
  //     }
  //     else {
  //       result &= ~(1 << i);
  //     }
  //   }
  // }
  result = ADCL;
  result |= (ADCH << 8);
  sum = (float) (5./1023.) * result;
  ADMUX_Reset(stored_pin); // Fix ADC function 
  return sum;
}

void resetChannel(int channel) {
  switch (channel) {
    case A0:
      ADMUX &= ~((1 << MUX3) | (1 << MUX2) | (1 << MUX1) | (1 << MUX0)); // choose pin A0 as the analog pin
      break;
    case A1:
      ADMUX &= ~((1 << MUX3) | (1 << MUX2) | (1 << MUX1));
      ADMUX |= (1 << MUX0);
      break;
    case A2:
      ADMUX &= ~((1 << MUX3) | (1 << MUX2) | (1 << MUX0));
      ADMUX |= (1 << MUX1);
      break;
    case A3:
      ADMUX &= ~((1 << MUX3) | (1 << MUX2));
      ADMUX |= ((1 << MUX1) | (1 << MUX0));
      break;
    default:
      break;
  }
}

void ADC_init(int channels) {
  ADC_Config();
  Analog_Init();
  selectChannel(channels);
  REFS0_Config();
}
