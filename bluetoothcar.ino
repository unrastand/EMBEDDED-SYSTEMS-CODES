// Define motor control pins
const int IN1 = 9;  // Motor A forward
const int IN2 = 8;  // Motor A backward
const int IN3 = 7;  // Motor B forward
const int IN4 = 6;  // Motor B backward
const int ENA = 10; // Enable pin for Motor A (PWM)
const int ENB = 11; // Enable pin for Motor B (PWM)

// Variable to store received Bluetooth command
char command;

void setup() {
  // Set up motor pins as output
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  // Start serial communication
  Serial.begin(9600);

  // Stop motors at start
  stopMotors();
}

void loop() {
  // Check if data is available from Bluetooth
  if (Serial.available()) {
    command = Serial.read(); // Read the command from Bluetooth

    // Control the car based on the command received
    switch (command) {
      case 'F': // Move Forward
        moveForward();
        break;

      case 'B': // Move Backward
        moveBackward();
        break;

      case 'L': // Turn Left
        turnLeft();
        break;

      case 'R': // Turn Right
        turnRight();
        break;

      case 'S': // Stop
        stopMotors();
        break;

      default:
        // Do nothing for unknown commands
        break;
    }
  }
}

// Function to move forward
void moveForward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 255); // Full speed
  analogWrite(ENB, 255); // Full speed
}

// Function to move backward
void moveBackward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, 255);
  analogWrite(ENB, 255);
}

// Function to turn left
void turnLeft() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 180); // Reduced speed for smoother turning
  analogWrite(ENB, 255);
}

// Function to turn right
void turnRight() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, 255);
  analogWrite(ENB, 180);
}

// Function to stop motors
void stopMotors() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}
