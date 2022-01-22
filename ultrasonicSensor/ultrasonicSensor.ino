//Ultrasonic Sensor Pins
int trigPin = 4;
int echoPin = 3;
int pingTravelTime;
float pingTravelDistance;
float distanceToTarget;

//LCD Sensor Pins
#include <LiquidCrystal.h>
int rs = 7;
int en = 8;
int d4 = 9;
int d5 = 10;
int d6 = 11;
int d7 = 12;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

//Button Pins
int buttonPin = 5;
int NewButtonVal;
int OldButtonVal = 1;
int state = 0;

void setup() {
  //Ultrasonic Sensor Setup
  pinMode (trigPin, OUTPUT);
  pinMode (echoPin, INPUT);

  //Serial Port Setup
  Serial.begin (9600);

  //LCD setup
  lcd.begin (16, 2);

  //Button Setup
  pinMode (buttonPin, INPUT);
  digitalWrite (buttonPin, HIGH);
}

void loop() {
  NewButtonVal = digitalRead (buttonPin);

  /*
  Serial.print (" Button: ");
  Serial.print (NewButtonVal);
  Serial.print (" State: ");
  Serial.println (state);
  */
  
  delay (150);
  if (NewButtonVal == 1 && OldButtonVal == 0) {
    if (state == 0) {
      state = 1;
    } else {
      state = 0;
    }
  }

  OldButtonVal = NewButtonVal;

  
  if (state == 1){
    digitalWrite (trigPin, LOW);
    delayMicroseconds (10);
    digitalWrite (trigPin, HIGH);
    delayMicroseconds (10);
    pingTravelTime = pulseIn (echoPin, HIGH);
    pingTravelDistance = (pingTravelTime * 765. * 5280. * 12.) / (3600. * 1000000.);
    distanceToTarget = pingTravelDistance / 2;

    lcd.setCursor(0, 0);
    lcd.print ("Distance: ");
    lcd.setCursor(0, 1);
    lcd.print (distanceToTarget);
    lcd.print ("in");
    delay (50);
    lcd.clear();
  }else{
    
  }

  

}
