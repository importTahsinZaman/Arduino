//Button Read Pins
int upButtonPin = 12;
int downButtonPin = 11;

//LED & Buzzer Pins
int LEDpin = 10;
int buzzerPin = 9;

//Changing variables
int upButtonRead;
int LEDstate;
float LEDbright = 0;
int downButtonRead;

//Delays
int dt = 300;
int buzzDelay = 250;

//changable LEDmodes
int LEDmodes = 8;

void setup() {
  pinMode (LEDpin, OUTPUT);
  pinMode (buzzerPin, OUTPUT);
  pinMode (upButtonPin, INPUT);
  pinMode (downButtonPin, INPUT);
  Serial.begin (9600);
}

void loop() {
  //Button reads and prints
  upButtonRead = digitalRead (upButtonPin);
  downButtonRead = digitalRead (downButtonPin);
  Serial.print ("Bright Up Button = ");
  Serial.print (upButtonRead);
  Serial.print (" Bright Down Button = ");
  Serial.print (downButtonRead);
  Serial.print (" LED Bright = ");
  Serial.println (LEDbright);

  //LED Brigthener
  if (0 == upButtonRead) {
    LEDstate = LEDstate + 1;
    if (LEDstate > LEDmodes) {
      LEDstate = LEDmodes;
      digitalWrite (buzzerPin, HIGH);
      delay(buzzDelay);
      digitalWrite (buzzerPin, LOW);
    }
    else {
      digitalWrite (buzzerPin, LOW);
    }

    LEDbright = 0 + ((255. / LEDmodes) * LEDstate);
    analogWrite (LEDpin, LEDbright);
    delay (dt);
  }

  //LED Dimmer
  if (0 == downButtonRead) {
    LEDstate = LEDstate - 1;
    if (LEDstate < 0) {
      LEDstate = 0;
      digitalWrite (buzzerPin, HIGH);
      delay(buzzDelay);
      digitalWrite (buzzerPin, LOW);
    }
    else {
      digitalWrite (buzzerPin, LOW);
    }
    LEDbright = 0 + ((255. / LEDmodes) * LEDstate);
    analogWrite (LEDpin, LEDbright);
    delay (dt);
  }


}
