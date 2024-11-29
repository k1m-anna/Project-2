#include <Servo.h>

// Servo objects for the two servos
Servo forestDvalinServo, forestVentiServo;

// Digital Pins for Servos
int firstServoDvalin = 12; // Pin for the first servo (first Dvalin in forest)
int secondServoVenti = 11; // Pin for the second servo (first Venti in forest)

// Button Pins
int forestLuminePin = 13; // Pin for the first button (first Lumine in forest)
int forestVentiPin;  // Pin for the second button (first Venti in forest)

// Setup function
void setup()
{
  // Configure button pins as input with pull-up resistors
  pinMode(forestLuminePin, INPUT_PULLUP);
  pinMode(forestVentiPin, INPUT_PULLUP);

  // Attach servos to their respective pins
  forestDvalinServo.attach(firstServoDvalin);
  forestVentiServo.attach(secondServoVenti);

  // Reset servo positions
  //forestDvalinServo.write(0);
  //forestVentiServo.write(0);

  // Initialize serial communication for debugging
  Serial.begin(9600);
}

// Loop function
void loop()
{ 
  // Read the state of the first button
  int buttonState1 = digitalRead(forestLuminePin);

   // Control the first servo
    if (buttonState1 == LOW){
      forestDvalinServo.write(0);
    }
    
    if (buttonState1 == HIGH) {
        // First button is high (pressed), set the first servo to 100 degrees
        forestDvalinServo.write(120);

  }
}
