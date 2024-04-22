int tiltPin = 4;
int LEDG = 7;
int LEDR = 9;
int tiltVal;
int buzzer = 8;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(tiltPin,INPUT);
pinMode(LEDG,OUTPUT);
pinMode(LEDR,OUTPUT);
pinMode(buzzer,OUTPUT);
digitalWrite(tiltPin,HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
tiltVal = digitalRead(tiltPin);
Serial.println(tiltVal);
if(tiltVal==1){
  digitalWrite(LEDG,1);
  digitalWrite(buzzer,0);
  digitalWrite(LEDR,0);}
  else{
  digitalWrite(LEDR,1);
  digitalWrite(buzzer,1);
  digitalWrite(LEDG,0);}
}
