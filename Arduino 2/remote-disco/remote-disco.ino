#include <IRremote.h>
int IRpin = 10;
IRrecv IR(IRpin);
decode_results data;
byte value;
int r1 = A0;
int r2 = A1;
int r3 = A2;
int g1 = A3;
int g2 = A4;
int g3 = A5;
int b1 = 3;
int b2 = 5;
int b3 = 6;
int color1 = 100;
int color2 = 100;
int dt = 500;
int level;
 void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(r1, OUTPUT);
  pinMode(r2, OUTPUT);
  pinMode(r3, OUTPUT);
  pinMode(b1, OUTPUT);
  pinMode(b2, OUTPUT);
  pinMode(b3, OUTPUT);
  pinMode(g1, OUTPUT);
  pinMode(g2, OUTPUT);
  pinMode(g3, OUTPUT);
  IR.enableIRIn();
}
void randomled() {
  if (!(color1 > 900)) {
    color1 *= 2;
    color1 - 5;

  } else if (level == 0 && color1 > 900) {
    level = 1;
  } else if (level == 1 && !(color1 < 200)) {
    color1 /= 2;
  }
  else if(level ==1 && color1<200 ){
    level =0;
  }
}
void lightup() {
  analogWrite(r1, (15 + color1));
  analogWrite(r2, (20 + color1));
  analogWrite(r3, (25 + color1));
  analogWrite(g1, (5 + color1));
  analogWrite(g2, (10 + color1));
  analogWrite(g3, (15 + color1));
  analogWrite(b1, (5 + color2));
  analogWrite(b2, (10 + color2));
  analogWrite(b3, (15 + color2));
}
void loop() {
  // put your main code here, to run repeatedly:
  while (IR.decode(&data) == 0) {
    randomled();
    lightup();
  }
  Serial.println(data.value, HEX);
  delay(dt);
  if (data.value == 0xFF30CF) {
    dt -= 100;
  }
  if (data.value == 0xFF10EF) {
    dt += 100;
  }
  if (data.value == 0xFF18E7) {
    color1 += 20;
  }
  if (data.value == 0xFF38C7) {
    color1 -= 20;
  }
  if (data.value == 0xFF7A85) {
    color2 += 20;
  }
  if (data.value == 0xFF5AA5) {
    color2 -= 20;
  }
  int color[255] = { 0255 };

  for (int i = 0; i < 255; i++) {
    Serial.println(color[i]);
    delay(dt);
  }
}
