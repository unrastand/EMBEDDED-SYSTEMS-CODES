#include <IRremote.h>
int IRp = 10;
IRrecv IReciever(IRp);
decode_results cmd;
int dt =  500;
byte value;
int RED = 5;
int GREEN = 6;
int BLUE = 7;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
IReciever.enableIRIn();
}

void loop() {
  // put your main code here, to run repeatedly:
while (IReciever.decode(&cmd)==0){
}
Serial.println( cmd.value,HEX);
delay(dt);
if (cmd.value== 0xFF30CF){
  digitalWrite(RED,1);
  }
  if (cmd.value== 0xFF10EF){
   digitalWrite(RED,0);
  }
if (cmd.value== 0xFF18E7){
   digitalWrite(GREEN,1);
  }
 if (cmd.value== 0xFF38C7){
   digitalWrite(GREEN,0);
  } 
  if (cmd.value== 0xFF7A85){
   digitalWrite(BLUE,1);
  } 
  if (cmd.value== 0xFF5AA5){
   digitalWrite(BLUE,0);
  } 
IReciever.resume();
}
