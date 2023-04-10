#include <Arduino.h>

const int LM35_pin = A1;
const float LM35_calib = 0.48875; //convert voltage to temp

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
}

void loop() {
  float temperature = analogRead(LM35_pin) * LM35_calib;
  Serial.println(temperature);
  delay(1000);

  // put your main code here, to run repeatedly:
}