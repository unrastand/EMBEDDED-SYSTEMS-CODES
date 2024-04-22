const int LED =3;
const int BUTTON1 =4;
const int BUTTON2 =5;

int button1, button2, dim_value;

void setup() {
pinMode(BUTTON1, INPUT);
pinMode(BUTTON2, INPUT);
pinMode(LED, OUTPUT);
Serial.begin(9600);
}

void loop() {

button1 = digitalRead(BUTTON1);
button2 = digitalRead(BUTTON2);

if(button1 == HIGH) {
  if(dim_value > 255) {
    dim_value = dim_value;
}
else{
dim_value += 25;
delay(300);
  }
}
if(button2 == HIGH) {
  if(dim_value < 25) {
    dim_value = dim_value;
}
else{
dim_value -= 25;
delay(300);
  }
}
Serial.println(dim_value);
analogWrite(LED, dim_value);
}

