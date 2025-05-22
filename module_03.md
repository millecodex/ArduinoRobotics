# **Module 3: Motor Control \- Digital & Variable Speed**

This module introduces you to one of the most exciting aspects of robotics: making your robot move\! Controlling motors is fundamental to any mobile robotic platform. We will explore how to control DC motors, first with basic digital ON/OFF commands for direction, and then with variable speed control using Pulse Width Modulation (PWM) through a dedicated motor shield.

## **Module 3a: Motor Control with the L293D Arduino Motor Shield**

While the Arduino is excellent for logic and low-power signals, its pins cannot directly supply enough current to drive most DC motors. Furthermore, to reverse the direction of a DC motor, you need to reverse the polarity of the voltage supplied to it, which a standard Arduino digital pin cannot do on its own. This is where motor drivers and motor shields come into play.

### **The L293D Dual H-Bridge Motor Driver IC**

The L293D is a widely used integrated circuit (IC) that acts as a "dual H-bridge" motor driver. An H-bridge is an electronic circuit that enables a voltage to be applied across a load (like a motor) in either direction, allowing for bidirectional control. The "dual" aspect means one L293D chip can control two DC motors independently.

* **Purpose:** The L293D serves as an interface between low-power microcontrollers (like your Arduino) and higher-power motors. It handles the higher current and voltage required by motors, protecting your Arduino from damage.  
* **Functionality:** It enables you to control both the speed and direction of two DC motors or one stepper motor.

### **L293D Arduino Motor Shield**

To simplify wiring and integration, the L293D IC is often incorporated into an Arduino-compatible motor shield. This shield plugs directly onto your Arduino board, providing convenient terminals for motor connections and abstracting away much of the complex wiring.

**Key Specifications of the L293D (as found on many motor shields):**

| Feature | Value/Description |
| :---- | :---- |
| Supply Voltage (Motor) | 4.5 V to 36 V |
| Logic Supply Voltage | Separate (typically 5 V, often from Arduino) |
| Output Current (Continuous) | 600 mA per channel |
| Output Current (Peak) | 1.2 A per channel |
| Number of Channels | 2 (can drive 2 DC motors or 1 stepper) |
| Protection | Built-in clamp diodes, thermal shutdown |
| Package | 16-DIP (Dual In-line Package) |
| Motor Types Supported | DC, stepper (unipolar/bipolar) |
| Control | Bidirectional, PWM speed control |
| Operating Temp | 0∘C to 70∘C |

Diagram Description of a Typical L293D Motor Shield:  
Imagine a rectangular circuit board designed to stack on top of an Arduino Uno.

* It has screw terminals along its edges for connecting up to four DC motors (labeled DC Motor 1, DC Motor 2, DC Motor 3, DC Motor 4\) and their respective GND connections.  
* There are also terminals for connecting servo motors (Servo Motor Terminal).  
* Two large black rectangular chips, the L293D Driver ICs, are prominent on the board.  
* Another smaller chip, a 74HC595 Shift Register, is typically present, which helps expand the number of pins available for motor control.  
* A Reset Switch is usually located on the shield, mirroring the Arduino's reset button.  
* An External Power Supply Terminal allows you to connect a separate power source for the motors, which is crucial for higher current demands.  
* A Power Supply Selection Jumper (often yellow) determines whether the motors draw power from the Arduino (via the shield) or from the external power supply. For most robotics projects, you will remove this jumper to use an external power supply for the motors.

### **Setup and Basic Digital Control**

For robust motor control, especially when driving multiple motors or larger motors, it is **mandatory** to use a separate power supply for the motors. On the motor shield, you will typically find a yellow jumper. **Remove this yellow jumper** to ensure that power for the motors is drawn from the dedicated external power supply terminal, rather than attempting to draw it from the Arduino's 5V pin, which cannot provide sufficient current.

To simplify programming the motor shield, we will use a dedicated library. The **Adafruit Motor Shield V2 Library** is highly recommended due to its comprehensive features and ease of use.

#### **Installing the Adafruit Motor Shield V2 Library:**

1. Open the Arduino IDE.  
2. Go to Sketch \-\> Include Library \-\> Manage Libraries....  
3. In the Library Manager, search for "Adafruit Motor Shield V2".  
4. Select "Adafruit Motor Shield V2 Library by Adafruit" and click "Install". Ensure you also install any dependencies it suggests.

Once installed, you can use simple commands to control your motors digitally (ON/OFF) for basic movements like going straight, reversing, or turning. The library handles the underlying pin manipulations for the H-bridge.

**Conceptual Code for Digital Motor Control (using Adafruit Library):**

```cpp
#include <AFMotor.h> // Include the Adafruit Motor Shield library

// Create motor objects for M1 and M2 (Motor 1 and Motor 2 on the shield)
AF_DCMotor motor1(1); // M1 port
AF_DCMotor motor2(2); // M2 port

void setup() {
  Serial.begin(9600); // Initialize serial communication
  Serial.println("Motor Control Test");

  // Set initial speed (optional, can be done later)
  motor1.setSpeed(200); // Set speed for motor 1 (0-255)
  motor2.setSpeed(200); // Set speed for motor 2 (0-255)
}

void loop() {
  // Go Straight (both motors FORWARD)
  Serial.println("Moving Straight...");
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  delay(2000); // Run for 2 seconds

  // Stop
  Serial.println("Stopping...");
  motor1.run(RELEASE); // Release motor 1
  motor2.run(RELEASE); // Release motor 2
  delay(1000); // Stop for 1 second

  // Reverse (both motors BACKWARD)
  Serial.println("Reversing...");
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  delay(2000); // Run for 2 seconds

  // Stop
  Serial.println("Stopping...");
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  delay(1000);

  // Turn Left (e.g., motor1 BACKWARD, motor2 FORWARD)
  Serial.println("Turning Left...");
  motor1.run(BACKWARD);
  motor2.run(FORWARD);
  delay(2000);
  ```

### **Code Explanation:**

- `#include <AFMotor.h>`: Includes the Adafruit Motor Shield library, providing access to its functions for motor control.
- `AF_DCMotor motor1(1);` and `AF_DCMotor motor2(2);`: Creates `AF_DCMotor` objects, associating them with the motor ports on the shield (M1 and M2, respectively).
- `motorX.setSpeed(speed);`: Sets the speed of the motor. The `speed` parameter ranges from 0 (off) to 255 (full speed).
- `motorX.run(direction);`: Controls the direction of the motor. Common directions are `FORWARD`, `BACKWARD`, and `RELEASE` (to stop the motor).

### Exercises and Questions

1. Connect two DC motors to your L293D Motor Shield (e.g., to M1 and M2). Ensure you have a separate power supply connected to the shield and the yellow jumper is removed. Upload the "Conceptual Code for Digital Motor Control" sketch. Observe how your motors behave for each movement command (straight, reverse, turn left, turn right).

2. Experiment with changing the `delay()` values after each movement. How does this affect the duration of each action?

3. **Critical Thinking**: If you only had `FORWARD` and `BACKWARD` commands for each motor, how would you make your robot pivot on the spot (turn in place without moving forward or backward)?

4. What would happen if you forgot to remove the yellow power selection jumper and tried to power the motors from the Arduino's USB connection? (Hint: Consider the current limitations of the Arduino's 5V pin).

**Fun Fact**: The very first robotic arm, called the "Unimate," was invented in 1954 by George Devol and later developed by Joseph Engelberger. It was initially used in General Motors factories for tasks like spot welding and handling hot die castings, demonstrating the early industrial applications of controlled motion!
