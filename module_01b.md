# Module 1b: Breadboard LED - External LED Control

In Module 1, you learned to control the built-in LED on your Arduino board. This module extends that knowledge by showing you how to connect and control an external LED using a breadboard. This is a crucial step as it introduces you to connecting external components and building simple circuits, which is fundamental to robotics.

## Why Use a Breadboard?

A breadboard is a solderless construction base used for prototyping electronic circuits. It allows you to quickly assemble and modify circuits by simply plugging in components and wires without the need for soldering. This makes it ideal for experimentation and learning.

## Circuit Theory
< *Jeff will draw a circuit on the board* >

When connecting an external LED, it's important to understand that LEDs are diodes, meaning current flows in only one direction. They also require a current-limiting resistor to prevent them from burning out. The Arduino's digital pins can supply a small amount of current (typically 20mA), which is sufficient for most standard LEDs when paired with an appropriate resistor.

It's worth noting that Arduino's digital pin 13 is internally connected to the `LED_BUILTIN`. This means that if you use pin 13 for an external LED, you are essentially controlling both the external LED and the onboard LED simultaneously. For this module, we will use a different digital pin to demonstrate controlling an LED independently.

## 1. Building the Breadboard Circuit

To build your external LED circuit we'll trace from Positive (Live/Red) to Negative (Ground/Black):

1.  **Connect the Jumper Wire (Live Voltage):** First, take a red jumper wire to represent the live voltage. Connect one end of this jumper wire to Digital Pin 12 on your Arduino board. Connect the other end of this red jumper wire to an empty block on your breadboard. This will serve as the positive connection for your LED.

2.  **Place the LED:** Now, insert the LED into the breadboard. Ensure the longer leg (anode, the positive terminal) is connected to the same breadboard row as the red jumper wire you just connected from Digital Pin 12. The shorter leg (cathode, the negative terminal) should go into a *new*, separate breadboard block.

3.  **Introduce the Resistor (Current Limiter):** To protect your LED, we need to limit the current flow. Take a current-limiting resistor (e.g., 220 Ohm to 330 Ohm). Connect one end of this resistor to the same breadboard row as the shorter leg (cathode) of the LED. Connect the other end of the resistor to another *new*, separate breadboard block.

4.  **Connect to Ground (GND):** Finally, to complete the circuit, take another jumper wire (e.g., black or brown to represent ground). Connect one end of this jumper wire to the breadboard row where the last side of the resistor is connected. Connect the other end of this jumper wire to any `GND` (Ground) pin on your Arduino board.

![image](https://github.com/user-attachments/assets/ab7dc1e8-f97a-48f2-8383-ee2ee77d2cef)


## Defining the Pin in Code

Just like with `LED_BUILTIN`, you need to tell the Arduino which pin your external LED is connected to. We do this by defining a constant integer for the pin number.

## 2. Write the Sketch: Code Example

Click File -> New Sketch. Modify the default sketch to look like the example. (Try typing it yourself rather than copying/pasting.)

```cpp
const int ledPin = 12; // Define the digital pin the LED is connected to

void setup() {  
  // put your setup code here, to run once:  
  pinMode(ledPin, OUTPUT); // Initialize the digital pin as an output.  
}

void loop() {  
  // put your main code here, to run repeatedly:  
  digitalWrite(ledPin, HIGH); // Turn the LED on (HIGH is the voltage level)  
  delay(800);                 // Wait for 800 milliseconds  
  digitalWrite(ledPin, LOW);  // Turn the LED off by making the voltage LOW  
  delay(400);                 // Wait for 400 milliseconds  
}
```

### **Code Explanation:**

- `const int ledPin = 12;`: This line declares a constant integer variable named `ledPin` and assigns it the value `12`. This makes your code more readable and easier to modify if you decide to connect the LED to a different pin later.  
- `void setup() { ... }`: As in Module 1, this function runs once when the Arduino board starts or resets.  
  - `pinMode(ledPin, OUTPUT);`: This configures `ledPin` (which is pin `12` in this case) as an `OUTPUT`. This tells the Arduino that it will be sending electrical signals *out* of this pin to control the LED.  
- `void loop() { ... }`: This function runs repeatedly, creating the blinking effect.  
  - `digitalWrite(ledPin, HIGH);`: This command sets the voltage on `ledPin` to `HIGH` (approximately 5V), turning the LED on.  
  - `delay(800);`: This pauses the program for 800 milliseconds, keeping the LED on for that duration.  
  - `digitalWrite(ledPin, LOW);`: This command sets the voltage on `ledPin` to `LOW` (approximately 0V), turning the LED off.  
  - `delay(400);`: This pauses the program for 400 milliseconds, keeping the LED off for that duration.

## 3. Upload the Module

Upload the Module\_1b\_breadboard\_LED.ino sketch to your Arduino board. Observe the blinking pattern of your external LED.  

## **Exercises and Questions**
1. Experiment with changing the delay() values. How does increasing or decreasing these values affect the blinking speed and pattern?  
2. Try connecting the LED to a different digital pin (e.g., pin 7) and update the ledPin constant in your code accordingly. Does the LED still blink as expected?  
3. What would happen if you omitted the resistor in your LED circuit? Why is it important to include it?

### Fun Fact
The first commercially available Light Emitting Diode (LED) that emitted visible light was red, developed in 1962 by Nick Holonyak Jr. While LEDs are now ubiquitous, it took [decades of research](https://www.simplyled.co.uk/blog/a-brief-history-of-the-light-emitting-diode-led/) to develop the blue LED, which was essential for creating white light LEDs and enabling technologies like LED screens and energy-efficient lighting!

---
NEXT ➡️ You are now ready to move on to [Module 2](./module_02.md), where we'll use an Ultrasonic Sensor!
