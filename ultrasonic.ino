#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int echoPin = 7; // Echo Pin
int trigPin = 8; // Trigger Pin
int LEDPin = 13;// connected LED
int maximumRange = 200; // Maximum range of sensor in inches
int minimumRange = 0; // Minimum range needed
float pingTime=0.;
float targetDistance=0; // Duration used to calculate distance
int speedofSound=330; //constant in m/s
void setup() {
 Serial.begin (9600);
 pinMode(trigPin, OUTPUT); //sonic pulse from trigPin
 pinMode(echoPin, INPUT); //detection at Echo Pin
 pinMode(LEDPin, OUTPUT); // Use LED indicator (if required)
 lcd.begin(16, 2);
  // initialize the serial communications:
  Serial.begin(9600);
 /*USe LED to flash if min and maximum distance out of range,
 as set in the program */
}
void loop() {
/* The following trigPin/echoPin cycle is used to determine the
 distance of the nearest object by bouncing soundwaves off of it. */
 digitalWrite(trigPin, LOW);
 delayMicroseconds(2000);
 //Used 2 seconds to sette the trigPin
//Sending 20 milliseconds pulses, microsecond pulses are used
//with sophisticated ultrasonic sensors
 digitalWrite(trigPin, HIGH);
 delayMicroseconds(20);
 digitalWrite(trigPin, LOW);
 pingTime = pulseIn(echoPin, HIGH); //calculate the time of flight distance
// in microseconds
 //Calculate the distance (in inches) based on the speed of sound.
 pingTime=pingTime/1000000.; //calculate time in seconds
 targetDistance=(speedofSound*pingTime)*39.37; //twice distace in inches
 targetDistance=targetDistance/2;
 if (targetDistance >= maximumRange || targetDistance <= minimumRange)
 {
 /* Send a negative number to computer and Turn LED ON
 //to indicate "out of range" */
 Serial.println("-1");

 digitalWrite(LEDPin, HIGH);
 }
 else {
 /* Send the distance to the computer using Serial protocol, and
 turn LED OFF to indicate successful reading. */
 
 Serial.println(targetDistance);
 lcd.print(targetDistance);
 lcd.setCursor(0,1);
 digitalWrite(LEDPin, LOW);
 }
 //Delay 50ms before next reading.
 delay(50);
}
