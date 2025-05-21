# **Module 2: Ultrasonic Sensor \- Obstacle Detection**

In this module, we will integrate an ultrasonic sensor into your Arduino projects. Ultrasonic sensors are crucial for robotic applications as they allow your robot to perceive its environment by detecting obstacles and measuring distances. This capability is fundamental for tasks such as automatic braking, navigation in autonomous vehicles (like self-driving cars), and robotic vacuum cleaners (e.g., Roomba).

## **How Ultrasonic Sensors Work: Echolocation**

Ultrasonic sensors operate on the principle of echolocation, similar to how bats and dolphins navigate their surroundings. The sensor emits a high-frequency sound wave (ultrasound) that is inaudible to humans. This sound wave travels through the air, bounces off an object, and then returns to the sensor. By measuring the time it takes for the sound wave to travel to the object and return, the sensor can calculate the distance to that object.

The fundamental formula for calculating distance based on speed and time is:

Distance=Speed×Time  
In this context, 'Speed' refers to the speed of sound in air (approximately 343 meters per second or 0.0343 cm per microsecond). The 'Time' measured by the sensor is the total time for the sound to travel to the object and back. Therefore, to get the one-way distance, we divide the total time by two.

## **Introducing the NewPing Library**

While you could implement the ultrasonic sensor logic from scratch, the NewPing library by Tim Eckel simplifies the process significantly. It provides robust and efficient functions for interfacing with ultrasonic sensors, making distance measurements simple, fast, and powerful.

### **Installing the NewPing Library:**

1. Open the Arduino IDE.  
2. Go to Sketch \-\> Include Library \-\> Manage Libraries....  
3. In the Library Manager, search for "NewPing".  
4. Select "NewPing by Tim Eckel" and click "Install".

## **Ultrasonic Sensor Pin Setup**

The most common ultrasonic sensor, like the HC-SR04, typically has four or five pins. When using a 4-pin configuration, the OUT pin is usually left unconnected.

Here's a breakdown of the standard pin connections:

| Pin | Function | Arduino Connection |
| :---- | :---- | :---- |
| **VCC** | Power supply (+5V) | 5V |
| **GND** | Ground | GND |
| **TRIG** | Trigger: Send a HIGH pulse (≥10μs) to start ranging | Any digital pin (e.g., 12\) |
| **ECHO** | Echo: Outputs pulse width proportional to distance | Any digital pin (e.g., 13\) |
| **OUT** | Optional: Used for single-pin mode | Leave unconnected in 4-pin mode |

Diagram Description:  
Imagine your Arduino Uno board connected to an ultrasonic sensor. The VCC pin of the sensor is connected to the 5V pin on the Arduino. The GND pin of the sensor is connected to a GND pin on the Arduino. The TRIG pin of the sensor is connected to Arduino's Digital Pin 12\. The ECHO pin of the sensor is connected to Arduino's Digital Pin 13\. The OUT pin of the sensor is left unconnected.

## **Code Example: Reading Distance**

Here is an example sketch to read distance data from your ultrasonic sensor and display it on the Serial Monitor:
```cpp
#include <NewPing.h> // Include the NewPing library

#define TRIGGER_PIN  12  // Arduino pin connected to the trigger pin (TRIG) of the ultrasonic sensor  
#define ECHO_PIN     13  // Arduino pin connected to the echo pin (ECHO) of the ultrasonic sensor  
#define MAX_DISTANCE 200 // Maximum distance (in cm) to ping. Max sensor distance is ~400-450cm.

// NewPing setup of pins and maximum distance.  
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

void setup() {  
  Serial.begin(9600); // Open serial monitor at 9600 baud rate to see sensor output.  
}

void loop() {  
  delay(50); // Wait 50ms between pings (20 pings/sec). This delay is important to avoid sensor interference and allow the sound to travel.

  Serial.print("Ping: ");  
  Serial.print(sonar.ping_cm()); // Send ping, get distance in cm and print to Serial Monitor.  
  Serial.println("cm");  
}
```

### Code Explanation:

- `#include <NewPing.h>`: This line includes the necessary NewPing library, making its functions available in your sketch.  
- `#define TRIGGER_PIN 12` and `#define ECHO_PIN 13`: These lines define constants for the digital pins connected to the `TRIG` and `ECHO` pins of your ultrasonic sensor. Using `#define` is a common practice for constants in Arduino.  
- `#define MAX_DISTANCE 200`: This defines the maximum distance (in centimeters) that the sensor will attempt to measure. Pings beyond this distance will be ignored.  
- `NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);`: This line creates an instance of the `NewPing` object, named `sonar`, associating it with the defined trigger and echo pins, and the maximum distance.  
- `Serial.begin(9600);`: In the `setup()` function, this initializes serial communication at a baud rate of `9600`. This allows your Arduino to send data (like distance readings) back to your computer, which you can view in the Serial Monitor.  
- `delay(50);`: In the `loop()` function, this introduces a small delay between measurements. This is important to prevent "echoes" from one ping interfering with the next, ensuring more accurate readings.  
- `Serial.print("Ping: ");`, `Serial.print(sonar.ping_cm());`, `Serial.println("cm");`: These lines work together to print the measured distance to the Serial Monitor. `sonar.ping_cm()` sends an ultrasonic pulse and returns the distance to the nearest object in centimeters.

## **Viewing Output in Serial Monitor**

After uploading the sketch, open the Serial Monitor in the Arduino IDE (Tools \-\> Serial Monitor). You should see a continuous stream of distance readings, similar to this:

```plaintext
Ping: 188cm  
Ping: 189cm  
Ping: 190cm  
Ping: 189cm
```

## Sensor Characteristics and Considerations

Understanding the specifications of your ultrasonic sensor is important for effective use:

- **Field of View (FOV):** The sensor typically has a narrow beam, often around ±15 degrees. This is its "sight" or effective cone angle within which it can reliably detect objects.  
- **Operating Frequency:** Ultrasonic sensors usually operate at 40 kHz, which is beyond the range of human hearing.  
- **Operating Voltage:** Most ultrasonic sensors are designed to work with 5V DC, making them directly compatible with Arduino Uno boards.  
- **Other Considerations:**  
  - Unlike infrared (IR) sensors, ultrasonic sensors are generally not sensitive to ambient light or optically reflective surfaces.  
  - The maximum reliable range can be influenced by environmental factors such as temperature, humidity, and the nature of the target surface (e.g., soft or absorbent surfaces might not reflect sound well).  
  - If no echo is detected within the `MAX_DISTANCE` or within a fixed timeout (about 200 ms for some sensors), the `ECHO` pin is automatically reset to prevent the program from hanging.

## Exercises and Questions

1. Hold the ultrasonic sensor close to your ear. Can you hear the 40 kHz ultrasonic pulse? Why or why not?  
2. Can you get the sensor to show `0cm` in the Serial Monitor? What does a `0cm` reading signify in the context of this sensor? (Hint: Consider the `MAX_DISTANCE` and what happens when no echo is detected).  
3. **Critical Thinking:** How does the sensor's field of view (±15 degrees) affect the ability of a robotic car to navigate its environment? What challenges might this narrow field of view present, and how could they be overcome?

**Fun Fact:** Did you know that some species of **shrews**, despite their tiny size and poor eyesight, also use echolocation, much like bats, to navigate and hunt for insects in their environment? They emit high-frequency squeaks and listen for the echoes to build a sound map of their surroundings!
