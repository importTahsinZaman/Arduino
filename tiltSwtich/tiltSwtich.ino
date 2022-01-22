int tiltPin = 2;
int tiltVal;
int greenPin = 3;
int redPin = 4;


void setup() {
  pinMode (tiltPin, INPUT);
  pinMode (redPin, OUTPUT);
  pinMode (greenPin, OUTPUT);
  digitalWrite (tiltPin, HIGH);
  Serial.begin (9600);
}

void loop() {
  tiltVal = digitalRead (tiltPin);

  while (tiltVal == 0) {
    tiltVal = digitalRead (tiltPin);
    Serial.println (tiltVal);
    digitalWrite (greenPin, HIGH);
    digitalWrite (redPin, LOW);
  }

  while (tiltVal == 1) {
    tiltVal = digitalRead (tiltPin);
    Serial.println (tiltVal);
    digitalWrite (redPin, HIGH);
    digitalWrite (greenPin, LOW);
  }

}
