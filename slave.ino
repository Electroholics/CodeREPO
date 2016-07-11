// Include the required Wire library for I2C
#include <Wire.h>
const int analogOutpin=11;
int x = 0;
void setup() {
   // Start the I2C Bus as Slave on address 9
 Wire.begin(9);
 Serial.begin(9600);
 // Attach a function to trigger when something is received.
 Wire.onReceive(receiveEvent);
}
void receiveEvent(int bytes) {
 x = Wire.read(); // read one character from the I2
}
void loop() {
analogWrite(analogOutpin,x);   
Serial.println(x);
 delay(500);
}

