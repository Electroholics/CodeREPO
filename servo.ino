#include<Servo.h>
Servo myservo;
void stopSignal(){
myservo.writeMicroseconds(1500);
delay(20);
}
void rotateSignalCW(int time){
myservo.writeMicroseconds(500);
delay(time);
}
void rotateSignalCCW(int time){
myservo.writeMicroseconds(2500);
delay(time);
}
void setup(){
myservo.attach(9);
}
void loop()
{
rotateSignalCCW(177);
stopSignal();
}
