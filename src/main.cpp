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
  // Check if Serial data is available
    if (Serial.available() > 0) {

        // Read integer angle input from Serial
        targetAngle = Serial.parseInt();

        // Validate angle range (0–180)
        if (targetAngle >= 0 && targetAngle <= 180) {

            // Move servo
            axisServo.write(targetAngle);

            // Print confirmation message
            Serial.print("Servo moved to: ");
            Serial.print(targetAngle);
            Serial.println(" degrees");
        }
      else {
            // Print error message
            Serial.println("Error: Invalid angle. Enter value between 0 and 180.");
        }

        // Clear any remaining serial buffer
        while (Serial.available() > 0) {
            Serial.read();
        }
    }
}
