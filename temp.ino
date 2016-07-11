int set_temp=60;int delta=2;int sensorPin=A0;int outpin=10; int sensorValue=0;
void setup() {  // put your setup code here, to run once:  
  Serial.begin(9600);  pinMode(outpin,OUTPUT);  pinMode(13,OUTPUT);}
void loop() {  // put your main code here, to run repeatedly: 
  Serial.println("set_temp is");  Serial.println(set_temp);  delay(2000);
}
  sensorValue=analogRead(sensorPin);  float sense_voltage=sensorValue * (5.0 / 1023.0);  float sense_temp=sense_voltage*100;
  Serial.println("sense_temp is");  Serial.println(sense_temp);  delay(2000);
  if (sense_temp >= set_temp + delta)  {    digitalWrite(outpin,HIGH);    digitalWrite(13, LOW);    delay(10);  }  else if(sense_temp < set_temp - delta)  {    digitalWrite(outpin, LOW);    digitalWrite(13,HIGH);    delay(10);  }}
