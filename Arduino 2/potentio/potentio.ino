int V2 = A5;
int RED = 12;
int YELLOW = 8;
int GREEN = 5;
int WHITE = 3;
float volt;
float readval;
int dt = 500;
void setup() {
  // put your setup code here, to run once:
pinMode(V2,INPUT);
pinMode(RED,OUTPUT);
pinMode(YELLOW,OUTPUT);
pinMode(GREEN,OUTPUT);
pinMode(WHITE,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  readval = analogRead(V2);
  volt = (5./1023.)*readval;

  Serial.print(V2);
  Serial.print("The current volt is ");
  Serial.println(volt);
  delay(dt);
  if (volt>2.5 && volt<4){
    digitalWrite(YELLOW,1);
    digitalWrite(GREEN,0);
    digitalWrite(RED,0);
  }
  if (volt<2.5){
    digitalWrite(GREEN,1);
    digitalWrite(YELLOW,0);
    digitalWrite(RED,0);
    }
      if (volt>4){
    digitalWrite(GREEN,0);
    digitalWrite(YELLOW,0);
    digitalWrite(RED,1);
    }
    analogWrite(WHITE,volt);
}
