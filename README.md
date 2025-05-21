# Welcome to Arduino Robotics!

## Course Introduction
Welcome to the exciting world of Arduino robotics! This course is designed to introduce you to the fundamentals of building and programming your own robots using the versatile Arduino microcontroller platform. Whether you're new to electronics and programming or have some prior experience, this course will provide you with the hands-on skills and theoretical knowledge to bring your robotic creations to life.

Over the next few modules, we will explore everything from the basics of setting up your Arduino and writing your first lines of code to controlling motors, using sensors to perceive the environment, and developing algorithms for autonomous behavior. We'll combine theory with practical exercises, culminating in the construction and programming of your own robotic car.

Robotics is a multidisciplinary field that combines elements of computer science, electrical engineering, and mechanical engineering. The Arduino platform, with its open-source hardware and software, provides an accessible and affordable entry point into this fascinating domain.

**A Little Bit of History:** The Arduino project was started in Ivrea, Italy, in 2005. The goal was to create a simple, low-cost tool for students without a background in electronics and programming to create interactive projects. The name "Arduino" comes from a bar in Ivrea, where some of the founders of the project used to meet. It's named after Arduin of Ivrea, who was King of Italy from 1002 to 1014.

We hope you find this course engaging and rewarding. Let's get started on our journey into robotics!

## Table of Contents

### [Module 0: Setup - Proof of Life](https://github.com/millecodex/ArduinoRobotics/blob/main/Module_00.md)
- Connecting the Arduino board
- Verifying board communication
- Navigating the Arduino IDE (Integrated Development Environment)
- Understanding serial ports

### [Module 1: Turn Out the Lights - The "Blink" Sketch](https://github.com/millecodex/ArduinoRobotics/blob/main/module_01.md)
- Introduction to Arduino programming structure: `setup()` and `loop()`
- Controlling digital outputs: `pinMode()`, `digitalWrite()`
- Introducing timing: `delay()`
- Your first circuit: Blinking an LED

### [Module 1b: Using a Breadboard and an External LED](https://github.com/millecodex/ArduinoRobotics/blob/main/module_01b.md)

### Module 2: Sensing the World - Ultrasonic Obstacle Detection
- Introduction to sensors
- Principles of ultrasonic distance measurement (echolocation)
- Interfacing with the HC-SR04 ultrasonic sensor
- Using the NewPing library
- Reading sensor data via the Serial Monitor

### Module 2b: Creating a Reusable Distance Function

### Module 3: Movement - Motor Control
- Introduction to DC motors
- Controlling motors with digital signals (On/Off)
- Using an H-Bridge motor driver (e.g., L298N)
- Understanding the need for a separate power supply for motors

### Module 3b: Analog Speed Control with Pulse Width Modulation (PWM)

### Module 4: Precision Movement - Servo Control
- Introduction to servo motors
- Understanding positional control
- Interfacing with an SG90 servo motor
- Using the Arduino Servo library

### Module 4b: Creating a Servo Scanning Mechanism

### Module 5: Bringing It All Together - The Car Build
- Mechanical assembly of a robot car chassis
- Integrating motors, sensors, and the Arduino
- Wiring considerations and power management

### Module 6: Intelligence - Algorithm Development and Optimization
- Designing basic robot behaviors (e.g., obstacle avoidance)
- Implementing decision-making in code
- Strategies for testing and debugging
- Optimizing code for efficiency and responsiveness
- Preparing for the Final Competition!

## What You'll Need (General Overview)
- An Arduino Uno (or compatible board)
- A USB cable to connect the Arduino to your computer
- A computer with the Arduino IDE installed
- A breadboard
- Jumper wires
- LEDs
- Resistors (e.g., 220 Ohm for LEDs)
- An ultrasonic sensor (e.g., HC-SR04)
- DC motors (typically two for a small robot car)
- A motor driver (e.g., L298N module or a motor shield)
- A small servo motor (e.g., SG90)
- A robot car chassis (or materials to build one)
- A separate power supply for motors (e.g., a battery pack)

*Specific components for each module will be detailed at the beginning of that module.*

Let's begin with **Module 0** and get your Arduino board set up!
