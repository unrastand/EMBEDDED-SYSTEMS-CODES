int red = 6;
int yellow = 7;
int green = 8;
int led1 = 9;
int led2 = 10;
int led3 = 11;
int delayr = 1000;
int delayy = 1000;
int delayg = 1000;
int delayl1 = 1000;
int delayl2 = 1000;
int delayl3 = 1000;
void setup() {
  // put your setup code here, to run once:
pinMode(red,OUTPUT);
pinMode(yellow,OUTPUT);
pinMode(green,OUTPUT);
pinMode(led1,OUTPUT);
pinMode(led2,OUTPUT);
pinMode(led3,OUTPUT);
}
void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(red,1);
delay(delayr);
digitalWrite(red,0);
digitalWrite(led1,1);
delay(delayg);
digitalWrite(led2,1);
delay(delayr);
digitalWrite(led1,0);
digitalWrite(led2,0);
digitalWrite(yellow,1);
delay(delayy);
digitalWrite(yellow,0);
digitalWrite(led1,1);
delay(delayg);
digitalWrite(yellow,1);
delay(delayr);
digitalWrite(led1,0);
digitalWrite(yellow,0);
digitalWrite(green,1);
delay(delayg);
digitalWrite(green,0);
digitalWrite(led1,1);
delay(delayg);
digitalWrite(led3,1);
delay(delayr);
digitalWrite(led1,0);
digitalWrite(led3,0);
digitalWrite(green,1);
delay(delayg);
digitalWrite(green,0);
digitalWrite(red,1);
delay(delayg);
digitalWrite(led3,1);
delay(delayr);
digitalWrite(red,0);
digitalWrite(led3,0);
digitalWrite(yellow,1);
delay(delayy);
digitalWrite(green,1);
delay(delayg);
digitalWrite(yellow,0);
digitalWrite(green,0);
digitalWrite(red,1);
delay(delayr);
digitalWrite(red,0);
digitalWrite(green,1);
delay(delayg);
digitalWrite(green,0);
digitalWrite(yellow,1);
delay(delayy);
digitalWrite(yellow,0);
digitalWrite(red,1);
delay(delayr);
digitalWrite(red,0);
digitalWrite(led1,1);
delay(delayg);
digitalWrite(led3,1);
delay(delayr);
digitalWrite(led1,0);
digitalWrite(led3,0);
digitalWrite(yellow,1);
delay(delayy);
digitalWrite(yellow,0);
digitalWrite(green,1);
delay(delayg);
digitalWrite(green,0);
}
