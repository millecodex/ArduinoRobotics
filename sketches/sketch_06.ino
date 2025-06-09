#include <Servo.h>    // Include the Servo library for servo control
#include <NewPing.h>  // Include the NewPing library for ultrasonic sensor

// --- Motor Control Pins (L298N Module) ---
// These pins control direction. ENA/ENB are assumed to be HIGH via jumpers on the L298N module.
const int motor1Input1 = 7; // IN1 on L298N for Motor 1
const int motor1Input2 = 8; // IN2 on L298N for Motor 1
const int motor2Input3 = 5; // IN3 on L298N for Motor 2
const int motor2Input4 = 6; // IN4 on L298N for Motor 2

// --- Ultrasonic Sensor Pins (HC-SR04) ---
const int TRIGGER_PIN = 12; // Arduino pin connected to HC-SR04 Trigger pin
const int ECHO_PIN = 13;    // Arduino pin connected to HC-SR04 Echo pin
const int MAX_DISTANCE = 200; // Maximum distance (in cm) to ping (sensor range 2cm-400cm).

// --- Servo Motor Pin (SG90) ---
const int SERVO_PIN = 9; // Arduino pin connected to SG90 Servo Signal pin

// --- Global Objects ---
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing sensor object
Servo myServo;                                       // Servo object

// --- Robot Movement Constants ---
#define FORWARD_DIR 1
#define BACKWARD_DIR 2
#define LEFT_TURN 3
#define RIGHT_TURN 4
#define STOP_MOVE 0

const int DANGER_ZONE_CM = 20; // Distance in cm at which an obstacle is too close
const int REVERSE_DURATION = 700; // Milliseconds to reverse
const int TURN_DURATION = 800; // Milliseconds to turn

void setup() {
  // Initialize Serial communication for debugging
  Serial.begin(9600);
  Serial.println("Autonomous Robot Started!");

  // Setup Motor Control Pins as OUTPUTs
  pinMode(motor1Input1, OUTPUT);
  pinMode(motor1Input2, OUTPUT);
  pinMode(motor2Input3, OUTPUT);
  pinMode(motor2Input4, OUTPUT);

  // Attach Servo to its pin
  myServo.attach(SERVO_PIN);
  myServo.write(90); // Start servo at center position
  delay(500); // Give servo time to move

  // Ensure motors are initially stopped
  stopMotors();
}

void loop() {
  int distance = scanForObstacle(); // Get distance by scanning
  Serial.print("Current Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance > DANGER_ZONE_CM || distance == 0) { // If no obstacle (distance > danger zone) or sensor returned 0 (no echo, far away)
    Serial.println("Path clear. Moving forward.");
    moveForward();
    delay(200); // Move forward for a short duration, then re-scan
  } else { // Obstacle detected within danger zone
    Serial.println("Obstacle detected! Avoiding...");
    avoidObstacle();
  }
}

// --- Robot Movement Helper Functions ---

// Function to make both motors move forward
void moveForward() {
  digitalWrite(motor1Input1, HIGH);
  digitalWrite(motor1Input2, LOW);
  digitalWrite(motor2Input3, HIGH);
  digitalWrite(motor2Input4, LOW);
}

// Function to make both motors move backward (reverse)
void moveBackward() {
  digitalWrite(motor1Input1, LOW);
  digitalWrite(motor1Input2, HIGH);
  digitalWrite(motor2Input3, LOW);
  digitalWrite(motor2Input4, HIGH);
}

// Function to make the robot turn left
void turnLeft() {
  digitalWrite(motor1Input1, LOW);  // Motor 1 (Right wheel) backward
  digitalWrite(motor1Input2, HIGH);
  digitalWrite(motor2Input3, HIGH); // Motor 2 (Left wheel) forward
  digitalWrite(motor2Input4, LOW);
}

// Function to make the robot turn right
void turnRight() {
  digitalWrite(motor1Input1, HIGH); // Motor 1 (Right wheel) forward
  digitalWrite(motor1Input2, LOW);
  digitalWrite(motor2Input3, LOW);  // Motor 2 (Left wheel) backward
  digitalWrite(motor2Input4, HIGH);
}

// Function to stop both motors (brake)
void stopMotors() {
  digitalWrite(motor1Input1, LOW);
  digitalWrite(motor1Input2, LOW);
  digitalWrite(motor2Input3, LOW);
  digitalWrite(motor2Input4, LOW);
}

// --- Sensing and Decision Making Functions ---

// Function to scan for obstacles using the servo and ultrasonic sensor
int scanForObstacle() {
  int currentDistance;
  int minDistance = MAX_DISTANCE + 1; // Initialize with a value higher than max possible distance

  // Sweep servo from 0 to 180 degrees, taking readings
  for (int pos = 0; pos <= 180; pos += 45) { // Scan at 0, 45, 90, 135, 180 degrees
    myServo.write(pos);
    delay(100); // Give servo time to move to position
    currentDistance = sonar.ping_cm();
    if (currentDistance > 0 && currentDistance < minDistance) { // Only update if valid reading
      minDistance = currentDistance;
    }
  }

  // Sweep servo back to center (or desired resting position)
  myServo.write(90);
  delay(200); // Give servo time to return

  return minDistance; // Return the minimum distance found during the scan
}

// Function to execute obstacle avoidance routine
void avoidObstacle() {
  stopMotors();
  delay(500); // Small pause

  Serial.println("Reversing...");
  moveBackward();
  delay(REVERSE_DURATION); // Reverse for defined duration

  stopMotors();
  delay(500); // Small pause

  // Decide to turn left or right randomly (or based on previous scan data)
  // For simplicity, we'll turn right for now
  Serial.println("Turning Right...");
  turnRight();
  delay(TURN_DURATION); // Turn for defined duration

  stopMotors();
  delay(500); // Small pause

  // After avoidance, scan again before continuing (optional, but good practice)
  Serial.println("Avoiding complete. Re-scanning before moving forward.");
  int postTurnDistance = scanForObstacle();
  if (postTurnDistance <= DANGER_ZONE_CM && postTurnDistance != 0) {
    Serial.println("Still blocked! Trying another turn.");
    // If still blocked, try turning left this time (simple alternative)
    turnLeft();
    delay(TURN_DURATION);
    stopMotors();
    delay(500);
  }
}
