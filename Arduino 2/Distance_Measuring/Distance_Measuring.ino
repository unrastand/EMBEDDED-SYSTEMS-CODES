int tPin = 12;
int echoPin = 11;
int pTravelT;
int dt = 500;
float seconds;
float distance;
void setup() {
  // put your setup code here, to run once:
  pinMode(tPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  digitalWrite(echoPin, 0);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(tPin, 0);
  delayMicroseconds(10);
  digitalWrite(tPin, 1);
  delayMicroseconds(10);
  digitalWrite(tPin, 0);
  pTravelT = pulseIn(echoPin, 1);
  seconds = (pTravelT / 2.);
  distance = (seconds * 765. * 5280. * 12. * 2.54) / (3600. * 1000000.);
  delay(250);
  Serial.print(3);
  Serial.print(",");
  Serial.print(distance);
  Serial.println(" cm  ");

}
