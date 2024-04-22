#include <IRremote.h>
#include<Stepper.h>
int stepsPerRevolution=2048;
Stepper myStepper(stepsPerRevolution, 8,10,9, 11);
int motSpeed = 10;
int dt = 500;
int direc;
int IRpin = 3;
IRrecv IR(IRpin);
decode_results data;
int dt =  500;
byte value;
int led1 = 6;
int led2 = 5;
int led3 = 7;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
IR.enableIRIn();
myStepper.setSpeed(motSpeed);
}

void loop() {
  // put your main code here, to run repeatedly:
while (IR.decode(&data)==0){
   myStepper.step(speedn*1);
}
Serial.println( data.value,HEX);
//delay(dt);

if (data.value== 0xFF30CF){
  direc = 1;
  }
  if (data.value== 0xFF10EF){
    motspeed = 10;
  }
if (data.value== 0xFF18E7){
    direc = 0;
  }
 if (data.value== 0xFF38C7){
    direc = -1;
  } 
  if (data.value== 0xFF7A85){
    motspeed = 5;
  } 
   myStepper.step(direc);
IR.resume();
}
