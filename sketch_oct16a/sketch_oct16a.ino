void setup() {
  Serial.begin(9600); 
}  

void loop() {  
  //REFS1 AND REFS0 to 1 1 -> internal 1.1V refference
  //ADMUX |= B00000010;   
  //We read A1 (MUX0)
  ADMUX |= B00000000;      
 
  // Start AD conversion
  ADCSRA |= B11000000;
  // Detect end-of-conversion
  while (bit_is_set(ADCSRA,ADSC));
  int val = ADCL | (ADCH << 8);
  float voltage = val * (5 / 1023.0);
  // print out the value you read:
  Serial.println(voltage);
}