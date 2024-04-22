#include <SoftwareSerial.h>  // import the serial library

SoftwareSerial me(2, 3);  // RX, TX

int red = 5;
int white = 6;
int buzzer = 7;
String InputData;  // the data given from bluetooth device
 
void setup() {
  // put your setup code here, to run once:
  me.begin(9600);
  Serial.begin(9600);
  pinMode(white,OUTPUT);
  pinMode(red,OUTPUT);
  Serial.println("Bluetooth On you can send messages.");
}


void loop() {
  // put your main code here, to run repeatedly:

  if (me.available()) {
    InputData = me.read();
    if (InputData == '1') {  // if number 1 pressed ....
      digitalWrite(red, 1);
      me.println("red on ! ");
    }
    if (InputData == '0') {  // if number 0 pressed ....
      digitalWrite(red, 0);
      me.println("red  Off ! ");
    }
    
    if(InputData == '3'){
      digitalWrite(white,1);
      me.println("white on ! ");
    }
    if(InputData == '2'){
      digitalWrite(white,0);
      me.println("white off ! ");
    }
    if(InputData == '5'){
      digitalWrite(buzzer,1);
      me.println("buzzer on ! ");
    }
    if (Inputdata == '4'){
       digitalWrite(buzzer,0);
       me.println("buzzer  Off ! ");
    }
  }
  delay(100);  // prepare for next data ...

}
