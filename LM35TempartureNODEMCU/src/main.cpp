#include <Arduino.h>
#include <WiFiClient.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

const char* ssid = "Gemenez_MainRouter";
const char* password = "LifeIsHere";
const char* serverUrl = "http://192.168.2.134:8000/api/data/temperature/";

const int lm35Pin = A0;
const float LM35_calib = 0.48875; 

void setup() {
  Serial.begin(9600);
  delay(10);
  Serial.println();
  Serial.println();
  Serial.print("Connecting to");
  Serial.println(ssid);

  WiFi.begin(ssid,password);
  while (WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi Connected");
  // put your setup code here, to run once:
}

void loop() {

  float temperature = analogRead(lm35Pin) * LM35_calib;
  delay(1000);

  Serial.print(temperature);

  WiFiClient client;
  HTTPClient http;
  
  String payload = "{\"temp\": " + String(temperature) + "}";

  Serial.print("Connecting to Server: ");
  Serial.println(serverUrl);

  http.begin(client, serverUrl);
  http.addHeader("Content-Type", "application/json");
  int httpResponseCode = http.POST(payload);
  
  if (httpResponseCode > 0) {
    Serial.print("HTTP Response Code: ");
    Serial.print("httpResponseCode");
  } else {
    Serial.print("Error During HTTP Post: ");
    Serial.println(httpResponseCode);
  }
  http.end();

  delay(10000);
  // put your main code here, to run repeatedly:
}