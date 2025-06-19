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

const int DANGER_ZONE_CM = 25; // Distance in cm at which an obstacle is too close
const int REVERSE_DURATION = 800; // Milliseconds to reverse
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
  myServo.write(90); // Start servo at center position (forward-facing)
  delay(500); // Give servo time to move

  // Ensure motors are initially stopped
  stopMotors();
}

void loop() {
  // Always check the distance straight ahead while moving forward
  int distance = getForwardDistance(); 
  Serial.print("Current Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance > DANGER_ZONE_CM || distance == MAX_DISTANCE) { 
    // If no obstacle (distance > danger zone) or sensor returned MAX_DISTANCE (no echo, far away)
    // Note: NewPing returns 0 for no echo, but we're mapping 0 to MAX_DISTANCE in getForwardDistance()
    Serial.println("Path clear. Moving forward.");
    moveForward();
    delay(300); // Short delay to allow a bit of movement before re-checking
  } else { 
    // Obstacle detected within danger zone
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

// NEW: Function to get distance directly in front (servo at 90 degrees)
int getForwardDistance() {
  myServo.write(90); // Ensure servo is facing straight ahead
  delay(300); // Give servo time to move if it was recently moved during avoidance
  int distance = sonar.ping_cm();
  // NewPing returns 0 if no echo within MAX_DISTANCE. Treat this as clear/far away.
  if (distance == 0) {
    return MAX_DISTANCE;
  }
  return distance;
}

// NEW: Function to scan different directions and decide the best turn
int decideAvoidanceDirection() {
  int leftDistance, rightDistance;

  // Scan Left (e.g., 45 degrees)
  myServo.write(45);
  delay(600); // Give servo more time to move and stabilize for accurate reading
  leftDistance = sonar.ping_cm();
  if (leftDistance == 0) leftDistance = MAX_DISTANCE; // If no echo, assume clear

  // Scan Right (e.g., 135 degrees)
  myServo.write(135);
  delay(600); // Give servo more time to move and stabilize
  rightDistance = sonar.ping_cm();
  if (rightDistance == 0) rightDistance = MAX_DISTANCE; // If no echo, assume clear

  myServo.write(90); // Return servo to center after scan
  delay(200);

  Serial.print("Scan Result: Left=");
  Serial.print(leftDistance);
  Serial.print("cm, Right=");
  Serial.print(rightDistance);
  Serial.println("cm");

  // Decide the turn direction based on which side is clearer
  if (rightDistance > leftDistance) {
    return RIGHT_TURN;
  } else {
    // If left is greater or equal, turn left
    return LEFT_TURN;
  }
}

// Function to execute obstacle avoidance routine
void avoidObstacle() {
  stopMotors();
  delay(800); //  pause before reversing

  Serial.println("Reversing...");
  moveBackward();
  delay(REVERSE_DURATION); // Reverse for defined duration

  stopMotors();
  delay(800); //  pause before turning

  int turnDecision = decideAvoidanceDirection(); // Use the new function to determine best turn

  if (turnDecision == RIGHT_TURN) {
    Serial.println("Turning Right based on scan...");
    turnRight();
  } else {
    Serial.println("Turning Left based on scan...");
    turnLeft();
  }
  delay(TURN_DURATION); // Turn for defined duration

  stopMotors();
  delay(500); // Small pause

  Serial.println("Avoidance maneuver complete. Resuming main loop.");
  // The loop() function will automatically call getForwardDistance() for the next check.
}
