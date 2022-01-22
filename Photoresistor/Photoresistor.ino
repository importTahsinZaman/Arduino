int photoPin = A5;
int lightVal;
int greenPin = 6;
int redPin = 5;
int lightMin = 140;

void setup() {
  // put your setup code here, to run once:
  pinMode (photoPin, INPUT);
  Serial.begin (9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  lightVal = analogRead (photoPin);
  Serial.println (lightVal);

  while (lightVal > lightMin) {
    digitalWrite (greenPin, HIGH);
    digitalWrite (redPin, LOW);
    lightVal = analogRead (photoPin);
    Serial.println (lightVal);
  }

  while (lightVal < lightMin) {
    digitalWrite (redPin, HIGH);
    digitalWrite (greenPin, LOW);
    lightVal = analogRead (photoPin);
    Serial.println (lightVal);
  }

}
