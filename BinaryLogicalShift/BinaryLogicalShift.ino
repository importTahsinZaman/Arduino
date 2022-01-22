int latchPin = 11;
int clockPin = 9;
int dataPin = 12;

byte LED1s;
byte startByte = 0b11111111;

int dt = 100;

void setup() {
  pinMode (latchPin, OUTPUT);
  pinMode (dataPin, OUTPUT);
  pinMode (clockPin, OUTPUT);
  Serial.begin (9600);
  LED1s = startByte;

}

void loop() {
  Serial.print (LED1s, BIN);
  Serial.print ("   ");
  Serial.println (LED1s, DEC);

  digitalWrite (latchPin, LOW);
  shiftOut (dataPin, clockPin, LSBFIRST, LED1s);
  digitalWrite (latchPin, HIGH);

  delay (dt);

  LED1s = LED1s / 2;

  if (LED1s < 1) {
    Serial.print (LED1s, BIN);
    Serial.print ("   ");
    Serial.println (LED1s, DEC);

    digitalWrite (latchPin, LOW);
    shiftOut (dataPin, clockPin, LSBFIRST, 0);
    digitalWrite (latchPin, HIGH);
    delay (dt);
  }
 
}
