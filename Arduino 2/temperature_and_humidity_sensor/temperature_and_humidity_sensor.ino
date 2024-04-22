#include<DHT.h>
#define Type DHT11
int sensePin = 2;
DHT HT(sensePin,Type);
float humidit;
float tempC;
float tempF;
int dt = 1000;
int setTime = 500;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
HT.begin();
delay(setTime);
}

void loop() {
  // put your main code here, to run repeatedly:
humidit = HT.readHumidity();
tempC = HT.readTemperature();
tempF = HT.readTemperature(true);
Serial.print("humidity  ");
Serial.print(humidit);
Serial.print("   Celcius  ");
Serial.print(tempC);
Serial.print("  Farienheight  ");
Serial.println(tempF);
delay(dt);
}
