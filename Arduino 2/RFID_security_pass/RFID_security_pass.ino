
#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 instance.
int go = 7;
int stop = A0;
int dt = 100;
void setup() {
  Serial.begin(57600);
  pinMode(go, OUTPUT);
  pinMode(stop, OUTPUT);
  //Serial.begin(9600);   // Initiate a serial communication
  SPI.begin();         // Initiate  SPI bus
  mfrc522.PCD_Init();  // Initiate MFRC522
  Serial.println("Approximate your card to the reader...");
  Serial.println();
}
void loop() {

  // Look for new cards
  if (!mfrc522.PICC_IsNewCardPresent()) {
    return;
  }
  // Select one of the cards
  if (!mfrc522.PICC_ReadCardSerial()) {
    return;
  }
  //Show UID on serial monitor
  Serial.print("UID tag :");
  String content = "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(mfrc522.uid.uidByte[i], HEX);
    content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
    content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Message : ");
  content.toUpperCase();
  if (content.substring(1) == "BD 31 15 2B") {
    //change here the UID of the card/cards that you want to give access

    Serial.println("Authorized access");
    Serial.println(" ");
    delay(dt);
  } else if (content.substring(1) == "73 9E E5 11") {
    Serial.println("Authorized access");
    digitalWrite(go, 1);
    delay(dt);
    digitalWrite(go, 0);
    delay(dt);
    digitalWrite(go, 1);
    delay(dt);
    digitalWrite(go, 0);
  } else {
    Serial.println(" Access denied, new card or not recognised");
    delay(3000);
    analogWrite(stop, 500);
    delay(dt);
    analogWrite(stop, 0);
    delay(dt);
    analogWrite(stop, 500);
    delay(dt);
    analogWrite(stop, 0);
    delay(dt);
  }

  //delay(10000);  // ten seconds
}
