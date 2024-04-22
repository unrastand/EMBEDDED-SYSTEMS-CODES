int potval;
float volt;
int led = 7;
int poten = A5;
int dt=500;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(poten,INPUT);
pinMode(led,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  potval = analogRead(poten);
  volt = (5./1023.)*potval;
  Serial.println(volt);
  if(potVal>900){
    potVal =900;
  }
  analogWrite(potVal);
  // delay(dt);
  // while (volt>3.5){
  //   digitalWrite(led,1);
  //   potval = analogRead(poten);
  // volt = (5./1023.)*potval;
  // Serial.println(volt);
  // delay(dt);}
  // digitalWrite(led,0);
//for (j=10;j>=1;j-=1){
//  Serial.println(j);
//  delay(dt);}
}
