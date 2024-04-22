int x = A0;
float t;
int a;
int dt= 500;
int red = 6;
int green = 7;
int yellow = 5;
int sound = 8;
void setup() {
  // put your setup code here, to run once:
pinMode(red,OUTPUT);
pinMode(yellow,OUTPUT);
pinMode(green,OUTPUT);
pinMode(sound,OUTPUT);

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

if(a<300)
{
  digitalWrite(red,1);
  digitalWrite(sound,1);
  digitalWrite(yellow,0);
  digitalWrite(green,0);
}

else if(a>300 && a<1000)
{
  digitalWrite(red,0);
  digitalWrite(sound,0);
  digitalWrite(yellow,1);
  digitalWrite(green,0);
}

else if(a>1000)
{
  digitalWrite(red,0);
  digitalWrite(sound,1);
  digitalWrite(yellow,0);
  digitalWrite(green,1);
}
}
