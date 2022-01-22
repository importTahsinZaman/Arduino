//Servo Setup Code
#include <Servo.h>
Servo myServo;

//Component Pins
int servoPin = 9;
int photoPin = A0;

//Servo Positon
int servoPos;

//Delay
int dt = 150;

//Photo Value
int photoVal;

void setup() {
  Serial.begin (9600);
  myServo.attach (servoPin);
  pinMode (servoPin, OUTPUT);
  pinMode (photoPin, INPUT);
}

void loop() {
  photoVal = analogRead (photoPin);
  Serial.println (servoPos);
  servoPos = 33./89.*(photoVal -500.)+165.;

  myServo.write (servoPos);

}
