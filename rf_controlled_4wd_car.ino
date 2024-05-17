#include <IBusBM.h>

IBusBM ibusRc;

HardwareSerial& ibusRcSerial = Serial1;
HardwareSerial& debugSerial = Serial;

// Define motor control pins for Motor A
const int motorA1 = 7; // IN1 on L298N
const int motorA2 = 8; // IN2 on L298N
const int enableA = 9; // ENA on L298N (connected to a PWM-capable pin)

// Define motor control pins for Motor B
const int motorB1 = 10; // IN3 on L298N
const int motorB2 = 11; // IN4 on L298N
const int enableB = 12; // ENB on L298N (connected to a PWM-capable pin)

int ch1 = 0; // Left and right control for Motor A
int ch2 = 0; // Forward and backward control for Motor A
int ch3 = 0; // Speed control for Motor A
int ch4 = 0; // Left and right control for Motor B
int ch5 = 0; // Forward and backward control for Motor B
int ch6 = 0; // Speed control for Motor B
int directionA=0;
int directionB=0;
// Function to set motor speed (0-255) and direction (1 for forward, 0 for reverse)
void setMotor(int speed, int backward, int motorPin1, int motorPin2, int enablePin) {
  analogWrite(enablePin, speed); // Set speed (0-255)
  if (backward == 1) {
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
  } else if(backward == 2){
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, HIGH);
  }
  else if(backward ==0){
     digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
  }
    else if(backward ==-1){
     digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, 1);
    digitalWrite(motorPin1, 0);
    digitalWrite(motorPin2, 1);
  }
  backward = 4;
}

void setup() {
  // Initialize debug and iBus communication
  debugSerial.begin(74880);
  ibusRc.begin(ibusRcSerial);

  // Initialize motor control pins for Motor A
  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(enableA, OUTPUT);

  // Initialize motor control pins for Motor B
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);
  pinMode(enableB, OUTPUT); 

  delay(2000); // wait for receiver to activate
}

// Read the number of a given channel and convert to the range provided.
// If the channel is off, return the default value
int readChannel(byte channelInput, int minLimit, int maxLimit, int defaultValue) {
  uint16_t ch = ibusRc.readChannel(channelInput);
  if (ch < 100) return defaultValue;
  return map(ch, 1000, 2000, minLimit, maxLimit);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (byte i = 0; i < 5; i++) {
    int value = readChannel(i, -100, 100, 0);
    // Assign channel values to respective variables
    if (i == 0) {
      ch1 = value;
    }
    if (i == 1) {
      ch2 = value;
    }
    if (i == 2) {
      ch3 = value;
    }
    if (i == 3) {
      ch4 = value;
    }
    if (i == 4) {
      ch5 = value;
    } 
  }
  debugSerial.println();

  // Determine motor A speed and direction based on channel values
  int motorSpeed = map(abs(ch3), 0, 100, 0, 255);
  if(ch2>40){ directionA = 1;}
  if(ch2>40){ directionB = 2;}
  if(ch2<-40){ directionA = 2;}
  if(ch2<-40){ directionB= 1;}

 if(ch1>40){ directionA = 0;}
  if(ch1>40){ directionB = 0;}
  if(ch1<-40){ directionA =-1;}
  if(ch1<-40){ directionB= -1;}
  setMotor(motorSpeed, directionA, motorA1, motorA2, enableA);  
  setMotor(motorSpeed, directionB, motorB1, motorB2, enableB);
 directionA = 3;
 directionB =4; 
}
