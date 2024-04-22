#include <Servo.h>

Servo myservo;   
int pos = 0;    // variable to store the servo position
int Pontentiometer = A0; 
void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  pinMode(Pontentiometer,INPUT);
  Serial.begin(9600);
} 
void loop() { 
     myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(20);           
    int val=analogRead(Pontentiometer );            // waits 15 ms for the servo to reach the position
 pos=map(val,0,1023,10,170);
 Serial.println(pos);
}
