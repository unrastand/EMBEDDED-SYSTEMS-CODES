#define BLYNK_TEMPLATE_ID "TMPL4LSV6cfDs" //replace with yours
#define BLYNK_TEMPLATE_NAME "SMART GENERATOR"
#define BLYNK_AUTH_TOKEN "H4ct4c1_Y9Ch5SKa_2Sx8JOY2xHoqX06" //replace with yours
#define BLYNK_FIRMWARE_VERSION "1.2.0"

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
 
 
#define FUEL_LEVEL   V0
#define OIL_LEVEL    V1
#define TEMPERATURE  V2
#define RUNTIME      V3
#define CURRENT      V4

char ssid[] = "ENGINEER"; // change to the wifi your using 
char pass[] = "123456789"; // changed to the wifi password you are using  and please thw fif must be 2.4ghz band

BlynkTimer timer;
 
String pinstate;

bool connectedFlag = false;
 unsigned long startMillis;
 unsigned long currentMillis;
 const unsigned long period = 1000; 
void updateState(String state) {
  Blynk.virtualWrite(FUEL_LEVEL, state.substring(0, state.indexOf("f")));
  Blynk.virtualWrite(OIL_LEVEL, state.substring(state.indexOf("f") + 1, state.indexOf("o")));
  Blynk.virtualWrite(TEMPERATURE, state.substring(state.indexOf("o") + 1, state.indexOf("t")));
  Blynk.virtualWrite(RUNTIME, state.substring(state.indexOf("t") + 1, state.indexOf("r")));
  Blynk.virtualWrite(CURRENT, state.substring(state.indexOf("r") + 1, state.indexOf("c")));
}
  
 void  myTimer(){
     updateState(pinstate);
  }
void setup() {
  Serial.begin(9600);
  //setSyncInterval(1);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);  
  timer.setInterval(2000L,myTimer);
}

void loop() {
  while (Serial.available() > 0) {
    pinstate = Serial.readString();
    updateState(pinstate);
    connectedFlag = true;
  }
  if (connectedFlag) {
    Blynk.run();
    timer.run();
   
  }

}
