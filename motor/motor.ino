int speedPin = 5;
int dir1 = 4;
int dir2 = 3;
int mSpeed;
int potPin = A0;
int potVal;
int buttonPin = 6;
int NewButtonVal;
int OldButtonVal = 1;
int mState = 0;
int tiltPin = 7;
int tiltVal;

void setup() {
  pinMode (speedPin, OUTPUT);
  pinMode (dir1, OUTPUT);
  pinMode (dir2, OUTPUT);
  pinMode (potPin, INPUT);
  pinMode (buttonPin, INPUT);
  digitalWrite (buttonPin, HIGH);
  pinMode (tiltPin, INPUT);
  digitalWrite (tiltPin, HIGH);
  Serial.begin (9600);
}

void loop() {
  NewButtonVal = digitalRead (buttonPin);
  delay (150);
  potVal = analogRead (potPin);
  tiltVal = digitalRead (tiltPin);
  mSpeed = (155. / 1023.) * potVal + 100;
  Serial.print ("Tilt : ");
  Serial.print (tiltVal);
  Serial.print (" Pot: ");
  Serial.print (potVal);
  Serial.print (" Speed: ");
  Serial.print (mSpeed);
  Serial.print (" Button: ");
  Serial.print (NewButtonVal);
  Serial.print (" State: ");
  Serial.println (mState);

  if  (NewButtonVal == 1 && OldButtonVal == 0) {
    if (mState == 0) {
      mState = 1;
    }else {
      mState = 0;
    }
  }
  OldButtonVal = NewButtonVal;

  if (mState == 1){
    digitalWrite (dir1, LOW);
    digitalWrite (dir2, HIGH);
    analogWrite (speedPin, mSpeed);
  }

  if (mState == 0 || tiltVal == 1){
    digitalWrite (dir1, LOW);
    digitalWrite (dir2, HIGH);
    analogWrite (speedPin, 0);
  }
}
