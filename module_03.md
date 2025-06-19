# 🚷 Skip this; not compatible 🏗️

# Module 3a: Motor Control - Basic Movement with L298N

In this module, you will take the first steps towards making your robot move! We will focus on the fundamental task of connecting and controlling DC motors using the **L298N Motor Driver Module**. The goal for this module is to understand how to make your robot move **forward** and **reverse** in a straight line.

## The Role of a Motor Driver: Why L298N?

The Arduino's digital pins, while great for sending signals, cannot provide enough electrical current to directly power most DC motors. Additionally, to change a DC motor's direction, you need to reverse the polarity of the voltage supplied to it. This is where a **motor driver** becomes indispensable.

The **L298N Motor Driver Module** is a robust and widely used solution for controlling DC motors. It incorporates an L298N Integrated Circuit (IC), which features a dual H-bridge. An H-bridge is an electronic circuit that allows you to apply voltage across a motor in two directions, enabling bidirectional control (forward and reverse). The module simplifies wiring by integrating necessary components and providing convenient terminals for power, motors, and control signals from your Arduino.

![L298N DC Motor Driver](https://github.com/user-attachments/assets/57d80a59-f960-4a2d-8779-8197054ad7f0)


* **Purpose:** The L298N module acts as a power interface, taking low-current control signals from your Arduino and using a separate, higher-current power supply to drive the motors. This protects your Arduino from damage.
* **Functionality:** It can control the direction of up to two independent DC motors.

### Key Features of the L298N Module:

* **Dual H-Bridge:** Capable of driving two DC motors (or one stepper motor) independently.
* **Motor Voltage Range:** Supports motor power supplies typically from 5V to 35V.
* **Current Capacity:** Each motor channel can typically handle up to 2 Amperes of continuous current.
* **Built-in 5V Regulator:** Many L298N modules include an onboard 5V regulator that *can* provide 5V for your Arduino if your motor power supply is above 7V. **However, for safety and stability, it is generally recommended to power your Arduino separately via its own power supply.**

## L298N Module Pinout and Connections

Understanding the pin connections is vital for proper operation. The L298N module has clearly labeled screw terminals and header pins:

![Pasted Graphic 7](https://github.com/user-attachments/assets/46c1eff6-47e4-47d0-92bd-87a667760007)


**1. Power Connections:**
* **`+12V` (or `+V`):** This is where you connect the positive (+) terminal of your **external power supply for the motors** (e.g., a 6V, 9V, or 12V battery pack). This power source must be separate from your Arduino's power.
* **`GND`:** This is the common ground connection. It **MUST** be connected to a `GND` pin on your Arduino board. Establishing a common ground is crucial for the Arduino's control signals to correctly operate the L298N module. This can be done with aligator clips, or splicing the battery pack ground into the jumper connected to the Arduino.
* **`+5V` (or `5V EN` / `VCC`):** This pin is for the module's internal 5V logic supply. Most modules have a jumper that enables an onboard 5V regulator.

   * Note: we will be taking the jumper **OFF** as we are using 6V (1.5 x 4 AA batteries) and **connecting the 5V pin from your Arduino Uno to this +5V pin on the L298N** module. This provides the essential 5V logic power that the L298N needs to operate correctly when its onboard regulator cannot function.

**2. Motor Connections:**
* **`OUT1`, `OUT2`:** Connect these two terminals to the two wires of **DC Motor 1**. The polarity here will determine initial forward/reverse, which you can adjust in code.
* **`OUT3`, `OUT4`:** Connect these two terminals to the two wires of **DC Motor 2**.

**3. Arduino Control Connections (Digital Direction):**
For simply moving forward and reverse, we need two digital pins per motor to control its direction. We will set the speed to a constant for now.

* **Motor 1 Direction Pins:**
    * **`IN1`:** Connect to an Arduino Digital I/O pin (e.g., Digital Pin 7).
    * **`IN2`:** Connect to an Arduino Digital I/O pin (e.g., Digital Pin 8).

* **Motor 2 Direction Pins:**
    * **`IN3`:** Connect to an Arduino Digital I/O pin (e.g., Digital Pin 5).
    * **`IN4`:** Connect to an Arduino Digital I/O pin (e.g., Digital Pin 6).

**Diagram Description:**
< Image / Schematic Here>

* A black jumper wire connects an Arduino `GND` pin to the `GND` terminal of the L298N module.
* An external battery pack (e.g., a 9V battery) has its positive terminal connected to the `+12V` (`+V`) terminal of the L298N module.
* Two wires from DC Motor 1 are connected to `OUT1` and `OUT2` on the L298N.
* Two wires from DC Motor 2 are connected to `OUT3` and `OUT4` on the L298N.
* Jumper wires connect:
    * Arduino Digital Pin 7 to `IN1` on the L298N.
    * Arduino Digital Pin 8 to `IN2` on the L298N.
    * Arduino Digital Pin 5 to `IN3` on the L298N.
    * Arduino Digital Pin 6 to `IN4` on the L298N.
 
![image](https://github.com/user-attachments/assets/f54950ff-58cf-410f-ac71-e0d199db70a3)


## Coding Basic Forward and Reverse Movement

To control the direction of a DC motor with the L298N, you set the two `IN` pins for that motor to complementary `HIGH` and `LOW` states. For instance, to make Motor 1 go forward, you might set `IN1` `HIGH` and `IN2` `LOW`. To reverse, you'd swap them: `IN1` `LOW` and `IN2` `HIGH`. To stop the motor, you can set both `IN` pins to `LOW`.

For now, we'll assume a constant "full speed" by implicitly powering the L298N's enable pins (ENA and ENB) with `HIGH` signals. Variable speed control will be covered in the next module.

**Code Example: Forward and Reverse Movement:**

```cpp
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
```

### Code Explanation:

* **Pin Definitions:** `const int` is used to define the Arduino pins connected to the L298N's `IN` and `Enable` pins. `motor1Enable` and `motor2Enable` are set to `HIGH` in `setup()` to allow full current to the motors.
* **`setup()` Function:** All relevant pins are configured as `OUTPUT`s. Serial communication is initiated. The enable pins (`motor1Enable`, `motor2Enable`) are driven `HIGH` to allow the motors to receive power. Finally, `stopMotors()` ensures a defined starting state.
* **`loop()` Function:** This function orchestrates the basic movements: `moveForward()`, `stopMotors()`, `moveBackward()`, and `stopMotors()`, each with a `delay()` to observe the action.
* **`moveForward()` Function:** Sets the `IN` pins for both motors to achieve forward rotation. The specific `HIGH`/`LOW` combination depends on how your motors are wired to `OUT1`/`OUT2` and `OUT3`/`OUT4`. If your motors spin backward, simply reverse the `HIGH` and `LOW` states for that motor's `IN` pins.
* **`moveBackward()` Function:** Reverses the `IN` pin states for both motors to achieve backward rotation.
* **`stopMotors()` Function:** Sets both `IN` pins for each motor to `LOW`. This configuration typically causes the motor to "brake" quickly, bringing it to a rapid stop, as the motor windings are shorted.

## Exercises and Questions

1.  **Circuit Assembly & Test:** Carefully connect your Arduino Uno, L298N module, and two DC motors as per the "L298N Module Pinout and Connections" diagram. Ensure your external power supply is correctly connected to the L298N. Upload the provided "Code Example: Forward and Reverse Movement" sketch. Observe your motors: Do they spin in the expected directions? 
2.  **Motor Direction Calibration:** If one or both of your motors spin in the opposite direction (e.g., "forward" makes them spin backward), -> On the motor controller module unplug IN3 and IN4 to test one motor at a time. If this motor is okay, plug back in IN3 and IN4. If this motor is not okay, swap these two jumpers. This keeps the code consistent while calibrating rotation direction. Alternatively you may adjust the `HIGH` and `LOW` assignments within the `moveForward()` and `moveBackward()` functions for that specific motor until both motors consistently push the robot forward and backward.
3.  **Impact of `delay()`:** Experiment with changing the `delay(3000);` values in the `loop()` function. What happens if you make them very short (e.g., `delay(500);`)? What happens if you make them very long (e.g., `delay(10000);`)?
4.  **Critical Thinking: Power Supply:** Your Arduino can be powered via USB. Why is it crucial to use a *separate external power supply* for the L298N module and the motors, rather than trying to power the motors directly from the Arduino's 5V pin or USB port? (Hint: Think about current draw).

---

**Fun Fact:** H-bridge circuits, like the one inside the L298N, are named because the arrangement of switches or transistors resembles the letter 'H' on a circuit diagram. This clever configuration allows current to flow in two directions through a motor, which is fundamental to controlling its direction of rotation!

---
NEXT ➡️ (time permitting) You are now ready to move on to [Module 3b](./module_03b.md), to extend the motor control!

NEXT ➡️ You are now ready to move on to [Module 4](./module_04.md), where we'll add in a servo!
