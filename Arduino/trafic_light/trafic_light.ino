int red = 6;
int green = 7;
int yellow = 5;
int delayr = 3000;
int delayg = 5000;
int delayy = 2000;
void setup() {
  // put your setup code here, to run once:
pinMode(red,OUTPUT);
pinMode(green,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
    digitalWrite(red,1);
    delay(delayr);
    digitalWrite(red,0);
    digitalWrite(yellow,1);
    delay(delayy);
    digitalWrite(yellow,0);
    digitalWrite(green,1);
    delay(delayg);
    digitalWrite(green,0);
    digitalWrite(yellow,1);
    delay(delayy);
    digitalWrite(yellow,0);
     
    

}
