int latchPin = 11;
int clockPin = 9;
int dataPin = 12;

byte LED1s = 0b00000000;
byte LED2s = 0b00000000;

int dt = 100;

void setup() {
  pinMode (latchPin, OUTPUT);
  pinMode (dataPin, OUTPUT);
  pinMode (clockPin, OUTPUT);
  Serial.begin (9600);

}

void loop() {

  Serial.println (LED1s, BIN);

  digitalWrite (latchPin, LOW);
  shiftOut (dataPin, clockPin, LSBFIRST, LED1s);
  digitalWrite (latchPin, HIGH);
  
  delay (dt);
  
  LED1s = LED1s + 1;

  if (LED1s == 11111111){
    LED1s = 0;
  }

}
