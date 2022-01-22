//Servo Setup Code
#include <Servo.h>
Servo myServo;

//Component Pins
int servoPin = 2;

//Servo Positon
int servoPos;

//Delay
int dt = 150;

void setup() {
  Serial.begin (9600);
  myServo.attach (servoPin);
  pinMode (servoPin, OUTPUT);
}

//servo degrees are from 20 - 165
void loop() {
  if (Serial.available() > 0) { // Checks whether data is coming from the serial port
    servoPos = Serial.parseInt(); // Reads the data from the serial port
  }
  
  if (servoPos <= 165 && servoPos >= 20) {
    myServo.write (servoPos);
  }
}
