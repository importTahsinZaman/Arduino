int LEDpin = 4;
int potPin = A0;
int readVal;
int delayTime = 50;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode (potPin, INPUT);
pinMode (LEDpin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

readVal = analogRead(potPin);
Serial.println(readVal);
delay (delayTime);

while (readVal>1000) {
  digitalWrite (LEDpin, HIGH);
  readVal = analogRead(potPin);
  Serial.println(readVal);
  delay (delayTime);
}

digitalWrite (LEDpin, LOW);

}
