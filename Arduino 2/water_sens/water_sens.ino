
int led1 = 8;
int led2 = 9;
int sensorPin = 6;
int buzzPin = 7;
int val = 0;
int vals;
int sense = A5;
void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(buzzPin, OUTPUT);
  pinMode(sense, INPUT);
  Serial.begin(9600);
}

void loop() {
  val = analogRead(sensorPin);
  
  Serial.print(vals);
  Serial.print("  ");
  Serial.print(analogRead(a));
  Serial.print("  ");
  Serial.println(val);
  // when the sensor detects a signal above the threshold value, LED flashes
  if (val == 300) {
    digitalWrite(led1, HIGH);
  } else {
    digitalWrite(led1, LOW);
  }
  if (vals > 500) {
    digitalWrite(buzzPin, 1);
    digitalWrite(led2, 1);
    delay(500);
  } else {
    digitalWrite(buzzPin, 0);
    digitalWrite(led2, LOW);
  }
  analogWrite(sensorPin, 0);
}
