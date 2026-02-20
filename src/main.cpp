#include <Arduino.h>

// Create Servo object
Servo axisServo;

// Define PWM pin (Use pin 9)
const int SERVO_PIN = 9;

// Variable to store servo angle
int targetAngle = 0;

void setup() {

  // Initialize Serial communication (9600 baud)
    Serial.begin(9600);

    // Attach servo to PWM pin
    axisServo.attach(SERVO_PIN);

    // Print system initialization message
    Serial.println("MG995 Closed-Loop Axis Control System Initialized");
    Serial.println("Enter angle between 0 and 180 degrees:");
}


void loop() {
// write your code here
}
