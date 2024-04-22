#include<LiquidCrystal.h>
int rs=2;
int en =3;
int d4 =4;
int d5 =5;
int d6 =6;
int d7 =7;
int ans;
int dt =1000;
float num1;
float num2;
String symbol;
float answer;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);
void setup() {
  // put your setup code here, to run once:
lcd.begin(16,2);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
lcd.setCursor(0,0);
lcd.print("YOUR WELCOME");
lcd.setCursor(0,1);
lcd.print("TO SCHOOL");
delay(dt);
lcd.clear();
lcd.print("BE PATIENT");