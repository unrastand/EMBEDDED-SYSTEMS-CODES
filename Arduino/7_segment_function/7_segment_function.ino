void setup() {
  for (int i = 3; i <= 11; i++) {
    pinMode(i, OUTPUT);
  }
}

void dot(int values[]) {
  int pins[] = { 3, 4, 5, 6, 7, 8, 9, 10 };
  for (int i = 0; i < 8; i++) {
    digitalWrite(pins[i], values[i]);
  }
  delay(1000);
}

void loop() {
  int patterns[][9]  = {
    {1, 1, 1, 1, 1, 1, 0, 0},
    {0, 1, 1, 0, 0, 0, 0, 0},
    {1, 1, 0, 1, 1, 0, 1, 0},
    {1, 1, 1, 1, 0, 0, 1, 0},
    {0, 1, 1, 0, 0, 1, 1, 0},
    {1, 0, 1, 1, 0, 1, 1, 0},
    {1, 0, 1, 1, 1, 1, 1, 0},
    {1, 1, 1, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 0},
    {1, 1, 1, 0, 0, 1, 1, 1}
  };
   
    dot(patterns[i]);
  }
}  