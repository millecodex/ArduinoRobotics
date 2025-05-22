# **Module 4: Servo Control \- Positional Movement**

In the previous modules, you learned to control LEDs and DC motors for basic movement. This module introduces you to **servo motors**, which are distinct from DC motors in their primary function: precise positional control. Servo motors are widely used in robotics for tasks requiring specific angles, such as controlling robotic arms, steering mechanisms, or camera gimbals.

## **Understanding Servo Motors**

A servo motor is a rotary actuator that allows for precise control of angular position. Unlike continuous rotation DC motors, standard servo motors are designed to rotate only within a limited range (e.g., 0 to 180 degrees) and hold a specific angle. They consist of a DC motor, a gearbox, a potentiometer (for position feedback), and a control circuit.

The control circuit interprets a pulse width modulation (PWM) signal from the microcontroller (like Arduino) to determine the desired angle. The servo then moves its shaft to that angle and holds it there.

## **SG90 Micro Servo Motor Pin Setup**

The SG90 is a popular and inexpensive micro servo motor, ideal for beginners. It typically has three wires, each with a standard color code and function:

| Wire Color | Pin Function | Arduino Connection |
| :---- | :---- | :---- |
| **Red** | VCC (+5V) | 5V |
| **Brown/Black** | GND | GND |
| **Orange/Yellow** | Signal | Any digital pin (e.g., 9, often a PWM pin) |

### **Connection Details:**

* **VCC (Red):** Connect this wire to the Arduino's 5V pin. This provides power to the servo motor.  
* **GND (Brown or Black):** Connect this wire to any GND (Ground) pin on the Arduino. This completes the circuit.  
* **Signal (Orange or Yellow):** Connect this wire to any digital I/O pin on the Arduino. While any digital pin can be used, it's common practice to use a PWM-capable pin (like pin 9\) for smoother operation, though the Servo library handles the PWM generation internally.

Diagram Description:  
Imagine your Arduino Uno board connected to an SG90 servo motor. The red wire from the servo is connected to the 5V pin on the Arduino. The brown/black wire from the servo is connected to a GND pin on the Arduino. The orange/yellow signal wire from the servo is connected to Arduino's Digital Pin 9\.

## **Controlling the Servo with the Servo Library**

The Arduino IDE comes with a built-in Servo library that makes controlling servo motors very straightforward. This library handles the complex PWM signal generation required to command the servo to a specific angle.

### **Basic Servo Control Code:**

```cpp
#include <Servo.h> // Include the Servo library

Servo jeff; // Create a Servo object named 'jeff'

void setup() {
  jeff.attach(9); // Attaches the servo on pin 9 to the servo object
  Serial.begin(9600); // Initialize serial communication for debugging
  Serial.println("Servo Control Test");
}

void loop() {
  Serial.println("Moving to 0 degrees...");
  jeff.write(0); // Tell the servo to go to 0 degrees
  delay(1000);   // Wait for 1 second

  Serial.println("Moving to 90 degrees...");
  jeff.write(90); // Tell the servo to go to 90 degrees (mid-point)
  delay(1000);   // Wait for 1 second

  Serial.println("Moving to 180 degrees...");
  jeff.write(180); // Tell the servo to go to 180 degrees
  delay(1000);   // Wait for 1 second
}
```

### **Code Explanation:**

* `#include <Servo.h>`: This line includes the necessary `Servo` library.
* `Servo jeff;`: This line creates an instance of the `Servo` class, named `jeff`. You can choose any valid variable name here. This object will represent your physical servo motor in the code.
* `jeff.attach(9);`: In the `setup()` function, this command associates the `jeff` servo object with digital pin 9 on the Arduino. This tells the Arduino which pin will be used to send control signals to the servo.
* `jeff.write(angle);`: In the `loop()` function, this is the primary command to control the servo's position. The `angle` parameter specifies the desired position in degrees, typically ranging from 0 to 180.
* `delay(1000);`: A delay is included after each movement to allow the servo time to reach its commanded position and for you to observe the movement.

### **Servo Range Considerations:**

The SG90 is a positional servo, meaning it cannot rotate a full 360 degrees continuously. Its typical range is from 0 to 180 degrees. However, some individual SG90 servos might have a slightly narrower mechanical range (e.g., 0 to 170 degrees) before hitting their internal limits. It's always a good idea to test the actual range of your specific servo to avoid stressing it.

## **Exercises and Questions**

1.  Connect your SG90 servo motor to your Arduino Uno as described in the "SG90 Micro Servo Motor Pin Setup" section. Upload the "Basic Servo Control Code" sketch. Observe the servo's movement as it cycles through 0, 90, and 180 degrees.
2.  Experiment with different angle values in `jeff.write()`. For example, try `jeff.write(45);` or `jeff.write(135);`. How does the servo respond?
3.  Change the `delay()` values between movements. What happens if you make the delays very short (e.g., 100ms)? What happens if they are very long (e.g., 5000ms)?
4.  **Critical Thinking:** If you needed a motor that could spin continuously in one direction or the other, would a standard positional servo like the SG90 be suitable? Why or why not? What type of motor would be more appropriate?

---

**Fun Fact:** The term "servo" comes from the Latin word "servus," meaning "slave." In engineering, a servo mechanism "serves" or "obeys" a command, precisely controlling a mechanical system's position, velocity, or acceleration, much like how your SG90 servo "obeys" your angle commands!
