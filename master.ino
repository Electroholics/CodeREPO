#include <Wire.h>
int x = 0;
int sensorPin = A0; 
int sensorValue=0;
void setup() {
 // Start the I2C Bus as Master
 Wire.begin();
delay(1000);
}

void loop() {
sensorValue = analogRead(sensorPin); 
Wire.beginTransmission(9); // transmit to device #9
 Wire.write(sensorValue);           // sends x
 Wire.endTransmission(); // stop transmitting
   delay(500);
}
