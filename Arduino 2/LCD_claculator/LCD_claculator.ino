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
lcd.print("CALCULATOR");
delay(dt);
lcd.clear();
lcd.print("Input The Number");
while(Serial.available()==0){
 
}
num1 = Serial.parseFloat();
lcd.clear();
lcd.print("Input the Operation");
lcd.setCursor(0,1);
lcd.print("Symbol +,-,*,/");
while(Serial.available()==0){  
}
symbol = Serial.readString();
lcd.clear();
lcd.print("Input 2nd Number");
while(Serial.available()==0){  
}
num2 = Serial.parseFloat();
if(symbol == "+") {
 answer = num1 + num2; }
 if(symbol == "-") {
 answer = num1 - num2; }
 if(symbol == "*") {
 answer = num1 * num2; }
 if(symbol == "/") {
 answer = num1 / num2; }
 ans = answer;
lcd.clear();
lcd.setCursor(0,0);
lcd.print("The Answer is");
lcd.setCursor(0,1);
lcd.print(num1);
lcd.print( symbol);
lcd.print(num2);
lcd.print("=");
lcd.print(answer);
delay(3000);
lcd.clear();
}
