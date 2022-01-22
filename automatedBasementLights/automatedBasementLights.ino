//Servo Setup Code
#include <Servo.h>
Servo myServo;

//Component Pins
int servoPin = 2;

//Servo Positon
int servoPos;

int state = 0;

void setup() {
  Serial.begin(9600); // Default communication rate of the Bluetooth module

  myServo.attach (servoPin);
  pinMode (servoPin, OUTPUT);

  myServo.write (165);
  state = 0;
}
void loop() {
  if (Serial.available() > 0) { // Checks whether data is coming from the serial port
    state = Serial.read(); // Reads the data from the serial port
  }
  if (state == '0') {
    myServo.write (165);
    Serial.println("Basement Lights: OFF"); // Send back, to the phone, the String "LED: ON"
  }
  else if (state == '1') {
    myServo.write (20);
    Serial.println("Basement Lights: ON");;
  }
}
