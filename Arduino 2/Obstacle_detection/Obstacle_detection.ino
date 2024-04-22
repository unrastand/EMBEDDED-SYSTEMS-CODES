int tPin = 12;
int echoPin = 11;
int pTravelT;
int dt = 500;
float seconds;
float distance;
int distanceToTargetInCm = 45; //change the value based on you
void setup() {
  // put your setup code here, to run once:

}
void distant() {
  digitalWrite(tPin, 0);
  delayMicroseconds(10);
  digitalWrite(tPin, 1);
  delayMicroseconds(10);
  digitalWrite(tPin, 0);
  pTravelT = pulseIn(ePin, 1);  
  seconds = (pTravelT / 2.);
  distance = (seconds * 765. * 5280. * 12. * 2.54) / (3600. * 1000000.);
  delay(250);
  Serial.print(3);
  Serial.print(",");
  Serial.print(distance);
  Serial.println(" cm  ");
 
}
void loop() {
  // put your main code here, to run repeatedly:
  if(distanceToTargetInCm<= distance){
    Serial.println("Caution");
    digitalWrite(red,1);
     digitalWrite(green,0);
  }
  else{
    digitalWrite(red,0);
    digitalWrite(green,1);
  }
}
