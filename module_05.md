# Module 5: Car Build - Integrating Components

Congratulations on reaching Module 5! At this stage, you have successfully controlled LEDs, understood ultrasonic sensors, driven DC motors for basic movement, and precisely positioned servo motors. Now, it's time to bring all these individual components together to construct your foundational robotic vehicle. This module focuses on the physical assembly and the complete circuit integration of your robot, laying the groundwork for its autonomous behavior.

## The Robotic Platform: Assembling Your Car

While the specific chassis design may vary, the core components for a simple two-wheel drive robotic car typically include:

* **Chassis:** The frame of your robot, often made of acrylic, plastic, or metal.
* **DC Motors (2x):** For driving the wheels.
* **Wheels (2x):** Connected to the DC motors.
* **Caster Wheel/Skid (1x):** A free-rolling wheel or a simple skid at the front or back to provide stability and allow for easy turning.
* **Arduino Uno Board:** The microcontroller brain of your robot.
* **L298N Motor Driver Module:** To power and control the DC motors.
* **Ultrasonic Sensor (e.g., HC-SR04):** For obstacle detection.
* **SG90 Micro Servo Motor:** To allow the ultrasonic sensor to scan its surroundings.
* **External Power Supply:** A battery pack (e.g., 4x AA batteries for 6V, or a 9V battery) to power the L298N module and motors.
* **Breadboard:** A small one may be useful for organizing sensor connections if needed.
* **Jumper Wires:** For all electrical connections.

**Assembly Tips:**

* Mount your DC motors securely to the chassis, ensuring their shafts can connect to the wheels.
* Attach the caster wheel or skid.
* Find a secure place to mount your Arduino Uno.
* Mount the L298N motor driver module. Ensure it's easily accessible for wiring, especially its power terminals.
* Attach the SG90 servo motor to a suitable position (e.g., the front of the chassis).
* Mount the ultrasonic sensor onto the servo's horn or a custom bracket attached to the servo. This setup allows the sensor to "look" in different directions.
* Mount your external battery pack.

## Integrated Circuit Diagram: Bringing it All Together

This diagram describes the complete electrical connections for your autonomous obstacle-avoiding robot, integrating all the components from previous modules.

**Diagram Description:**

Imagine your Arduino Uno board as the central hub. All components branch out from it or from the L298N module.

1.  **Arduino Power & Ground:**

    * Arduino powered via USB or its DC jack.
    * An Arduino `GND` pin is connected to the `GND` terminal of the L298N module (establishing a common ground).
    * The Arduino's 5V pin is connected to the `+5V` (logic input) pin on the L298N module. This is crucial if your L298N's motor power supply is 6V or less, and you've removed the onboard 5V enable jumper.

2.  **L298N Motor Driver Module & DC Motors:**

    * The **external battery pack** (e.g., 4xAA for 6V, or 9V) is connected to the `+12V` (or `+V`) terminal of the L298N module and its `GND` to the L298N's `GND`.
    * DC Motor 1 is connected to `OUT1` and `OUT2` on the L298N.
    * DC Motor 2 is connected to `OUT3` and `OUT4` on the L298N.
    * Arduino Digital Pin 7 connects to `IN1` (L298N).
    * Arduino Digital Pin 8 connects to `IN2` (L298N).
    * Arduino Digital Pin 5 connects to `IN3` (L298N).
    * Arduino Digital Pin 6 connects to `IN4` (L298N).

    * **Crucially:** Ensure the jumpers are on the `ENA` and `ENB` pins of the L298N module to enable motors at full speed, or connect these pins to Arduino Digital Pins 9 and 10 respectively (and drive them HIGH in code if not using jumpers). This diagram assumes `ENA` and `ENB` are jumpered `HIGH` on the L298N module, so no Arduino connections to these pins.

3.  **Ultrasonic Sensor (HC-SR04):**

    * HC-SR04 `VCC` pin to Arduino 5V.
    * HC-SR04 `GND` pin to Arduino `GND`.
    * HC-SR04 `TRIG` pin to Arduino Digital Pin 12.
    * HC-SR04 `ECHO` pin to Arduino Digital Pin 13.

4.  **SG90 Micro Servo Motor:**

    * SG90 `Red` (VCC) wire to Arduino 5V.
    * SG90 `Brown/Black` (GND) wire to Arduino `GND`.
    * SG90 `Orange/Yellow` (Signal) wire to Arduino Digital Pin 9 (often a PWM pin, but the Servo library handles it).

By carefully following these connections, you will have a fully wired robotic platform ready for the autonomous algorithms in the next module. Remember to double-check all polarities and connections before powering up!

---
NEXT ➡️ You are now ready to move on to [Module 6](./module_06.md), algorithm design and optimization!
