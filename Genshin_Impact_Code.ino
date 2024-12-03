#include <Servo.h>

// Servo objects for the two servos
Servo forestDvalinServo, forestVentiServo, cityTownServo, cliffMachineServo, cliffDvalinServo;

// Digital Pins for Servos
const int firstServoDvalin = 5; // Pin for the first servo (first Dvalin in forest)
const int secondServoVenti = 4; // Pin for the second servo (first Venti in forest)
const int thirdServoTown = 7; // Pin for the third servo (Townspeople in city)
const int fourthServoMachine = 9; // Pin for the fourth servo (Machine in cliff)
const int fifthServoBlueDvalin = 13; // Pin for the fifth servo (Blue Dvalin in cliff)

// Button Pins
const int forestLuminePin = 3; // Pin for the first button (first Lumine in forest)
const int forestLeafPin = 2;  // Pin for the second button (first Venti in forest)
const int cityToolsPin= 6; // Pin for the third button (Toolbox in city)
const int cliffLuminePin = 8; // Pin for the fourth button (second Lumine in cliff)
const int cliffMedicinePin = 12; // Pin for the fifth button (Medicine in cliff)


// Setup function
void setup()
{
  // Attach servos to their respective pins
  forestDvalinServo.attach(firstServoDvalin);
  forestDvalinServo.write(0);
  forestVentiServo.attach(secondServoVenti);
  forestVentiServo.write(0);
  cityTownServo.attach(thirdServoTown);
  cityTownServo.write(0);
  cliffMachineServo.attach(fourthServoMachine);
  cliffMachineServo.write(30);
  cliffDvalinServo.attach(fifthServoBlueDvalin);
  cliffDvalinServo.write(0);

  // Configure button pins as input with pull-up resistors
  pinMode(forestLuminePin, INPUT_PULLUP);
  pinMode(forestLeafPin, INPUT_PULLUP);
  pinMode(cityToolsPin, INPUT_PULLUP);
  pinMode(cliffLuminePin, INPUT_PULLUP);
  pinMode(cliffMedicinePin, INPUT_PULLUP);


  // Initialize serial communication for debugging
  Serial.begin(9600);
}

// Loop function
void loop()
{ 
 // Read the state of the buttons
 int buttonState1 = digitalRead(forestLuminePin);
 int buttonState2 = digitalRead(forestLeafPin);
 int buttonState3 = digitalRead(cityToolsPin);
 int buttonState4 = digitalRead(cliffLuminePin);
 int buttonState5 = digitalRead(cliffMedicinePin);


 // Control the first servo
 if(buttonState1 == LOW)
 {
   forestDvalinServo.write(0);
 }


 if(buttonState1 == HIGH)
 {
   forestDvalinServo.write(120);
 }

// Control the second servo
 if(buttonState2 == LOW)
 {
   forestVentiServo.write(0);
 }


 if(buttonState2 == HIGH)
 {
   forestVentiServo.write(120);
 }

// Control the third servo
 if(buttonState3 == LOW)
 {
  cityTownServo.write(100);
 }

 if(buttonState3 == HIGH)
 {
  cityTownServo.write(0);
 }

 //Control the fourth servo
 if(buttonState4 == LOW)
 {
  cliffMachineServo.write(100);
 }

 if(buttonState4 == HIGH)
 {
  cliffMachineServo.write(40);
 }

 // Control the fifth servo
if(buttonState5 == LOW)
{
  cliffDvalinServo.write(0);
}

if(buttonState5 == HIGH)
{
  cliffDvalinServo.write(180);
}
}
