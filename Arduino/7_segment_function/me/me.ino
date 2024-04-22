
void setup() {
  // put your setup code here, to run once:
for(int i=3;i<11;i++){
  pinMode(i,OUTPUT);
}
}
void dot(int a,int b,int c,int d,int e,int f,int g,int h){
 digitalWrite(3,a);
  digitalWrite(4,b);
  digitalWrite(5,c);
  digitalWrite(6,d);
  digitalWrite(7,e);
  digitalWrite(8,f);
  digitalWrite(9,g);
  digitalWrite(10,h);
}

void loop() {
  // put your main code here, to run repeatedly:
dot(1,1,1,1,1,1,0,0);
delay(1000);
dot(0,0,0,0,1,1,0,0);
delay(1000);
dot(1,1,0,1,1,0,1,0);
delay(1000);
dot(1,1,1,1,0,0,1,0);
delay(1000);
dot(0,1,1,0,0,1,1,0);
delay(1000);
dot(1,0,1,1,0,1,1,0);
delay(1000);
dot(1,0,1,1,1,1,1,0);
delay(1000);
dot(1,1,1,0,0,0,1,0);
delay(1000);
dot(1,1,1,1,1,1,1,0);
delay(1000);
dot(1,1,1,0,0,1,1,0);
delay(1000);}
