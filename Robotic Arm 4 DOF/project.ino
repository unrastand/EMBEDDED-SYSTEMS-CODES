#include<Servo.h>
Servo rightServo;
Servo leftServo;
Servo clawServo;
Servo baseServo;

const int servoRightPin = 3;
const int servoLeftPin = 13;
const int servoClawPin = 5;
const int servoBasePin = 6;

const int potenRx = A2;
const int potenRy = A3;
const int potenLx = A0;
const int potenLy = A1;

const int buttonL = 12;
int buttonLState = 0;
int buttonLOldState = 0;
int buttonLeft = 2;
const int buttonR = 8;
int buttonRState = 0;
int buttonROldState = 0;

int ClawPos = 90;
int ClawIncrease = 2;
int ClawReduce = -2;
int analogRy=0;
int buttonLeftRead=0;
void setup() {
  // put your setup code here, to run once:
  rightServo.attach(servoRightPin);
  leftServo.attach(servoLeftPin);
  clawServo.attach(servoClawPin);
  baseServo.attach(servoBasePin);

  pinMode(potenRx, INPUT);
  pinMode(potenRy, INPUT);
  pinMode(potenLy, INPUT);
  pinMode(potenLx, INPUT);
  pinMode(buttonL, INPUT);
  pinMode(buttonR, INPUT);
  pinMode(buttonLeft, INPUT);
  Serial.begin(9600);
  digitalWrite(buttonLeft,0);
  analogWrite(potenRx,0);
   analogWrite(potenRy,0);
    analogWrite(potenLx,0);
     analogWrite(potenLy,0);
}

void loop() {
  // put your main code here, to run repeatedly:
    //set the base with left first then control it with right
 buttonLeftRead=digitalRead(buttonLeft);  
 while (buttonLeftRead == 1) {
  analogRy= analogRead(potenRy);
  delay(500);
  baseServo.write(map(analogRy, 2, 178, 0, 1023));
  delay(500);
  buttonLeftRead=digitalRead(buttonLeft);  }  //push buttt=on control of the claw

  if (digitalRead(buttonR) == 1) {
    ClawPos += ClawIncrease;
    delay(50);
  }
  if (digitalRead(buttonL) == 1) {
    ClawPos += ClawReduce;
    delay(50);
  }
  clawServo.write(ClawPos);
  //joystick control of the arm/body
  int  cursorRightReadx = analogRead(potenRx);
  int cursorLeftReadx = analogRead(potenLx);
  int cursorLeftReady = analogRead(potenLy);
  delay(100);
  rightServo.write(map(cursorRightReadx, 10, 178, 0, 1023));
  leftServo.write(map(cursorLeftReadx, 26, 176, 0, 1023));
delay(50);
}
