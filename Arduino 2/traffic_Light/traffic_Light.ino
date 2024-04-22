int red = 13;
int yellow = 12;
int green = 11;
int greenp = 9;
int passive = 10;
int dtr = 5000;
int dtg = 7000;
int dty = 3000;
int dtc = 5000;
int cross;
void setup() {
  // put your setup code here, to run once:
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(greenp, OUTPUT);
  pinMode(passive, INPUT);
}

void wait() {
  int move = 1;
  for (int i = 0; i < 50; i++) {
    cross = digitalRead(passive);
    if (cross == 1 && move == 1) {
      digitalWrite(red, 1);
      digitalWrite(greenp, 1);
      move = 0;
      delay(dtc);
    } else if (move == 0) {
      digitalWrite(green, 1);
      digitalWrite(greenp, 0);
    }
    delay(1000);
  }
}
void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(red, 1);
  delay(dtr);
  digitalWrite(red, 0);  
  digitalWrite(yellow, 1);
  delay(dty);
  digitalWrite(yellow, 0);  
  digitalWrite(green, 1);
  wait();
  digitalWrite(green, 0);
  
}
