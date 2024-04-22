/*
 * 
 * All the resources for this project: http://randomnerdtutorials.com/
 * Modified by Rui Santos
 * 
 * Created by FILIPEFLOP
 * 
 */


// CONNECTIONS:
// DS1302 CLK/SCLK --> 5
// DS1302 DAT/IO --> 4
// DS1302 RST/CE --> 2
// DS1302 VCC --> 3.3v - 5v
// DS1302 GND --> GND

#include <RtcDS1302.h>

ThreeWire myWire(4, 5, 2);  // IO, SCLK, CE
RtcDS1302<ThreeWire> Rtc(myWire);

#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 instance.
int go = 7;
int stop = A0;
int dt = 100;
string storage_name[] = {};
void setup() {
  Serial.begin(57600);
  Serial.print("compiled: ");
  Serial.print(__DATE__);
  Serial.println(__TIME__);

  Rtc.Begin();

  RtcDateTime compiled = RtcDateTime(__DATE__, __TIME__);
  printDateTime(compiled);
  Serial.println();

  
  if (!Rtc.IsDateTimeValid()) {
    // Common Causes:
    //    1) first time you ran and the device wasn't running yet
    //    2) the battery on the device is low or even missing

    Serial.println("RTC lost confidence in the DateTime!");
    Rtc.SetDateTime(compiled);
  }

  if (Rtc.GetIsWriteProtected()) {
    Serial.println("RTC was write protected, enabling writing now");
    Rtc.SetIsWriteProtected(false);
  }

  if (!Rtc.GetIsRunning()) {
    Serial.println("RTC was not actively running, starting now");
    Rtc.SetIsRunning(true);
  }

  RtcDateTime now = Rtc.GetDateTime();
  if (now < compiled) {
    Serial.println("RTC is older than compile time!  (Updating DateTime)");
    Rtc.SetDateTime(compiled);
  } else if (now > compiled) {
    Serial.println("RTC is newer than compile time. (this is expected)");
  } else if (now == compiled) {
    Serial.println("RTC is the same as compile time! (not expected but all is fine)");
  }


  pinMode(go, OUTPUT);
  pinMode(stop, OUTPUT);
  //Serial.begin(9600);   // Initiate a serial communication
  SPI.begin();         // Initiate  SPI bus
  mfrc522.PCD_Init();  // Initiate MFRC522
  Serial.println("Approximate your card to the reader...");
  Serial.println();
}
void loop() {

  RtcDateTime now = Rtc.GetDateTime();
  printDateTime(now);
  Serial.println();

  if (!now.IsValid()) {
    // Common Causes:
    //    1) the battery on the device is low or even missing and the power line was disconnected
    Serial.println("RTC lost confidence in the DateTime!");
  }


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
   if (content.substring(1) == "BD 31 15 2B")  //change here the UID of the card/cards that you want to give access
  {
    Serial.println("Authorized access");
    Serial.println(" ");
    delay(dt);
  }
   else if (content.substring(1) == "73 9E E5 11") {
     String name= "David";
     storage[0] = {name};
    Serial.println("You clocked in at ");
    printDateTime(now);
    Serial.println();
      digitalWrite(go, 1);
    delay(dt);
    digitalWrite(go, 0);
    delay(dt);
    digitalWrite(go, 1);
    delay(dt);
    digitalWrite(go, 0);
    
      
    if(name == storage_name[0] ){
      Serial.println("Already Present");
        
    }
     
    delay(dt);
    while(!mfrc522.PICC_IsNewCardPresent()){
      
    }  } else {
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


#define countof(a) (sizeof(a) / sizeof(a[0]))

void printDateTime(const RtcDateTime& dt) {
  char datestring[20];

  snprintf_P(datestring,
             countof(datestring),
             PSTR("%02u/%02u/%04u %02u:%02u:%02u"),
             dt.Month(),
             dt.Day(),
             dt.Year(),
             dt.Hour(),
             dt.Minute(),
             dt.Second());
  Serial.print(datestring);
  String now = datestring;
  // attendance checking
  //if (now == "04/18/2023 18:}44:45") {
  //  Serial.println("YES WORKING");
  }
   
} 