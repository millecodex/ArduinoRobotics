# Module 4: Servo Control - Sweep the Floor

Having mastered controlling basic LEDs and driving DC motors for continuous movement, we now delve into the world of **servo motors**. Unlike the DC motors you've encountered, standard servo motors are specifically designed for **precise positional control**. This capability is invaluable in robotics for tasks demanding accuracy, such as manipulating robotic arms, controlling steering systems, or stabilizing camera platforms.

## Understanding Servo Motors: Precision in Motion

A servo motor is a self-contained rotary actuator that allows for exact control of its angular position. Think of it as a small motor with a built-in brain that knows its current orientation. Each servo motor typically integrates:

* **A DC Motor:** Provides the power to rotate the shaft.
* **A Gearbox:** Reduces the motor's high rotational speed to a usable lower speed, while simultaneously increasing torque. This allows the servo to hold a position against resistance.
* **A Potentiometer:** An internal variable resistor that provides precise feedback on the current angular position of the servo's output shaft.
* **A Control Circuit:** This electronic brain compares the desired position (from your Arduino's signal) with the actual position (from the potentiometer) and drives the DC motor until the two match. This continuous feedback loop is what makes servos so accurate and able to "hold" a position.

Standard servo motors are designed to rotate only within a specific, limited range (commonly 0 to 180 degrees). They achieve precise angles by interpreting a specific type of Pulse Width Modulation (PWM) signal from your microcontroller.

## SG90 Micro Servo Motor Pin Setup

The SG90 is a very common and cost-effective micro servo motor, excellent for introductory robotics projects. It typically features three wires, each with a distinct color code and function:

| Wire Color      | Pin Function | Arduino Connection                                  |
| :-------------- | :----------- | :-------------------------------------------------- |
| **Red** | VCC (+5V)    | 5V                                                  |
| **Brown/Black** | GND          | GND                                                 |
| **Orange/Yellow** | Signal       | Any digital pin (e.g., Digital Pin 9 is a common choice) |

### Connection Details:

* **VCC (Red):** Connect this wire to the Arduino's 5V pin. This provides the necessary electrical power for the servo motor's operation.
* **GND (Brown or Black):** Connect this wire to any GND (Ground) pin on the Arduino. This completes the electrical circuit.
* **Signal (Orange or Yellow):** Connect this wire to any digital I/O pin on the Arduino. While the `Servo` library (which we'll use) can work with most digital pins, it's often best practice to use a PWM-capable pin (like pin 9, 10, or 11 on an Uno) as the library might leverage PWM for smoother signal generation, even if not directly using `analogWrite()`.

**Diagram Description:**
Envision your Arduino Uno board linked to an SG90 servo motor. The servo's red wire should extend to the Arduino's 5V power supply pin. The brown/black ground wire from the servo connects to one of the Arduino's GND pins. Lastly, the orange/yellow signal wire from the servo should be connected to a digital I/O pin on the Arduino, for instance, Digital Pin 9.

## Controlling the Servo with the `Servo` Library

The Arduino IDE comes pre-installed with a highly efficient `Servo` library. This library significantly simplifies servo control by handling the intricate details of generating the precise PWM signal required to command the servo to a specific angle. You don't need to manually manipulate pulse widths; you just tell the servo your desired angle.

### Basic Servo Control Code:

```cpp
#include <Servo.h> // Include the Servo library, essential for servo functionality

Servo myServo; // Create a Servo object named 'myServo'. You can name it anything you like!

void setup() {
  myServo.attach(9); // Attaches the servo object 'myServo' to Digital Pin 9.
                     // This tells the Arduino which pin will send control signals to the servo.
  Serial.begin(9600); // Initialize serial communication at 9600 baud for debugging output.
  Serial.println("Servo Positional Control Test Started!");
}

void loop() {
  Serial.println("Moving to 0 degrees (full counter-clockwise)...");
  myServo.write(0);  // Command the servo to move to 0 degrees.
  delay(1500);       // Wait for 1.5 seconds to allow the servo to reach position and for observation.

  Serial.println("Moving to 90 degrees (center position)...");
  myServo.write(90); // Command the servo to move to 90 degrees.
  delay(1500);       // Wait for 1.5 seconds.

  Serial.println("Moving to 180 degrees (full clockwise)...");
  myServo.write(180); // Command the servo to move to 180 degrees.
  delay(1500);       // Wait for 1.5 seconds.
}
```

### Servo Range Considerations:

It's important to remember that standard SG90 servos are **positional servos**, meaning they cannot rotate a full 360 degrees continuously like a DC motor. Their typical range is 0 to 180 degrees. However, due to manufacturing variations, some individual SG90 servos might have a slightly narrower mechanical range (e.g., 5 to 175 degrees) before hitting their internal mechanical limits. It's always best practice to test the actual operational range of your specific servo to avoid forcing it against its mechanical stops, which can cause damage or premature wear.

## Exercises and Questions

1.  **Sweep Timing and Prediction:** Upload the "Servo Sweep" sketch to your Arduino. Using a stopwatch, carefully measure the total time it takes for the servo to complete one full sweep cycle (from 0 to 180 and back to 0). Now, without uploading, predict what the new total sweep time would be if you changed `delay(15);` to `delay(5);` within both `for` loops. Upload the modified code and verify your prediction. Explain any discrepancies.
2.  **Non-Linear Sweep Experiment:** Modify the `for` loops to create a non-linear sweeping motion. For example, make the servo move faster when it's near the center (e.g., 60-120 degrees) and slower when it's approaching the extremes (0-30 degrees or 150-180 degrees). You could achieve this by adjusting the `delay()` based on the `pos` value (e.g., using an `if-else` statement or a mathematical function).
3.  **Dynamic Sweep Range:** Program the servo to cycle through different sweep ranges automatically. For example, it could sweep:
    * A narrow range (e.g., 60 to 120 degrees) for 3 seconds.
    * A medium range (e.g., 30 to 150 degrees) for 3 seconds.
    * A full range (0 to 180 degrees) for 3 seconds.
    * Then repeat this sequence indefinitely.
4.  **Critical Thinking:** Imagine you've attached an ultrasonic sensor (from Module 2) to this sweeping servo. How does this setup fundamentally improve your robot's ability to detect obstacles compared to having the sensor fixed in place? 
5.  **Advanced Challenge:** Can you modify the code such that the servo sweeps from 0 to 180 degrees at a relatively slow pace, but then sweeps back from 180 to 0 degrees at a much faster pace? Explain the changes you made and why they achieve the desired effect.

---

**Fun Fact:** The concept of sweeping motion for environmental perception has a long history in robotics and engineering, predating modern computing. Early radar systems, for instance, used mechanically sweeping antennas to scan for targets across a wide area. Similarly, some biological systems, like a chameleon's eyes, can independently scan their surroundings to build a comprehensive view, mirroring the functionality you're implementing with your servo!
