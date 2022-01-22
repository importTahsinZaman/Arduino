#include <DHT.h>
#define Type DHT11
int sensePin = 2;
DHT HT(sensePin, Type);
float humidity;
float tempC;
float tempF;
int setTime = 500;

#include <LiquidCrystal.h>
int rs = 7;
int en = 8;
int d4 = 9;
int d5 = 10;
int d6 = 11;
int d7 = 12;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  lcd.begin (16, 2);
  Serial.begin (9600);
  HT.begin ();
  delay(setTime);
}

void loop() {
  humidity = HT.readHumidity();
  tempC = HT.readTemperature();
  tempF = HT.readTemperature(true);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print (" Temp: ");
  lcd.print (tempF);
  lcd.print ("F ");
  lcd.setCursor(0, 1);
  lcd.print("Humidity: ");
  lcd.print(humidity);
  delay (250);
}
