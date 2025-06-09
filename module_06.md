# Module 6: Algorithm Development and Optimization for Autonomous Robots

Welcome to Module 6! You have successfully assembled your robotic car and wired all its components. Now, it's time to bring your robot to life by programming its "brain" – the algorithms that will allow it to navigate autonomously and avoid obstacles. This module focuses on developing the core logic for an obstacle-avoiding robot, combining everything you've learned so far.

## Autonomous Navigation: The Core Logic

An autonomous obstacle-avoiding robot needs to perform several key tasks continuously:

1.  **Sense:** Use sensors (like the ultrasonic sensor) to gather information about the environment.

2.  **Think/Decide:** Process the sensor data and make decisions based on programmed rules (the algorithm).

3.  **Act:** Execute commands to control actuators (like motors and servos) to respond to the environment.

Our robot will follow a simple reactive algorithm:

* **Move Forward:** Continuously move forward if no obstacles are detected.

* **Detect Obstacle:** Regularly check for obstacles using the ultrasonic sensor.

* **Avoid Obstacle:** If an obstacle is detected within a predefined "danger zone," the robot will:

    * Stop.

    * Reverse.

    * Stop again.

    * Turn (e.g., randomly left or right, or always one direction).

    * Resume moving forward.

The servo will be used to "scan" the area in front of the robot before making a decision, providing a wider field of view for obstacle detection.

## Required Libraries

For this module, you will need to ensure two libraries are installed in your Arduino IDE:

* **`Servo.h`**: For controlling the SG90 servo motor (Module 4 & 4b).

* **`NewPing.h`**: For interfacing with the ultrasonic sensor (Module 2).

If you haven't already, install them via `Sketch` -> `Include Library` -> `Manage Libraries...`.

## Complete Sketch: Obstacle Avoiding Robot

This sketch combines the L298N motor control (digital direction only, assuming ENA/ENB jumpers are HIGH), ultrasonic sensing, and servo scanning to create an autonomous obstacle-avoiding robot.

See the full sketch [here](./sketches/module_06.ino). Open in a separate window to match the explanation.

### Code Explanation:

* **Pin Definitions:** Reuses pin assignments from Modules 3a (L298N `IN` pins), Module 2 (Ultrasonic `TRIGGER`/`ECHO`), and Module 4 (Servo `SERVO_PIN`). `ENA`/`ENB` for the L298N are still assumed to be `HIGH` via jumpers, so they are not connected to Arduino pins.

* **Global Objects:** `NewPing sonar(...)` and `Servo myServo;` are declared globally to be accessible throughout the sketch.

* **Robot Movement Constants:** `#define` statements are used for clarity in movement commands and timing. `DANGER_ZONE_CM` defines how close an object needs to be to trigger avoidance.

* **`setup()` Function:**

  * Initializes serial communication.

  * Sets L298N motor direction pins as `OUTPUT`s.

  * Attaches the `myServo` object to its pin and centers it.

  * Calls `stopMotors()` to ensure the robot is stationary at startup.

* **`loop()` Function (Main Algorithm):**

  * Calls `scanForObstacle()` to get the minimum distance from the current scan.

  * **Decision Logic:**

    * If `distance` is greater than `DANGER_ZONE_CM` (meaning the path is clear) or if `distance == 0` (which `NewPing` returns if no echo is received, often indicating nothing within `MAX_DISTANCE`), the robot `moveForward()` briefly then rescans.

    * If `distance` is within `DANGER_ZONE_CM`, an obstacle is detected, and `avoidObstacle()` is called.

* **`moveForward()`, `moveBackward()`, `turnLeft()`, `turnRight()`, `stopMotors()`:** These are helper functions for controlling the robot's locomotion using the L298N module, building directly from Module 3a's concepts.

* **`scanForObstacle()` Function:**

  * Sweeps the servo through a range of angles (0, 45, 90, 135, 180 degrees in this example).

  * At each angle, it takes an ultrasonic distance reading using `sonar.ping_cm()`.

  * It keeps track of the `minDistance` found during the entire sweep.

  * Returns this `minDistance` after the scan is complete and the servo returns to center.

* **`avoidObstacle()` Function:**

  * Stops the robot immediately.

  * Reverses for `REVERSE_DURATION`.

  * Stops.

  * Executes a `turnRight()` for `TURN_DURATION`. (For a more advanced robot, this turn direction could be chosen based on `scanForObstacle()` data to find the clearest path.)

  * Includes a simple re-check and secondary turn if the path is *still* blocked after the first avoidance maneuver.

## Algorithm Optimization and Future Enhancements

This provided sketch is a basic reactive obstacle avoidance algorithm. For further development and optimization, consider:

1.  **Smarter Turning:** Instead of a fixed turn (e.g., always right), `scanForObstacle()` could return not just the minimum distance but also the *direction* (angle) of the clearest path. The robot could then turn towards that clearest path.

2.  **State Machine:** Implement a state machine (e.g., `STATE_FORWARD`, `STATE_REVERSE`, `STATE_TURN`) to manage robot behavior more robustly, preventing overlapping actions and simplifying complex logic.

3.  **Speed Control:** Introduce variable speed (PWM) using the `ENA`/`ENB` pins (by removing their jumpers and connecting them to Arduino PWM pins like 9 and 10) for smoother acceleration/deceleration and more precise movements.

4.  **Error Handling:** Implement more robust checks for ultrasonic sensor readings (e.g., ignoring spurious values or taking multiple readings).

5.  **Battery Monitoring:** Add code to monitor the battery voltage and alert the user when it's low.

6.  **User Input:** Integrate a remote control (e.g., IR remote, Bluetooth module) to allow manual control alongside autonomous modes.

Hopefully this module will get your autonomous robot exploring its environment. Experiment with the values, test it in different environments, and try to implement some of the suggested optimizations to see your robot's capabilities grow!

