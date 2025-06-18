/*
Module 3a 
Wiring up the motors and checking correct rotation direction
*/

// Define the pins connected to the L298N driver for Motor 1
const int motor1Input1 = 7; // IN1 on L298N
const int motor1Input2 = 8; // IN2 on L298N


// Define the pins connected to the L298N driver for Motor 2
const int motor2Input3 = 5; // IN3 on L298N
const int motor2Input4 = 6; // IN4 on L298N


// comment here about what it is
void setup() {
  // Set all motor control pins as OUTPUT
  pinMode(motor1Input1, OUTPUT);
  pinMode(motor1Input2, OUTPUT);
  
  pinMode(motor2Input3, OUTPUT);
  pinMode(motor2Input4, OUTPUT);
  
  // Initialize Serial communication for debugging messages
  Serial.begin(9600);
  Serial.println("Module 3a: Basic L298N Motor Movement");
 // Initially stop both motors
  stopMotors();
}

void loop() {
  Serial.println("Moving FORWARD...");
  moveForward();
  delay(3000); // Move forward for 3 seconds

  Serial.println("Stopping...");
  stopMotors();
  delay(1000); // Stop for 1 second

  Serial.println("Moving BACKWARD...");
  moveBackward();
  delay(3000); // Move backward for 3 seconds

  Serial.println("Stopping...");
  stopMotors();
  delay(1000); // Stop for 1 second
  
}

// Function to make both motors move forward
void moveForward() {
  // Motor 1 Forward
  digitalWrite(motor1Input1, HIGH);
  digitalWrite(motor1Input2, LOW);
  // Motor 2 Forward
  digitalWrite(motor2Input3, HIGH);
  digitalWrite(motor2Input4, LOW);
}

// Function to make both motors move backward
void moveBackward() {
  // Motor 1 Backward
  digitalWrite(motor1Input1, LOW);
  digitalWrite(motor1Input2, HIGH);
  // Motor 2 Backward
  digitalWrite(motor2Input3, LOW);
  digitalWrite(motor2Input4, HIGH);
}

// Function to stop both motors
void stopMotors() {
  // Motor 1 Stop
  digitalWrite(motor1Input1, LOW);
  digitalWrite(motor1Input2, LOW);
  // Motor 2 Stop
  digitalWrite(motor2Input3, LOW);
  digitalWrite(motor2Input4, LOW);
}
