int latchPin=11;
int clockPin = 9;
int dataPin = 12;
int dt = 500;
byte LEDs = 0b10101010;
byte LEDm;
int j;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(latchPin,OUTPUT);
pinMode(dataPin,OUTPUT);
pinMode(clockPin,OUTPUT);
LEDm = LEDs;
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(latchPin,0);
shiftOut(dataPin,clockPin,LSBFIRST,LEDs);
Serial.println(LEDs, BIN);
digitalWrite(latchPin,1);
delay(dt);
LEDs = 0b11111111-LEDs;
for (j=1;j<5;){
  j+=1;
LEDs= (LEDs/128)+(LEDs*2);
} 

// digitalWrite(latchPin,0);
// shiftOut(dataPin,clockPin,LSBFIRST,LEDs1);
// delay(dt);
// digitalWrite(latchPin,1);
// digitalWrite(latchPin,0);
// shiftOut(dataPin,clockPin,LSBFIRST,LEDs2);
// delay(dt);
// digitalWrite(latchPin,1);
if(LEDs ==0b00000000){
  LEDs = LEDm;
}
}
