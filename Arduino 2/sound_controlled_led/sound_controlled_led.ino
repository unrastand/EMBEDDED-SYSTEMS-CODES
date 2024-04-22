
int state = LOW;
int val;
int led1 = 7;
int mPhone = 6;

void setup() {
  // Void setup is ran only once after each powerup or reset of the Arduino board.

  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(mPhone, INPUT);
}

void loop() {
  // Void loop is ran over and over and consists of the main program.

  val = digitalRead(mPhone);
  state = digitalRead(led1);
  Serial.println(val);
  if (val == 1) {
    digitalWrite(led1, 1);
    state = val;
    delay(5000);
  }

  if (val == 1 && state == 1) {
    digitalWrite(led1, 0);
    state = 0;
  }
}
