 #include <Servo.h>
#include <LiquidCrystal_I2C.h>
#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define buzzer 2
#define RST_PIN 9

int redLEDPin = 4;
int greenLEDPin = 5;
int door_about_to_close=1000;

String UID = "";
String data[4]={"C0 66 87 32", "C6 9D 9C 2B", "D0 9C F7 32", "C6 1A 11 2B"};
byte lock = 0;

Servo servo;
LiquidCrystal_I2C lcd(0x27, 16, 2);
MFRC522 rfid(SS_PIN, RST_PIN);


void setup() {
  Serial.begin(9600);
  pinMode(buzzer,OUTPUT);
  servo.write(0);
  lcd.init();
  lcd.backlight();
  servo.attach(3);
  SPI.begin();
  rfid.PCD_Init();
  pinMode(redLEDPin, OUTPUT);    
  pinMode(greenLEDPin, OUTPUT);

}

void loop() {
  lcd.setCursor(4, 0);
  lcd.print("Welcome!");
  lcd.setCursor(1, 1);
  lcd.print("Put your card");

  if ( ! rfid.PICC_IsNewCardPresent())
    return;
  if ( ! rfid.PICC_ReadCardSerial())
    return;

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Scanning");
  Serial.print("NUID tag is :");
  String ID = "";
  for (byte i = 0; i < rfid.uid.size; i++) {
    lcd.print(".");
    ID.concat(String(rfid.uid.uidByte[i] < 0x10 ? " 0" : " "));
    ID.concat(String(rfid.uid.uidByte[i], HEX));
    delay(300);
  }
  ID.toUpperCase();

  if (ID.substring(1) == data[0] && lock == 0 ) {
    servo.write(0);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Goodbye Duba");
    lcd.setCursor(0, 1);
    lcd.print("Door is locked");
    digitalWrite(greenLEDPin, HIGH);
    delay(2000);
    digitalWrite(greenLEDPin, LOW);
    lcd.clear();
    lock = 1;
   }
   else if (ID.substring(1) == data[0] && lock == 1 ) {
    servo.write(180);
    lcd.clear();
    lcd.setCursor(0, 0);
     lcd.print("Welcome Duba");
      lcd.setCursor(0, 1);
    lcd.print("Door is open");
    digitalWrite(buzzer, HIGH);
    delay(300);
    digitalWrite(buzzer, LOW);
    digitalWrite(greenLEDPin, HIGH);
    delay(2000);
    digitalWrite(greenLEDPin, LOW);
    lcd.clear();
    lcd.setCursor(0, 0);
     lcd.print("Door closing in:");
    digitalWrite(buzzer, HIGH);
    delay(300);
    digitalWrite(buzzer, LOW);
    lcd.clear();
    lock = 0;
   }
   else if (ID.substring(1) == data[1] && lock == 0 ) {
    servo.write(0);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Goodbye Caleb");
    lcd.setCursor(0, 1);
    lcd.print("Door is locked");
    digitalWrite(buzzer, HIGH);
    delay(300);
    digitalWrite(buzzer, LOW);
    digitalWrite(greenLEDPin, HIGH);
    delay(200);
    digitalWrite(greenLEDPin, LOW);
    delay(1500);
    lcd.clear();
    lock = 1;
   }
   else if (ID.substring(1) == data[1] && lock == 1 ) {
    servo.write(180);
    lcd.clear();
    lcd.setCursor(0, 0);
     lcd.print("Welcome Caleb");
      lcd.setCursor(0, 1);
    lcd.print("Door is open");
    digitalWrite(buzzer, HIGH);
    delay(300);
    digitalWrite(buzzer, LOW);
    digitalWrite(greenLEDPin, HIGH);
    delay(2000);
    digitalWrite(greenLEDPin, LOW);
    lcd.clear();
    lcd.setCursor(0, 0);
     lcd.print("Door closing in:");
     lcd.setCursor(7, 1);
    lcd.print("5");
    delay(door_about_to_close);
    lcd.setCursor(7, 1);
    lcd.print("4");
     delay(door_about_to_close);
    lcd.setCursor(7, 1);
    lcd.print("3");
     delay(door_about_to_close);
    lcd.setCursor(7, 1);
    lcd.print("2");
     delay(door_about_to_close);
    lcd.setCursor(7, 1);
    lcd.print("1");
     delay(door_about_to_close);
    servo.write(0);
    digitalWrite(buzzer, HIGH);
    delay(300);
    digitalWrite(buzzer, LOW);
    lcd.clear();
    lock = 0;
   }
     else if (ID.substring(1) == data[2] && lock == 0 ) {
    servo.write(0);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Goodbye Zion");
    lcd.setCursor(0, 1);
    lcd.print("Door is locked");
    digitalWrite(buzzer, HIGH);
    delay(300);
    digitalWrite(buzzer, LOW);
    digitalWrite(greenLEDPin, HIGH);
    delay(200);
    digitalWrite(greenLEDPin, LOW);
    delay(1500);
    lcd.clear();
    lock = 1;
   }
   else if (ID.substring(1) == data[2] && lock == 1 ) {
    servo.write(180);
    lcd.clear();
    lcd.setCursor(0, 0);
     lcd.print("Welcome Zion");
      lcd.setCursor(0, 1);
    lcd.print("Door is open");
    digitalWrite(buzzer, HIGH);
    delay(300);
    digitalWrite(buzzer, LOW);
    digitalWrite(greenLEDPin, HIGH);
    delay(2000);
    digitalWrite(greenLEDPin, LOW);
    lcd.clear();
    lcd.setCursor(0, 0);
     lcd.print("Door closing in:");
     lcd.setCursor(7, 1);
    lcd.print("5");
    delay(door_about_to_close);
    lcd.setCursor(7, 1);
    lcd.print("4");
     delay(door_about_to_close);
    lcd.setCursor(7, 1);
    lcd.print("3");
     delay(door_about_to_close);
    lcd.setCursor(7, 1);
    lcd.print("2");
     delay(door_about_to_close);
    lcd.setCursor(7, 1);
    lcd.print("1");
     delay(door_about_to_close);
    servo.write(0);
    digitalWrite(buzzer, HIGH);
    delay(300);
    digitalWrite(buzzer, LOW);
    lcd.clear();
    lock = 0;
   }
    else  if (ID.substring(1) == data[3] && lock == 0 ) {
    servo.write(0);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Goodbye Mckay");
    lcd.setCursor(0, 1);
    lcd.print("Door is locked");
    digitalWrite(buzzer, HIGH);
    delay(300);
    digitalWrite(buzzer, LOW);
    digitalWrite(greenLEDPin, HIGH);
    delay(200);
    digitalWrite(greenLEDPin, LOW);
    delay(1500);
    lcd.clear();
    lock = 1;
   }
   else if (ID.substring(1) == data[3] && lock == 1 ) {
    servo.write(180);
    lcd.clear();
    lcd.setCursor(0, 0);
     lcd.print("Welcome Mckay");
      lcd.setCursor(0, 1);
    lcd.print("Door is open");
    digitalWrite(buzzer, HIGH);
    delay(200);
    digitalWrite(buzzer, LOW);
    digitalWrite(greenLEDPin, HIGH);
    delay(2000);
    digitalWrite(greenLEDPin, LOW);
    lcd.clear();
    lcd.setCursor(0, 0);
     lcd.print("Door closing in:");
     lcd.setCursor(7, 1);
    lcd.print("5");
    delay(door_about_to_close);
    lcd.setCursor(7, 1);
    lcd.print("4");
     delay(door_about_to_close);
    lcd.setCursor(7, 1);
    lcd.print("3");
     delay(door_about_to_close);
    lcd.setCursor(7, 1);
    lcd.print("2");
     delay(door_about_to_close);
    lcd.setCursor(7, 1);
    lcd.print("1");
     delay(door_about_to_close);
    servo.write(0);
    digitalWrite(buzzer, HIGH);
    delay(300);
    digitalWrite(buzzer, LOW);
    lcd.clear();
    lock = 0;
   }
   else{
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Wrong card!");
    digitalWrite(redLEDPin, HIGH);
        digitalWrite(buzzer, HIGH);
    delay(200);
    digitalWrite(buzzer, LOW);
    delay(200);
    digitalWrite(buzzer, HIGH);
    delay(200);
    digitalWrite(buzzer, LOW);
    delay(200);
    digitalWrite(buzzer, HIGH);
    delay(200);
    digitalWrite(buzzer, LOW);
    delay(200);
    digitalWrite(redLEDPin, LOW);
    delay(1500);
    

    lcd.clear();
    
  }
}