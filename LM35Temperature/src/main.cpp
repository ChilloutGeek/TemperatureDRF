#include <Arduino.h>

const int LM35_pin = A1;
const float LM35_calib = 0.48875; //convert voltage to temp
char temperature;

void setup() {
  Serial.begin(115200);
  // put your setup code here, to run once:
}

void loop() {
  float temperature = analogRead(LM35_pin) * LM35_calib;
  char temp_str[10];
  dtostrf(temperature, 4, 2, temp_str);
  Serial.println(temperature);
  delay(5000);

  // put your main code here, to run repeatedly:
}