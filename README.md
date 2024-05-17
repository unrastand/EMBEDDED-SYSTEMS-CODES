README: Dual Motor Control with iBus Receiver for Arduino
This Arduino project demonstrates how to control two DC motors using an iBus receiver. The project uses an L298N motor driver and the IBusBM library to interface with the receiver. The code allows for speed and directional control of both motors.

Components Needed
Arduino board (e.g., Arduino mega)
iBus Receiver (e.g., FlySky FS-iA6B)
L298N Motor Driver
DC Motors (2x)
Jumper Wires
Power Supply (for motors)
Breadboard (optional)
Connections
iBus Receiver to Arduino:
iBus signal pin to Serial1 RX (on an Arduino Uno, you will need to use SoftwareSerial or a compatible board with Serial1)
Motor Driver to Arduino:
ENA to Pin 9
IN1 to Pin 7
IN2 to Pin 8
ENB to Pin 12
IN3 to Pin 10
IN4 to Pin 11
Motor Driver to Motors:
Motor A to OUT1 and OUT2
Motor B to OUT3 and OUT4
Power Connections:
Connect the motor driver to an appropriate power supply
Connect the Arduino to a power supply or USB


Instructions
Setup the hardware: Connect the iBus receiver, motor driver, and motors according to the connections provided.
Upload the code: Upload the provided Arduino code to your Arduino board.
Power up: Ensure the motor driver and Arduino are powered correctly.
Control the motors: Use your iBus transmitter to control the motors. The code maps channels from the receiver to motor speed and direction.
Channel Mapping
Channel 1: Controls the left and right movement for both motors.
Channel 2: Controls forward and backward movement for both motors.
Channel 3: Controls the speed of both motors.
Notes
Ensure your iBus receiver is correctly bound to your transmitter.
Adjust the channel mappings and motor control logic as needed for your specific setup.
Troubleshooting
No motor movement: Check all connections, ensure the motor driver is powered, and verify the receiver is bound to the transmitter.
Unexpected behavior: Use the Serial Monitor for debugging by observing the values read from the channels.
