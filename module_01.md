# **Module 1: Turn Out the Lights \- Basic LED Control**

Welcome to Module 1\! In this module, you will embark on your first practical experience with Arduino by learning to control the built-in LED on your Arduino board. This foundational exercise, often called the "Blink" sketch, is the "Hello World" of microcontrollers and will introduce you to the core structure of Arduino programs and essential functions.

## **Understanding the Arduino Program Structure**

Every Arduino program, also known as a "sketch," has two main functions that are crucial for its operation:

<img src="https://github.com/user-attachments/assets/6a80a8ec-36e2-4dc7-a04d-291eba660f66" alt="Arduino IDE Serial Monitor Output" width="500px" height="auto">


* `void setup()`: This function runs only once when the Arduino board is powered on or reset. It's used to initialize settings, configure pins as `INPUT` or `OUTPUT`, and start any libraries you might be using. Think of it as the setup phase for your project.
* `void loop()`: This function runs continuously after the `setup()` function has completed. As its name suggests, it "loops" repeatedly, executing the code within it over and over again. This is where the main logic of your program resides, controlling the actions of your Arduino.

## **Essential Arduino Functions**

To control the LED, we will use a few fundamental functions:

* `pinMode(pin, mode)`: This function configures a specified pin to behave either as an `INPUT` or an `OUTPUT`. For controlling an LED, we need to set the pin as an `OUTPUT` so the Arduino can send electrical signals to it.
    * `pin`: The number of the digital pin you want to configure.
    * `mode`: Either `INPUT`, `OUTPUT`, or `INPUT_PULLUP`.
* `digitalWrite(pin, value)`: This function writes a `HIGH` or `LOW` value to a digital pin.
    * `pin`: The number of the digital pin you want to write to.
    * `value`: `HIGH` (which is typically 5 Volts) to turn something on, or `LOW` (0 Volts) to turn something off.
* `delay(ms)`: This function pauses the program for a specified amount of time (in milliseconds).
    * `ms`: The number of milliseconds to pause. There are 1000 milliseconds in 1 second.

## **The Blink Sketch**

The Blink sketch is a classic example that demonstrates how to turn an LED on and off repeatedly. The Arduino Uno board has a built-in LED connected to digital pin 13, which is conveniently referred to as LED\_BUILTIN in the Arduino IDE.

To load the Blink sketch:

1. Open the Arduino IDE.  
2. Go to File \-\> Examples \-\> 01.Basics \-\> Blink. A *new* Arduino interface will open, this is normal behaviour.

```cpp
Here is the code for the Blink sketch:
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
}
```

### **Code Explanation:**

- `pinMode(LED_BUILTIN, OUTPUT);`: In the `setup()` function, this line initializes the `LED_BUILTIN` pin as an `OUTPUT`. This prepares the pin to send electrical signals to control the LED.  
- `digitalWrite(LED_BUILTIN, HIGH);`: In the `loop()` function, this line sets the voltage on `LED_BUILTIN` to `HIGH`, which turns the LED on.  
- `delay(1000);`: This line pauses the program for 1000 milliseconds (1 second), keeping the LED on for that duration.  
- `digitalWrite(LED_BUILTIN, LOW);`: This line then sets the voltage on `LED_BUILTIN` to `LOW`, turning the LED off.  
- `delay(1000);`: Another 1000 millisecond delay keeps the LED off for 1 second.
This sequence of turning the LED on, waiting, turning it off, and waiting, repeats indefinitely, creating the blinking effect.

## **Uploading Your Sketch**

To get your code onto the Arduino board, you need to upload it. This process involves two main steps:

1.  **Open Serial Monitor:** Click the 🔍 (spy glass) in the top right, this will show you communication information.
2.  **Compiling the Sketch:** Click the ✅ (check). The Arduino IDE translates your human-readable C++ code into machine code that the Arduino's microcontroller can understand.
3.  **Sending the Code to the Board:** Click the ➡️ (right arrow). The compiled code is then sent from your computer to the Arduino board via the USB cable.
   
During the upload process, you will typically observe the **TX (Transmit)** and **RX (Receive)** LEDs on your Arduino board flashing rapidly. This indicates data communication between your computer and the board.

## **Did it Work?**

If the L LED on the board is flashing (at a rate of once per second), then it works! Hooray! Alternatively, open the Output in the serial monitor and you will see any error messages here. No error messages is good news and you'll get some information about the storage space.

![image](https://github.com/user-attachments/assets/289d538b-10f6-49d4-a887-6ffc632091df)

**Troubleshooting Tip:** If you encounter issues, ensure you have selected the correct Arduino board type (Tools \-\> Board) and the correct serial port (Tools \-\> Port). If the port is not listed or appears as "not connected," try unplugging and replugging your Arduino, or restarting the IDE.

## **Theory: Arduino Uno Pins and Architecture**

The Arduino Uno is a popular microcontroller board based on the ATmega328P. It has a set of digital and analog input/output (I/O) pins that allow you to connect various components and sensors.

### Pins
![image](https://github.com/user-attachments/assets/57743a74-15b1-4afd-b72b-78144397e5d0)
[image credit: Pija Education](https://pijaeducation.com/arduino/introduction-arduino/arduino-uno/)

* At the top, there's a USB port for power and communication with your computer.  
* Near the USB port, you'll see a power jack for external power supply.  
* Along the edges of the board, there are rows of header pins.  
  * One side typically has Digital Pins (0-13), including the LED\_BUILTIN on pin 13\. These pins can be configured as either inputs or outputs and can read/write digital signals (HIGH or LOW).  
  * The other side has Analog Input Pins (A0-A5), which can read a range of voltage values, useful for sensors that provide varying outputs.  
  * You'll also find GND (Ground) pins and 5V / 3.3V power supply pins.  
* The central component is the ATmega328P microcontroller chip, the "brain" of the Arduino.

Understanding these pins is crucial as you begin to connect external components and build more complex circuits.

### Architecture (Components & Design)
![image](https://github.com/user-attachments/assets/0846a2ce-cfa2-493e-84c8-4e348379965b)
[image credit: Pija Education](https://pijaeducation.com/arduino/introduction-arduino/arduino-uno/)




## **Exercises and Questions**

1. How many milliseconds are in a second?  
2. Modify the `delay()` values in the Blink sketch to make the LED blink faster. For example, try `delay(100)` for both `HIGH` and `LOW` states.  
3. Experiment with different `delay()` values for the `HIGH` and `LOW` states (e.g., LED on for 200ms, off for 800ms). How does this affect the perceived blinking pattern?  
4. Observe the TX and RX LEDs on your Arduino board while uploading the sketch. Describe their behavior.
