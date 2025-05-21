# Module 1b: Breadboard LED - External LED Control

In Module 1, you learned to control the built-in LED on your Arduino board. This module extends that knowledge by showing you how to connect and control an external LED using a breadboard. This is a crucial step as it introduces you to connecting external components and building simple circuits, which is fundamental to robotics.

## Why Use a Breadboard?

A breadboard is a solderless construction base used for prototyping electronic circuits. It allows you to quickly assemble and modify circuits by simply plugging in components and wires without the need for soldering. This makes it ideal for experimentation and learning.

## Circuit Theory

When connecting an external LED, it's important to understand that LEDs are diodes, meaning current flows in only one direction. They also require a current-limiting resistor to prevent them from burning out. The Arduino's digital pins can supply a small amount of current (typically 20mA), which is sufficient for most standard LEDs when paired with an appropriate resistor.

It's worth noting that Arduino's digital pin 13 is internally connected to the `LED_BUILTIN`. This means that if you use pin 13 for an external LED, you are essentially controlling both the external LED and the onboard LED simultaneously. For this module, we will use a different digital pin to demonstrate controlling an LED independently.

## Building the Breadboard Circuit

To build your external LED circuit:

1. **Place the LED:** Insert the LED into the breadboard. Remember that the longer leg (anode) is the positive terminal, and the shorter leg (cathode) is the negative terminal.

2. **Add a Resistor:** Connect one end of a current-limiting resistor (e.g., 220 Ohm to 330 Ohm) to the shorter leg (cathode) of the LED.

3. **Connect to Ground (GND):** Connect the other end of the resistor to a GND (Ground) pin on your Arduino board.

4. **Connect to a Digital Pin:** Connect the longer leg (anode) of the LED to a digital I/O pin on your Arduino board (e.g., pin 12).

**Diagram Description:**
Imagine your Arduino Uno board connected to a breadboard. On the breadboard, an LED is placed with its longer leg connected to a wire that goes to Arduino's Digital Pin 12. The shorter leg of the LED is connected to one end of a resistor. The other end of the resistor is connected to a wire that goes to an Arduino GND pin.

## Defining the Pin in Code

Just like with `LED_BUILTIN`, you need to tell the Arduino which pin your external LED is connected to. We do this by defining a constant integer for the pin number.

## Code Example

Here is the Arduino sketch (`.ino` file) for controlling an external LED:
