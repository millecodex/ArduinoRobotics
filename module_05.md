# Module 5: Car Build - Integrating Components

Congratulations on reaching Module 5! At this stage, you have successfully controlled LEDs, understood ultrasonic sensors, driven DC motors for basic movement, and precisely positioned servo motors. Now, it's time to bring all these individual components together to construct your foundational robotic vehicle. This module focuses on the physical assembly and the complete circuit integration of your robot, laying the groundwork for its autonomous behavior.

## The Robotic Platform: Assembling Your Car

This diagram describes the complete electrical connections for your autonomous obstacle-avoiding robot, integrating all the components from previous modules. (Some of the pin numbers may be different to yours.)

![Pasted Graphic 8](https://github.com/user-attachments/assets/ecdeba8f-d9de-445a-85fd-dd52f4eb84d5)


1.  **Arduino Power & Ground:**

    * Arduino powered via USB or its DC jack.
    * An Arduino `GND` pin is connected to the `GND` terminal of the L298N module (establishing a common ground).
    * The Arduino's 5V pin is connected to the `+5V` (logic input) pin on the L298N module. This is crucial since our L298N's motor power supply is 6V or less, and we've removed the onboard 5V jumper.

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

By carefully following these connections, you will have a fully wired robotic platform ready for the autonomous algorithms in the next module. Remember to double-check all connections before powering up!

![image](https://github.com/user-attachments/assets/3f80f2f5-baff-4169-a4e6-aae2b529f31a)

> Quite a nest of wires! Perhaps you can have better wire management and organisation thank me

---
NEXT ➡️ You are now ready to move on to [Module 6](./module_06.md), algorithm design and optimization!
