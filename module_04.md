# **Module 4: Servo Control \- Positional Movement**

In the previous modules, you learned to control LEDs and DC motors for basic movement. This module introduces you to **servo motors**, which are distinct from DC motors in their primary function: precise positional control. Servo motors are widely used in robotics for tasks requiring specific angles, such as controlling robotic arms, steering mechanisms, or camera gimbals.

## **Understanding Servo Motors**
A servo motor is a self-contained rotary actuator that allows for exact control of its angular position. Think of it as a small motor with a built-in brain that knows its current orientation. Each servo motor typically integrates:

* **A DC Motor:** Provides the power to rotate the shaft.
* **A Gearbox:** Reduces the motor's high rotational speed to a usable lower speed, while simultaneously increasing torque. This allows the servo to hold a position against resistance.
* **A Potentiometer:** An internal variable resistor that provides precise feedback on the current angular position of the servo's output shaft.
* **A Control Circuit:** This electronic brain compares the desired position (from your Arduino's signal) with the actual position (from the potentiometer) and drives the DC motor until the two match. This continuous feedback loop is what makes servos so accurate and able to "hold" a position.


The control circuit interprets a pulse width modulation (PWM) signal from the microcontroller (like Arduino) to determine the desired angle. The servo then moves its shaft to that angle and holds it there.

## **SG90 Micro Servo Motor Pin Setup**

The SG90 is a popular and inexpensive micro servo motor, ideal for beginners. It typically has three wires, each with a standard color code and function:

| Wire Color | Pin Function | Arduino Connection |
| :---- | :---- | :---- |
| **Red** | VCC (+5V) | 5V |
| **Brown/Black** | GND | GND |
| **Orange/Yellow** | Signal | Any digital pin (I will use 9, often a PWM ~ pin) |

### **Connection Details:**

* **VCC (Red):** Connect this wire to the Arduino's 5V pin. This provides power to the servo motor.  
* **GND (Brown or Black):** Connect this wire to any GND (Ground) pin on the Arduino. This completes the circuit.  
* **Signal (Orange or Yellow):** Connect this wire to any digital I/O pin on the Arduino. While any digital pin can be used, it's common practice to use a PWM-capable pin (like pin 9\) for smoother operation, though the Servo library handles the PWM generation internally.

Diagram Description:  
Imagine your Arduino Uno board connected to an SG90 servo motor. The red wire from the servo is connected to the 5V pin on the Arduino. The brown/black wire from the servo is connected to a GND pin on the Arduino. The orange/yellow signal wire from the servo is connected to Arduino's Digital Pin 9\.

## **Controlling the Servo with the Servo Library**

The Arduino IDE comes with a built-in Servo library that makes controlling servo motors very straightforward. This library handles the complex PWM signal generation required to command the servo to a specific angle. In the Libary Manager make sure the **Servo** library is installed.

### **Basic Servo Control Code:**

```cpp
#include <Servo.h> // Include the Servo library

Servo myServo; // Create a Servo object named 'myServo'

void setup() {
  myServo.attach(9); // Attaches the servo on pin 9 to the servo object
  Serial.begin(9600); // Initialize serial communication for debugging
  Serial.println("Servo Control Test");
}

void loop() {
  Serial.println("Moving to 0 degrees...");
  myServo.write(0); // Tell the servo to go to 0 degrees
  delay(1000);    // Wait for 1 second

  Serial.println("Moving to 90 degrees...");
  myServo.write(90); // Tell the servo to go to 90 degrees (mid-point)
  delay(1000);    // Wait for 1 second

  Serial.println("Moving to 180 degrees...");
  myServo.write(180); // Tell the servo to go to 180 degrees
  delay(1000);    // Wait for 1 second
}
```

### **Code Explanation:**

* `#include <Servo.h>`: This line includes the necessary `Servo` library.
* `Servo myServo;`: This line creates an instance of the `Servo` class, named `myServo`. You can choose any valid variable name here. This object will represent your physical servo motor in the code.
* `myServo.attach(9);`: In the `setup()` function, this command associates the `myServo` servo object with digital pin 9 on the Arduino. This tells the Arduino which pin will be used to send control signals to the servo.
* `myServo.write(angle);`: In the `loop()` function, this is the primary command to control the servo's position. The `angle` parameter specifies the desired position in degrees, typically ranging from 0 to 180.
* `delay(1000);`: A delay is included after each movement to allow the servo time to reach its commanded position and for you to observe the movement.

### **Servo Range Considerations:**

The SG90 is a positional servo, meaning it cannot rotate a full 360 degrees continuously. Its typical range is from 0 to 180 degrees. However, some individual SG90 servos might have a slightly narrower mechanical range (e.g., 0 to 170 degrees) before hitting their internal limits. It's always a good idea to test the actual range of your specific servo to avoid stressing it.

## Exercises and Questions

1.  **Sweep Timing and Prediction:** Upload the "[Servo Sweep](./sketches/sketch_04_sweep.ino)" sketch to your Arduino. What is the code doing?
2.  **Non-Linear Sweep Experiment:** Modify the `for` loops to create a non-linear sweeping motion. For example, make the servo move faster when it's near the center (e.g., 60-120 degrees) and slower when it's approaching the extremes (0-30 degrees or 150-180 degrees). You could achieve this by adjusting the `delay()` based on the `pos` value (e.g., using an `if-else` statement or a mathematical function).
3.  **Dynamic Sweep Range:** Program the servo to cycle through different sweep ranges automatically. For example, it could sweep:
    * A narrow range (e.g., 60 to 120 degrees) for 3 seconds.
    * A medium range (e.g., 30 to 150 degrees) for 3 seconds.
    * A full range (0 to 180 degrees) for 3 seconds.
    * Then repeat this sequence indefinitely.
4.  **Design Thinking:** Imagine you've attached an ultrasonic sensor (from Module 2) to this sweeping servo. How does this setup fundamentally improve your robot's ability to detect obstacles compared to having the sensor fixed in place? 
5.  **Advanced Challenge:** Can you modify the code such that the servo sweeps from 0 to 180 degrees at a relatively slow pace, but then sweeps back from 180 to 0 degrees at a much faster pace? Explain the changes you made and why they achieve the desired effect.
---

**Fun Fact:** The term "servo" comes from the Latin word "servus," meaning "slave." In engineering, a servo mechanism "serves" or "obeys" a command, precisely controlling a mechanical system's position, velocity, or acceleration, much like how your SG90 servo "obeys" your angle commands!

---
NEXT ➡️ You are now ready to move on to [Module 5](./module_05.md), the big build!
