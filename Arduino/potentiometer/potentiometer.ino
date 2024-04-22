int x = A0;
float t;
int a;
int dt= 500;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(x,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
a= analogRead(x);
Serial.print(a);
t= ((5./1023.)*a);
Serial.print("   ");
Serial.println(t);
delay(dt);
}
