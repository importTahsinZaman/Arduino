#include <LiquidCrystal.h>
int rs = 7;
int en = 8;
int d4 = 9;
int d5 = 10;
int d6 = 11;
int d7 = 12;

float radius;
float area;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  lcd.begin (16, 2);
  Serial.begin (9600);

}

void loop() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print ("Input Radius: ");
  while (Serial.available() == 0) { }
  radius = Serial.parseFloat();
  lcd.clear();

  area = (radius * radius) * 3.14159265359;
  
  lcd.print ("Circle Area: ");
  lcd.setCursor(0, 1);
  lcd.print (area);
  delay(5000);

}
