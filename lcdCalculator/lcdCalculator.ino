#include <LiquidCrystal.h>
int rs = 7;
int en = 8;
int d4 = 9;
int d5 = 10;
int d6 = 11;
int d7 = 12;

float firstNumber;
float secondNumber;
String Operator;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  lcd.begin (16, 2);
  Serial.begin (9600);

}

void loop() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print ("Input First Num: ");
  while (Serial.available() == 0) { }
  firstNumber = Serial.parseFloat();
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print ("Input Second Num: ");
  while (Serial.available() == 0) {}
  secondNumber = Serial.parseFloat();
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print ("Input Operator: ");
  while (Serial.available() == 0) { }
  Operator = Serial.readString();
  lcd.clear();

  if (Operator == "*") {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print (firstNumber);
    lcd.print (" * ");
    lcd.print (secondNumber);
    lcd.print (" = ");
    lcd.setCursor(0, 1);
    lcd.print (firstNumber * secondNumber);
    delay (5000);
  }

  if (Operator == "/") {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print (firstNumber);
    lcd.print (" / ");
    lcd.print (secondNumber);
    lcd.print (" = ");
    lcd.setCursor(0, 1);
    lcd.print (firstNumber / secondNumber);
    delay (5000);
  }

  if (Operator == "+") {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print (firstNumber);
    lcd.print (" + ");
    lcd.print (secondNumber);
    lcd.print (" = ");
    lcd.setCursor(0, 1);
    lcd.print (firstNumber + secondNumber);
    delay (5000);
  }

  if (Operator == "-") {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print (firstNumber);
    lcd.print (" - ");
    lcd.print (secondNumber);
    lcd.print (" = ");
    lcd.setCursor(0, 1);
    lcd.print (firstNumber - secondNumber);
    delay (5000);
  }

}
