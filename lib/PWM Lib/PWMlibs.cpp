#include "PWMlibs.h"

void PWM_Write(int pins, int val) {
    DDRB |= (1 << pins);
    TCCR0A |= (1 << WGM01) | (1 << WGM00); // fast mode
    TCCR0A |= (1 << COM0A1); // None inverting
    TCCR0B |= ((1 << CS02) | (1 <<CS00)); // choose prescaler 1024 for all input clock
    OCR0A = val; // set top value to timer 0
}