#include <NewPing.h>     // Ultrasonic sensor library (install via Library Manager)

#define TRIGGER_PIN   12 // Arduino pin connected to sensor TRIG
#define ECHO_PIN      13 // Arduino pin connected to sensor ECHO
#define MAX_DISTANCE 200 // Maximum distance to ping for (in cm)

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // Initialize ultrasonic sensor

int distance;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // Open serial monitor at 115200 baud to see ping results.
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(50); // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  Serial.print("Ping: ");
  Serial.print(sonar.ping_cm()); // Send ping, get distance in cm and print result (0 = outside set distance range)
  Serial.println("cm");
}
