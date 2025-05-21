# **Module 1b: Breadboard LED \- External LED Control**

In Module 1, you learned to control the built-in LED on your Arduino board. This module extends that knowledge by showing you how to connect and control an external LED using a breadboard. This is a crucial step as it introduces you to connecting external components and building simple circuits, which is fundamental to robotics.

## **Why Use a Breadboard?**

A breadboard is a solderless construction base used for prototyping electronic circuits. It allows you to quickly assemble and modify circuits by simply plugging in components and wires without the need for soldering. This makes it ideal for experimentation and learning.

## **Circuit Theory**

When connecting an external LED, it's important to understand that LEDs are diodes, meaning current flows in only one direction. They also require a current-limiting resistor to prevent them from burning out. The Arduino's digital pins can supply a small amount of current (typically 20mA), which is sufficient for most standard LEDs when paired with an appropriate resistor.

It's worth noting that Arduino's digital pin 13 is internally connected to the LED\_BUILTIN. This means that if you use pin 13 for an external LED, you are essentially controlling both the external LED and the onboard LED simultaneously. For this module, we will use a different digital pin to demonstrate controlling an LED independently.

## **Building the Breadboard Circuit**

To build your external LED circuit:

1. **Place the LED:** Insert the LED into the breadboard. Remember that the longer leg (anode) is the positive terminal, and the shorter leg (cathode) is the negative terminal.  
2. **Add a Resistor:** Connect one end of a current-limiting resistor (e.g., 220 Ohm to 330 Ohm) to the shorter leg (cathode) of the LED.  
3. **Connect to Ground (GND):** Connect the other end of the resistor to a GND (Ground) pin on your Arduino board.  
4. **Connect to a Digital Pin:** Connect the longer leg (anode) of the LED to a digital I/O pin on your Arduino board (e.g., pin 12).

Diagram Description:  
Imagine your Arduino Uno board connected to a breadboard. On the breadboard, an LED is placed with its longer leg connected to a wire that goes to Arduino's Digital Pin 12\. The shorter leg of the LED is connected to one end of a resistor. The other end of the resistor is connected to a wire that goes to an Arduino GND pin.

## **Defining the Pin in Code**

Just like with LED\_BUILTIN, you need to tell the Arduino which pin your external LED is connected to. We do this by defining a constant integer for the pin number.

## **Code Example**

Here is the Arduino sketch (.ino file) for controlling an external LED:

const int ledPin \= 12; // Define the digital pin the LED is connected to

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

### **Code Explanation:**

* const int ledPin \= 12;: This line declares a constant integer variable named ledPin and assigns it the value 12\. This makes your code more readable and easier to modify if you decide to connect the LED to a different pin later.  
* void setup() { ... }: As in Module 1, this function runs once when the Arduino board starts or resets.  
  * pinMode(ledPin, OUTPUT);: This configures ledPin (which is pin 12 in this case) as an OUTPUT. This tells the Arduino that it will be sending electrical signals *out* of this pin to control the LED.  
* void loop() { ... }: This function runs repeatedly, creating the blinking effect.  
  * digitalWrite(ledPin, HIGH);: This command sets the voltage on ledPin to HIGH (approximately 5V), turning the LED on.  
  * delay(800);: This pauses the program for 800 milliseconds, keeping the LED on for that duration.  
  * digitalWrite(ledPin, LOW);: This command sets the voltage on ledPin to LOW (approximately 0V), turning the LED off.  
  * delay(400);: This pauses the program for 400 milliseconds, keeping the LED off for that duration.

## **Exercises and Questions**

1. Upload the Module\_1b\_breadboard\_LED.ino sketch to your Arduino board. Observe the blinking pattern of your external LED.  
2. Experiment with changing the delay() values. How does increasing or decreasing these values affect the blinking speed and pattern?  
3. Try connecting the LED to a different digital pin (e.g., pin 7\) and update the ledPin constant in your code accordingly. Does the LED still blink as expected?  
4. **Critical Thinking:** What would happen if you omitted the resistor in your LED circuit? Why is it important to include it?
