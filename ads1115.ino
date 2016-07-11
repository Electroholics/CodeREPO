#include <Wire.h>
#include <Adafruit_ADS1015.h>
Adafruit_ADS1115 ads(0x48);//since address is 0x48 we have to connect address pin to ground
float Voltage = 0.0;
void setup(void) 
{
  Serial.begin(9600);  
  ads.begin();//now the adafruit lib uses wire.h that’s  why we have included it
}
void loop() 
{
  int16_t adc0;  // we read from the ADC, we have a sixteen bit integer as a result
  adc0 = ads.readADC_SingleEnded(0);// 0 stands for the AIN0 we  are taking input from pin zero 
  Voltage = (adc0 * 0.1875)/1000;//dividing by 0.1875 bcoz default full scale is 6.144 and dividing it with 32728 we get 0.1875
  
  Serial.print("AIN0: "); 
  Serial.print(adc0);//this will output the digital value 
  Serial.print("\tVoltage: ");
  Serial.println(Voltage, 7);  //this will output the input voltage that we give as input upto 7 places 
  Serial.println();
  
  delay(1000);
}


