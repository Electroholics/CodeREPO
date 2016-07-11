int a;
int  sensoranalogpin=A0;
int ledPin=11;
int sensorvalue=0;
int outputValue=0;
void setup() {
  // put your setup code here, to run once:
pinMode(7,OUTPUT);
pinMode(A0,INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
sensorvalue=analogRead(sensoranalogpin);
Serial.println(sensorvalue);
outputValue = map(sensorvalue, 0, 1023, 0, 255); 
analogWrite(ledPin, outputValue);
Serial.println (outputValue);
delay(200);
}



