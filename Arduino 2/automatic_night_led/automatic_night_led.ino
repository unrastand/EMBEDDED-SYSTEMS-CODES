
int photo = A4;
int led = 6;
int data;
void setup() {
  // put your setup code here, to run once:
pinMode(led,OUTPUT);
pinMode(photo,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  data = analogRead(photo);
 if(data < 400){
   digitalWrite(led,1);
 }
 else{
   digitalWrite(led,0);
 }
 }
}
