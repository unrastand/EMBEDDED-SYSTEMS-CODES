#include <SoftwareSerial.h>
SoftwareSerial me(2, 3); // TX | RX
String ComputerData;
String BluetoothData;
void setup() {
  // put your setup code here, to run once:
  me.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (me.available()) {
    BluetoothData = me.read();
    Serial.println(BluetoothData);
  }
  if (Serial.available()) {
    EEBlue.write(Serial.read());
    Serial.println(ComputerData);
  }
}
