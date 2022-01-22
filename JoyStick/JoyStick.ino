#include <Servo.h>
Servo myServo;
int servoPin = 10;
int servoPower = 11;
float servoAngle;
int yPin = A1;
int xPin = A0;
int switchPin = 3;
int xVal;
int yVal;
int switchVal;
int dt = 100;

void setup() {
  Serial.begin (9600);
  pinMode (yPin, INPUT);
  myServo.attach(servoPin);
}

void loop() {
  xVal = analogRead (xPin);
  digitalWrite (servoPower, HIGH);

  //  Serial.print (" Y Value: ");
  //  Serial.print (yVal);

  servoAngle = (82.5 / 527.) * (xVal - 1023) + 165;
  Serial.println (servoAngle);
  myServo.write(servoAngle);

}
