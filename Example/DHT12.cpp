#include <Arduino.h>
#include <Wire.h>

#define DHT12_zy (0x61 >> 1) // I2C bus address

void setup() {
    Serial.begin(9600);
    Wire.begin(4,5);
}

void loop() {
  delay(1000);
  byte value0,value1,value2, value3;

  Wire.beginTransmission(DHT12_zy); 
  Wire.write(0x00); 
  Wire.endTransmission();
  Wire.requestFrom(DHT12_zy, 2);
  value0=Wire.read();

  Wire.beginTransmission(DHT12_zy); 
  Wire.write(0x01);
  Wire.endTransmission(); 
  Wire.requestFrom(DHT12_zy, 2);
  value1=Wire.read();

   Wire.beginTransmission(DHT12_zy);
  Wire.write(0x02); 
  Wire.endTransmission(); 
  Wire.requestFrom(DHT12_zy, 2);
  value2=Wire.read();
  
  Wire.beginTransmission(DHT12_zy);
  Wire.write(0x03); 
  Wire.endTransmission();
  Wire.requestFrom(DHT12_zy, 2);
  value3=Wire.read();

 Serial.print("Rh"); Serial.print(value0); Serial.print(".");
 Serial.print(value1); Serial.print(" ");

 Serial.print("T"); Serial.print(value2); Serial.print(".");
 Serial.print(value3); Serial.print(" ");
}