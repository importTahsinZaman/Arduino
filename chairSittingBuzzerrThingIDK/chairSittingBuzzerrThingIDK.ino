//Ultrasonic Sensor Pins
int trigPin = 6;
int echoPin = 5;
int pingTravelTime;
float pingTravelDistance;
float distanceToTarget;

//lcd pins
#include <LiquidCrystal.h>
int rs = 7;
int en = 8;
int d4 = 9;
int d5 = 10;
int d6 = 11;
int d7 = 12;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

//Buzzer pin
int buzzerPin = 4;

//Chair sitting variables
int maxDistance = 30;
int chairSitTime = 1500; //PUT THIS VALUE IN SECONDS
int buzzTime = 3000; //milliseconds
int secondsSitting = 0;

//sensor accuracy variables
int readings = 50;
float avgDistanceToTarget;


void setup() {
  //lcd Setup
  lcd.begin (16, 2);

  //Ultrasonic Sensor Setup
  pinMode (trigPin, OUTPUT);
  pinMode (echoPin, INPUT);

  //Buzzer Setup
  pinMode (buzzerPin, OUTPUT);

  //Serial Port Setup
  Serial.begin (9600);

}

void loop() {
  float bucket = 0;

  for (int j = 0; j < readings; j++) {
    digitalWrite (trigPin, LOW);
    delayMicroseconds (10);
    digitalWrite (trigPin, HIGH);
    delayMicroseconds (10);
    pingTravelTime = pulseIn (echoPin, HIGH);
    pingTravelDistance = (pingTravelTime * 765. * 5280. * 12.) / (3600. * 1000000.);
    distanceToTarget = pingTravelDistance / 2;
    bucket = bucket + distanceToTarget;
  }

  avgDistanceToTarget = bucket / readings;

  lcd.clear();
  lcd.setCursor (0, 0);
  lcd.print ("Distance: ");
  lcd.print (avgDistanceToTarget);


  Serial.print (avgDistanceToTarget);
  Serial.println (" in");

  while (avgDistanceToTarget < maxDistance) {
    for (int j = 0; j < chairSitTime; j++) {
      bucket = 0;
      for (int j = 0; j < readings; j++) {
        digitalWrite (trigPin, LOW);
        delayMicroseconds (10);
        digitalWrite (trigPin, HIGH);
        delayMicroseconds (10);
        pingTravelTime = pulseIn (echoPin, HIGH);
        pingTravelDistance = (pingTravelTime * 765. * 5280. * 12.) / (3600. * 1000000.);
        distanceToTarget = pingTravelDistance / 2;
        bucket = bucket + distanceToTarget;
      }
      avgDistanceToTarget = bucket / readings;

      if (avgDistanceToTarget > maxDistance) {
        secondsSitting = 0;
        digitalWrite (buzzerPin, LOW);
        break;
      }


      Serial.print (avgDistanceToTarget);
      Serial.print (" in");
      Serial.print (" *Sitting* ");
      secondsSitting = secondsSitting + 1;
      Serial.print ("Seconds Sitting: ");
      Serial.println (secondsSitting);
      delay (1000);

      lcd.clear();
      lcd.setCursor (0, 0);
      lcd.print ("Distance: ");
      lcd.print (avgDistanceToTarget);
      lcd.setCursor (0, 1);
      lcd.print ("Sitting: ");
      lcd.print (secondsSitting);
      lcd.print (" Sec");
    }
    if (avgDistanceToTarget > maxDistance) {
      secondsSitting = 0;
      digitalWrite (buzzerPin, LOW);
      break;
    }
    Serial.println ("INITIALIZED");
    digitalWrite (buzzerPin, HIGH);
    delay (buzzTime);

    if (avgDistanceToTarget > maxDistance) {
      secondsSitting = 0;
      digitalWrite (buzzerPin, LOW);
      break;
    }
  }
}
