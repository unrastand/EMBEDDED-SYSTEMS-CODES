int buzzer =9;
int buttonPin1 =5;
int buttonPin2 =3;
int LED =10;
int dt = 100;
int button1;
int button2;
int brightness;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(LED,OUTPUT);
pinMode(buttonPin1,INPUT);
pinMode(buttonPin2,INPUT);
pinMode(buzzer,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
button1 = digitalRead(buttonPin1);
button2 = digitalRead(buttonPin2);
if (button1==0){
  brightness+=5;
  }
if (button2==0){
   brightness-=5;
   }
 if (brightness>255){
   brightness=255;
   digitalWrite(buzzer,1);
   delay(dt);
   digitalWrite(buzzer,0);
   }
   if (brightness<0){
   brightness=0;
   digitalWrite(buzzer,1);
   delay(dt);
   digitalWrite(buzzer,0);
   }
 analogWrite(LED,brightness);
 
Serial.println(brightness);
delay(dt);
}
