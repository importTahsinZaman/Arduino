//Motor Variables
int speedPin = 5;
int dir1 = 4;
int dir2 = 3;
int mSpeed;
int mState = 0;

//Tilt Sensor Variables
int tiltPin = 7;
int tiltVal;

//Joystick Variables
int xPin = A1;
int yPin = A2;
int buttonPin = 2;
int NewButtonVal;
int OldButtonVal = 1;
int xVal;
int yVal;


void setup() {
  //Motor Pin Modes
  pinMode (speedPin, OUTPUT);
  pinMode (dir1, OUTPUT);
  pinMode (dir2, OUTPUT);
  //Tilt Sensor Pin Modes
  pinMode (tiltPin, INPUT);
  digitalWrite (tiltPin, HIGH);
  //Joystick Pin Modes
  pinMode (xPin, INPUT);
  pinMode (yPin, INPUT);
  pinMode (buttonPin, INPUT);
  digitalWrite (buttonPin, HIGH);
  //Serial
  Serial.begin (9600);
}

void loop() {
  NewButtonVal = digitalRead (buttonPin);
  delay (150);
  tiltVal = digitalRead (tiltPin);
  yVal = analogRead (yPin);


  Serial.print ("Tilt : ");
  Serial.print (tiltVal);
  Serial.print (" Y Value: ");
  Serial.print (yVal);
  Serial.print (" Speed: ");
  Serial.print (mSpeed);
  Serial.print (" Button: ");
  Serial.print (NewButtonVal);
  Serial.print (" State: ");
  Serial.println (mState);

  if  (NewButtonVal == 1 && OldButtonVal == 0) {
    if (mState == 0) {
      mState = 1;
    } else {
      mState = 0;
    }
  }
  OldButtonVal = NewButtonVal;


  if (mState == 1) {
    if (yVal <= 516) {
      mSpeed = (-255. / 516) * (yVal - 516.);
      digitalWrite (dir1, LOW);
      digitalWrite (dir2, HIGH);
      analogWrite (speedPin, mSpeed);
    }
    if (yVal >= 516) {
      mSpeed = (255. / 507) * (yVal - 516.);
      digitalWrite (dir1, HIGH);
      digitalWrite (dir2, LOW);
      analogWrite (speedPin, mSpeed);
    }
  }

  if (mState == 0 || tiltVal == 1) {
    digitalWrite (dir1, LOW);
    digitalWrite (dir2, HIGH);
    analogWrite (speedPin, 0);
  }

}
