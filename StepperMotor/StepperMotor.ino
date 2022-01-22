//THIS CODE DOES NOT WORK!!!!!!!!!

#include <Stepper.h>
int stepsPerRevolution = 2048;
int motSpeed = 10;
Stepper myStepper (stepsPerRevolution, 8, 10, 9, 11);
int dt = 175;
int buttonPin = 2;
int buttonValue;
int stepState = 1;

void setup() {
  Serial.begin (9600);
  myStepper.setSpeed (motSpeed);
  pinMode (buttonPin, INPUT);
  digitalWrite (buttonPin, HIGH);
}

void loop() {

  buttonValue = digitalRead (buttonPin);
  delay(dt);

  if (buttonValue == 0) {
    if (stepState == 1) {
      stepState = -1;
      myStepper.step(1);
    } else {
      stepState = 1;
      myStepper.step (-1);
    }

  }

  Serial.print ("Button Value: ");
  Serial.print (buttonValue);
  Serial.print (" Step State: ");
  Serial.println (stepState);

  // myStepper.step(stepsPerRevolution);
  //  delay(dt);
  //  myStepper.step (-stepsPerRevolution);
  //  delay(dt);
}
