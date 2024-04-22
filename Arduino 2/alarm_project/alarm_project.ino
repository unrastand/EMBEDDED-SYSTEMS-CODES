/*
 * 
 * part of the resources for this project: http://randomnerdtutorials.com/

 * 
 */

#include <RtcDS1302.h>

ThreeWire myWire(4, 5, 2);  // IO, SCLK, CE
RtcDS1302<ThreeWire> Rtc(myWire);
int dt = 100;
int dt1 = 2000;
int buzz = 9;
String alarmtime = "18:44:45";  //change to set alarm time
void setup() {
  // put your setup code here, to run once:
  pimMode(buzz,OUTPUT);
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


  
  //Serial.begin(9600);   // Initiate a serial communication
}
#define countof(a) (sizeof(a) / sizeof(a[0]))


void buzzSound() {
  digitalWrite(buzz, 1);
  delay(5000);
  digitalWrite(buzz, 0);
  delay(dt1);
  digitalWrite(buzz, 1);
  delay(dt1);
  digitalWrite(buzz, 0);
  delay(dt1);
  digitalWrite(buzz, 1);
  delay(10000);
  digitalWrite(buzz, 0);
}
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
  // time checking
  int timeindex = 11;
  String found = now.substring(timeindex);
  if (found == alarmtime) {
    buzzSound();
  }


  void loop() {
    // put your main code here, to run repeatedly:

    RtcDateTime now = Rtc.GetDateTime();
    printDateTime(now);
    Serial.println();

    if (!now.IsValid()) {
      // Common Causes:
      //    1) the battery on the device is low or even missing and the power line was disconnected
      Serial.println("RTC lost confidence in the DateTime!");
    }
    printDateTime(now);
  }
