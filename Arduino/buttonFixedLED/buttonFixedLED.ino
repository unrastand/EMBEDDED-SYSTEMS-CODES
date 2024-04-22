int butPin = 8;
int oldval = 0;
int newval;
int dt = 200;
int led = 7;
int a = 0;
void setup() {
  pinMode(butPin,INPUT);
  pinMode(led,OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
 newval = digitalRead(butPin);
 if(newval==0 && oldval == 1){
   if(a ==1){
   digitalWrite(led,0);
   a=0;
 }
 else{
   digitalWrite(led,1);
   a =1;
 }
 }
 oldval=newval;
 delay(dt);
}
