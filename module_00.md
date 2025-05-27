# Module 0: Setup - Proof of Life

## Welcome to Module 0!

Before we can start building robots and writing code to control them, we need to ensure that your Arduino board is correctly connected to your computer and that the Arduino Integrated Development Environment (IDE) is set up and can communicate with your board. This module is all about getting that "proof of life" – confirming that everything is working as expected.

**What is an Arduino?**
An Arduino is a microcontroller board. Think of it as a tiny, programmable computer that can interact with the physical world through sensors and actuators (like LEDs, motors, etc.). The "brain" of the Arduino Uno, a popular board for beginners, is typically an ATmega328P microcontroller.

**Fun Fact:** The open-source nature of Arduino means that not only is the software free to use and modify, but the hardware designs are also openly available. This has led to a massive community of users, a wide variety of "clone" boards, and an incredible number of shared projects and libraries.

## Step 1: Download and Install the Arduino IDE
### (This is already done in the RMIT Windows Lab)

The Arduino IDE is the software you'll use to write code (called "sketches"), compile it, and upload it to your Arduino board.

1.  Go to the official Arduino website and download the suitable version for your OS: [www.arduino.cc](https://www.arduino.cc/en/software/#ide)

## Step 2: Connect Your Arduino Board

1.  Connect the USB-A end (rectangular) to the computer and the other end (USB-B) to the arduino.
2.  You should see a power LED (often labeled 'ON' or 'PWR') light up on the Arduino board. This indicates that the board is receiving power from your computer. Some boards might also have a pre-loaded "Blink" sketch, causing another LED (often labeled 'L', connected to pin 13) to start blinking.

## Step 3: Configure the Arduino IDE

Now, let's tell the Arduino IDE which board you're using and how to communicate with it.

1.  **Open the Arduino IDE.** You'll see a window with a text editor for writing code, a message area, and a console.

    ![Arduino IDE Interface](https://www.arduino.cc/en/uploads/Main/IDE_0000.png)
    *(Image Credit: Arduino.cc - The Arduino IDE interface)*

2.  **Select Your Board:**
    * Go to **Tools > Board**.
    * Scroll through the list and select "Arduino Uno" (or the specific type of Arduino board you are using if it's different).

    ![IDE Tools > Board Menu](https://docs.arduino.cc/assets/02f37b1717507909786290d1c9508831.png)
    *(Image Credit: Arduino.cc - Selecting the board in the IDE)*

3.  **Select the Serial Port:**
    The serial port is the communication channel your computer uses to talk to the Arduino.
    * Go to **Tools > Port**.
    * You should see a list of available serial ports. The port your Arduino is connected to will usually have "Arduino Uno" or a similar identifier next to it.
        * **Windows:** It will likely be `COMX` (e.g., `COM3`, `COM4`). If you're unsure which one it is, you can disconnect your Arduino, check the list of ports, then reconnect it and see which new port appears.
        * **macOS:** It will likely be something like `/dev/cu.usbmodemXXXX` or `/dev/cu.usbserial-XXXX` (where XXXX is a number or code).
        * **Linux:** It will likely be `/dev/ttyACMX` or `/dev/ttyUSBX` (e.g., `/dev/ttyACM0`). You might need to add your user to the `dialout` group to have permission to access the serial port (`sudo usermod -a -G dialout yourusername`, then log out and log back in).

    If you don't see a port or are unsure:
    * Ensure your USB cable is a data cable (some cheap cables are power-only).
    * Try a different USB port on your computer.
    * Check your system's device manager (Windows) or system information (macOS/Linux) to see if the board is being recognized by the operating system.

    The image from your notes shows a common message if no port is selected:
    ```
    (i) Please select a port to obtain board info.
    ```
    And the status bar might show `[not connected]`:
    ```
    Ln 36, Col 5 Arduino Uno on /dev/cu.usbmodem2101 [not connected]
    ```
    This means you need to complete the "Select the Serial Port" step above.

## Step 4: Verify Communication - "Proof of Life"

Once you've selected the correct board and port, you can verify that the IDE can communicate with your Arduino.

1.  Go to **Tools > Get Board Info**.
2.  If the connection is successful, a small window will pop up displaying information about your board, such as its VID, PID, and Serial Number (SN).

    ![Board Info Dialog](https://user-images.githubusercontent.com/10934705/149621367-4a720d83-63e5-4a4f-9165-3e579e06956c.png)
    *(Example of a "Board Info" dialog. Your details might vary.)*

    This confirms that your computer and the Arduino IDE can "see" and identify your Arduino board. This is our "proof of life"!

## Troubleshooting Common Issues:

* **Board not recognized / Port not appearing:**
    * **Driver Issues (mainly Windows):** Ensure drivers are installed. The Arduino IDE installer usually handles this. If you're using a clone board with a CH340 USB-to-serial chip, you might need to install a separate CH340 driver.
    * **Faulty USB Cable:** Try a different USB cable. Some cables are for charging only and don't transmit data.
    * **Faulty USB Port:** Try a different USB port on your computer.
    * **Insufficient Power:** If using a USB hub, ensure it's a powered hub, or connect the Arduino directly to the computer.
    * **Board Itself:** In rare cases, the Arduino board might be faulty.
* **"Get Board Info" fails or shows errors:**
    * Double-check that you've selected the correct board type in **Tools > Board**.
    * Double-check that you've selected the correct serial port in **Tools > Port**.
    * Try restarting the Arduino IDE.
    * Try disconnecting and reconnecting the Arduino board.

## Quick Tour of the Arduino IDE

* **Verify/Compile Button (✓):** Checks your code for errors and compiles it into machine language that the Arduino can understand.
* **Upload Button (→):** Compiles your code (if not already done) and then uploads it to the Arduino board. You'll often see TX (transmit) and RX (receive) LEDs blink on the Arduino board during an upload.
* **New Sketch (📄):** Opens a new window to start a new project.
* **Open (↑):** Opens an existing sketch.
* **Save (↓):** Saves your current sketch.
* **Serial Monitor (🔍):** Opens a window that allows your Arduino to send messages back to your computer, which is very useful for debugging. We'll use this a lot!
* **Text Editor Area:** This is where you write your Arduino code (sketches).
* **Message Area/Console:** Displays messages from the IDE, including compilation status, errors, and upload progress.

## Questions to Ponder:

1.  Why would someone want their own microcontroller board?
2.  What does it mean if the power LED on your Arduino lights up but the "L" LED (pin 13) doesn't blink?
---
NEXT ➡️ You are now ready to move on to [Module 1](./module_01.md), where you'll write and upload your first sketch to make an LED blink!
