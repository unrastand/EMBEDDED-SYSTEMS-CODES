int l=A0;
int r=A1;
void setup() {
  // put your setup code here, to run once:
pinMode(l,OUTPUT);
pinMode(r,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
analogWrite(l,600);
analogWrite(r,0);
}
