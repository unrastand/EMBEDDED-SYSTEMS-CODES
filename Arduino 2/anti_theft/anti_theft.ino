
int state = LOW;
int val;
int led1 = 7;
int buzzer = 4;
int motionSensorPin = 8;
int Irsense = 2
void setup() {
  // Void setup is ran only once after each powerup or reset of the Arduino board.

  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(motionSensorPin, INPUT);
  pinMode(Irsense, INPUT);
}

void loop() {
  // Void loop is ran over and over and consists of the main program.

  val = digitalRead(motionSensorPin);
  state = digitalRead(Irsense);
  Serial.println(val);
  if (val == 1) {
    digitalWrite(buzz, 1);
    state = val;
    Serial.println("go back area for goods only");
    
  }

  if (state == 1) {
    // if person does not go back another sensor senses presence
    Serial.println("lockdown initiated");
    digitalWrite(buzz, 1);
     
  }
  else{
    Serial.println("Thank you");
    digitalWrite(buzz, 0);
  }
}
