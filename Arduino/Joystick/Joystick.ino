int potX=A0;
int potY = A1;
int potZ=A2;
int dt=100;

int xVal=0;
int yVal=0;
int zVal=0;
void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
pinMode(potX,INPUT);
pinMode(potY,INPUT);
pinMode(potZ,INPUT);
digitalWrite(potZ,HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
xVal=analogRead(potX);
yVal=analogRead(potY);
zVal=analogRead(potZ);
Serial.print(xVal);
Serial.print(',');
Serial.print(yVal);
Serial.print(',');
Serial.print(zVal);
delay(25);
}
