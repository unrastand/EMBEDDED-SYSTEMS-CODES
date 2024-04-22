int led1=13;
int led2 = 12;
int led3 = 11;
int dt=100;
void setup() {
  // put your setup code here, to run once:
pinMode(led1,OUTPUT);
pinMode(led2,OUTPUT);
pinMode(led3,OUTPUT);
}
void blink(int led){
  digitalWrite(led,1);
  delay(dt);
  digitalWrite(led,0);
  delay(dt);
  digitalWrite(led,1);
  delay(dt);
  digitalWrite(led,0);
  delay(dt);
  digitalWrite(led,1);
  delay(dt);
  digitalWrite(led,0);
}
void loop() {
  // put your main code here, to run repeatedly:
blink(led1);
blink(led2);
blink(led3);

}
