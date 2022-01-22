//Servo Setup Code
#include <Servo.h>
Servo myServo;

//Component Pins
int servoPin = 9;

//Servo Positon
int servoPos;

void setup() {
  Serial.begin (9600);
  myServo.attach (servoPin);
  pinMode (servoPin, OUTPUT);
}

void loop() {
  while (1){
    if (Serial.available()>0){
     servoPos = Serial.read();
     myServo.write (servoPos); 
    }
  }
}
