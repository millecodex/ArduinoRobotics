/*
Manipulate an LED using Arduino sketch code with a breadboard
*/

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
