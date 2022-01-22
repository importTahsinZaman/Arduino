int buttonPin = 5;
int LEDpin = 10;
int buttonOld = 1;
int buttonNew;
int dt = 100;
int IIbuttonPower = 2;
int LEDstate = 0;

void setup() {
  pinMode (LEDpin, OUTPUT);
  pinMode (buttonPin, INPUT);
  digitalWrite (buttonPin, HIGH);
  Serial.begin (9600);
}

void loop() {
  buttonNew = digitalRead (buttonPin);
  Serial.println (buttonNew);

  if (buttonOld == 0 && buttonNew == 1) {
    if (LEDstate == 0){
      digitalWrite(LEDpin, HIGH);
      LEDstate = 1;
    }
    else {
      digitalWrite (LEDpin, LOW);
      LEDstate = 0;
    }
  }
  buttonOld = buttonNew;
  delay (dt);
}
