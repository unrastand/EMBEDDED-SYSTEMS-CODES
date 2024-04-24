#include <SoftwareSerial.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);  // Set the I2C address (0x27) and specify 16 columns and 2 rows

#include <OneWire.h>
#include <DallasTemperature.h>

// Define the pin connected to the DS18B20 sensor
#define SENSOR_PIN 3

OneWire oneWire(SENSOR_PIN);           // Setup a OneWire instance
DallasTemperature tsensors(&oneWire);  // Pass OneWire to the DallasTemperature library


unsigned long startTime = 0;    // Variable to store the start time
unsigned long currenttIME = 0;  // Variable to store the currrent  time
unsigned long previoustIME = 0;
unsigned long duration = 0;         // Duration of the event in milliseconds
const unsigned int TRIG_PINF = 11;  //RX
const unsigned int ECHO_PINF = 10;

const unsigned int TRIG_PINO = 9;
const unsigned int ECHO_PINO = 8;
String pinStatus = "";

const int volt_pin = A0;
const int current_pin = A1;
const int oil_pin = A2;
int mVperAmp = 100;  // Use 185 for 5A Module, 100 for 20A Module, and 66 for 30A Module
int RawValue = 0;
int voltage;


int t1;
int f1;
int o1;
int r1;
int v1;
int c1;
 char sense ='f';
int present=0;
void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  lcd.init();        // Initialize the LCD
  lcd.backlight();   // Turn on the backlight
  tsensors.begin();  // Initialize the sensor
  pinMode(TRIG_PINF, OUTPUT);
  pinMode(ECHO_PINF, INPUT);
  pinMode(volt_pin, INPUT);
  pinMode(current_pin, INPUT);
  pinMode(oil_pin, INPUT);
}

float temp() {
  tsensors.requestTemperatures();                    // Request temperature reading
  float temperatureC = tsensors.getTempCByIndex(0);  // Get temperature in Celsius
  t1 = temperatureC;
  return temperatureC;
}

double currents() {

  RawValue = analogRead(current_pin);
  double voltage = RawValue * (5.0 / 1023.0);   // Convert analog value to voltage
  double current = (voltage - 2.5) / mVperAmp;  // Calculate current in amps (voltage - 2.5) *1000 / mVperAmp;  for miliamps
  c1 = current;
  return current;
}

int fuelReading() {
  digitalWrite(TRIG_PINF, LOW);
  delayMicroseconds(10);
  digitalWrite(TRIG_PINF, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PINF, LOW);

  const unsigned long duration = pulseIn(ECHO_PINF, HIGH);
  f1 = map((duration / 29 / 2), 16, 19, 0, 7);
  return f1;
  delay(100);
}
int oilReading() {
  digitalWrite(TRIG_PINO, LOW);
  delayMicroseconds(10);
  digitalWrite(TRIG_PINO, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PINO, LOW);

  const unsigned long duration = pulseIn(ECHO_PINO, HIGH);
  o1 = map((duration / 29 / 2), 16, 19, 0, 5);
  return o1;  
  delay(100);
}
int runtime() {
  if (voltage > 200) {  // Replace 'threshold' with your desired value
    if (startTime == 0) {
      startTime = millis();  // Record the start time only once
    }

    if (startTime != 0) {
      currenttIME = millis();                            // Record the end time only once
      duration = (currenttIME - startTime) * 1000 / 60;  // Calculate the duration
      r1 = duration;
    }
  }
}
void printing() {
  currenttIME = millis();
  char list[6]={'f','t','o','r','v','c'};
  if (previoustIME - currenttIME >= 2000) {
    if(present>=5){
      present=0;
    }
    else present++;
    if(list[present]==sense){
      present =0;
    }
    previoustIME = currenttIME;
  }
   sense=list[present];
  switch (sense) {
    case 'f':
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Fuel Level 0--30:");
      lcd.setCursor(3, 1);
      lcd.print(f1);
      break;
    case 't':
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Temperature (C):");
      lcd.setCursor(3, 1);
      lcd.print(t1);
       break;
    case 'o':
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Oil Level 0--30:");
      lcd.setCursor(3, 1);
      lcd.print(o1);
       break;
    case 'r':
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("RUNTIME:");
      lcd.setCursor(3, 1);
      lcd.print(r1);
       break;
    case 'v':
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("VOLTAGE:");
      lcd.setCursor(10, 0);
      lcd.print(v1);
       break;
    case 'c':
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("CURRENT:");
      lcd.setCursor(10, 0);
      lcd.print(c1);
       break;
  }
}

void loop() {
  currenttIME = millis();
  voltage =  analogRead(volt_pin);
  v1 = voltage;
  pinStatus = String(fuelReading()) + "f" + String(oilReading()) + "o" + String(temp()) + "t" + String(runtime()) + "r" + String(currents()) + "c";
  printing();
  Serial.print(pinStatus);
  delay(200);
}
