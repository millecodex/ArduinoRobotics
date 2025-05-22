# **Module 3b: Motor Control \- Variable Speed with Pulse Width Modulation (PWM)**

Building on the digital ON/OFF motor control from Module 3a, this module focuses on achieving variable speed for your DC motors. The ability to precisely control motor speed is crucial for nuanced movements, smooth acceleration/deceleration, and accurate navigation in robotics. This is primarily achieved through a technique called Pulse Width Modulation (PWM).

## **Theory: Pulse Width Modulation (PWM)**

PWM is a powerful technique that allows you to achieve analog-like results using digital signals. Instead of providing a continuous analog voltage, PWM rapidly switches a digital signal ON and OFF at a high frequency. The "average" voltage supplied to a component, and thus its effective power or speed, is determined by the proportion of time the signal is ON versus OFF within each cycle.

* **Duty Cycle:** The key concept in PWM is the **duty cycle**. This is the ratio of the time the signal is ON (pulse width) to the total period of the signal. It is usually expressed as a percentage.  
  * A 0% duty cycle means the signal is always OFF (0V average).  
  * A 50% duty cycle means the signal is ON for half the time and OFF for half the time (e.g., 2.5V average for a 5V signal).  
  * A 100% duty cycle means the signal is always ON (5V average).

For motors, a higher duty cycle translates to a higher average voltage delivered to the motor, resulting in faster rotation. Conversely, a lower duty cycle leads to slower rotation.

Diagram Description of PWM:  
Imagine a square wave signal.

* At 0% duty cycle, the line is flat at 0V.  
* At 50% duty cycle, the wave is HIGH for half the period and LOW for the other half.  
* At 100% duty cycle, the line is flat at 5V.  
* Intermediate duty cycles would show the pulse width (ON time) varying, with the frequency of the pulses remaining constant.

### **Arduino PWM Pins**

On the Arduino Uno, not all digital pins are capable of generating true PWM signals. Specific digital pins are marked with a \~ (tilde) symbol (e.g., pins 3, 5, 6, 9, 10, 11). These pins can be used with the analogWrite() function to generate PWM signals. However, when using the Adafruit Motor Shield, the library handles the direct analogWrite() calls for you, abstracting the complexity.

### **Enable Pins for PWM on the L293D Motor Shield**

The L293D motor shield utilizes specific "Enable" pins (often labeled ENA for Motor A and ENB for Motor B) to control the speed of the connected motors via PWM. These pins are internally connected to the Arduino's PWM-capable pins by the shield's design. The Adafruit library manages these connections, allowing you to simply use the setSpeed() function.

For reference, the shield typically sets up the following pin associations:

```cpp
#define ENA 9  // Enable pin for Motor 1 (PWM)
#define ENB 10 // Enable pin for Motor 2 (PWM)
#define IN1 8  // Motor 1 direction pin 1
#define IN2 7  // Motor 1 direction pin 2
#define IN3 6  // Motor 2 direction pin 1
#define IN4 5  // Motor 2 direction pin 2
```

## **Code Example: Variable Speed Control**

Using the setSpeed() function from the Adafruit library, you can easily vary the motor speed from 0 (off) to 255 (maximum speed). This range corresponds to the 8-bit resolution of Arduino's PWM, where 0 is 0% duty cycle and 255 is 100% duty cycle.

```cpp
#include <AFMotor.h> // Include the Adafruit Motor Shield library

AF_DCMotor motor1(1); // M1 port
AF_DCMotor motor2(2); // M2 port

void setup() {
  Serial.begin(9600);
  Serial.println("Variable Speed Motor Test");
}

void loop() {
  // Example 1: Motor 1 at medium speed, Motor 2 off
  Serial.println("Motor 1 at 150, Motor 2 off");
  motor1.setSpeed(150); // Set motor 1 speed to medium (approx. 59% duty cycle)
  motor1.run(FORWARD);
  motor2.setSpeed(0);   // Set motor 2 speed to 0 (off)
  motor2.run(FORWARD);  // Direction still set, but motor will not move
  delay(3000);          // Run for 3 seconds

  // Example 2: Motor 1 at max speed, Motor 2 at slow speed
  Serial.println("Motor 1 at max speed, Motor 2 at slow speed");
  motor1.setSpeed(255); // Max speed (100% duty cycle)
  motor1.run(FORWARD);
  motor2.setSpeed(50);  // Slow speed (approx. 20% duty cycle)
  motor2.run(FORWARD);
  delay(3000);          // Run for 3 seconds

  // Example 3: Gradually increase speed for both motors
  Serial.println("Increasing speed...");
  motor1.run(FORWARD); // Ensure motors are set to run before changing speed
  motor2.run(FORWARD);
  for (int speed = 0; speed <= 255; speed += 5) {
    motor1.setSpeed(speed);
    motor2.setSpeed(speed);
    delay(50); // Small delay to see the gradual increase
  }
  delay(1000); // Hold at max speed for 1 second

  // Example 4: Gradually decrease speed for both motors
  Serial.println("Decreasing speed...");
  for (int speed = 255; speed >= 0; speed -= 5) {
    motor1.setSpeed(speed);
    motor2.setSpeed(speed);
    delay(50); // Small delay to see the gradual decrease
  }
  motor1.run(RELEASE); // Stop motors completely
  motor2.run(RELEASE);
  delay(1000); // Hold at stop for 1 second
}
```

### **Exercises and Questions**

1.  **Finding the "Floor Speed":** Modify the example code to find the lowest integer value (the "floor speed") at which your motors consistently start to turn. This value can vary between motors due to manufacturing tolerances and friction.
    ```arduino
    motor1.setSpeed(X); // Replace X with different integer values (start low, e.g., 10, and increase)
    motor1.run(FORWARD);
    motor2.setSpeed(0);
    motor2.run(FORWARD);
    delay(2000);
    ```
    What factors might influence this "floor speed" for a given motor?
2.  Set one motor to its maximum speed (255) and the other to a very slow speed (e.g., 50). Observe what happens to your robot. Why might you *not* want your robot to operate with such a significant speed difference between its drive motors in a real-world application (e.g., a robot trying to drive in a straight line)? Consider implications for navigation and control.
3.  Experiment with the `motorX.run(RELEASE);` command versus setting `motorX.setSpeed(0);`. Are there any noticeable differences in how the motors stop or behave? (`RELEASE` typically removes power, allowing the motor to coast, while `setSpeed(0)` still applies a 0V PWM signal, which might engage braking depending on the motor driver).

---

**Fun Fact:** While PWM is widely used for motor control, it's also the fundamental principle behind how many modern LED dimmers work, allowing you to smoothly adjust the brightness of lights without changing the actual voltage! It's also used in audio amplifiers and power converters.
