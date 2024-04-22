const int butin = 5;
const int butde = 6;
const int led = 7;


int buti,butd, dim_value;
void setup() {
  pinMode(butin,INPUT);
  pinMode(butde,INPUT);
  pinMode(led,OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
 buti = digitalRead(butin);
 butd = digitalRead(butde);
 if(butin == HIGH){
   if(dim_value > 225){
     dim_value = dim_value;
   }
   else{
     dim_value += 25;
     delay(300);
   }
 }
  if(butde == HIGH){
   if(dim_value < 25){
     dim_value = dim_value;
   }
   else{
     dim_value -= 25;
     delay(300);
   }
 }
 Serial.println(dim_value);
 analogWrite(led, dim_value);
}
