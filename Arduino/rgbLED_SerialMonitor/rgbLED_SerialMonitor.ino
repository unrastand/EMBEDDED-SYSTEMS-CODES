int R = 9;
int G = 10;
int B = 11;
int Rval = 255;
int Gval = 255;
int Bval = 255;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(250000);
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  while (Serial.available() == 0){
}
       Rval = Serial.readStringUntil(':').toInt();
       Gval = Serial.readStringUntil(':').toInt();    
       Bval = Serial.readStringUntil('\e').toInt();

       analogWrite(R, Rval);
       analogWrite(G, Gval);
       analogWrite(B, Bval);

}
