#include<Servo.h>
int servoPin =10;
int servoPos;
int Photo = A5;
float Time;
int volt;
Servo light_tracker;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(Photo,INPUT);
  light_tracker.attach(servoPin);
}

void loop() {
  // put your main code here, to run repeatedly:
 int dt = 1000;
volt = analogRead(Photo);
Time = 180./1023.*volt;
if (Time > 300){
servoPos =160;}
if (Time < 30 && Time> 4 ){
servoPos =90;}
if (Time < 4){
servoPos =0;}
Serial.println(Time);
delay(100);


servoPos = 5;

light_tracker.write(servoPos);
delay(dt);
servoPos = 90;

light_tracker.write(servoPos);
delay(dt);
servoPos = 175;

light_tracker.write(servoPos);
delay(dt);

}
