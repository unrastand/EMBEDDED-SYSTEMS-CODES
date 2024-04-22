int val;
int led1 = 7;
int mPhone = A0;
int buzzer = 8;
int th = 800; //threshold
void setup() {
  // Void setup is ran only once after each powerup or reset of the Arduino board.

  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(mPhone, INPUT);
}

void loop() {
  // Void loop is ran over and over and consists of the main program.

  val = analogRead(mPhone);
  Serial.println(val);
  if (val > th) {
    digitalWrite(led1, 1);
    digitalWrite(buzzer,1);
    delay(5000);
  }
  else{
    digitalWrite(led1, 0);
    digitalWrite(buzzer,0);
  }
 
}
