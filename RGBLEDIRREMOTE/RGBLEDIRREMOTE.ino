//IR Remote Variables
#include <IRremote.h>
int IRpin = 10;
IRrecv IR(IRpin);
decode_results cmd;
String myComm;

//RGB LED Pins
int redPin = 6;
int greenPin = 5;
int bluePin = 9; // Pin 3 may be broken???? only seems to work when brightness level is at 5

//RGB LED Variables
int totalBrightModes = 5;
int brightMode = 0;
int ledColorState = 0;

//Delay Variable
int dt = 100;

void setup() {
  //IR Remote Setup
  Serial.begin (9600);
  IR.enableIRIn();

  //RGB LED SETUP
  pinMode (redPin, OUTPUT);
  pinMode (greenPin, OUTPUT);
  pinMode (bluePin, OUTPUT);

}

void loop() {
  //Looking for Remote Input
  while (IR.decode(&cmd) == 0) { }
  IR.resume();

  //Remote Input Reads
  switch (cmd.value) {
    case 0xFF906F:
      myComm = "up";
      if (brightMode < totalBrightModes && brightMode >= 0) {
        brightMode = brightMode + 1;
        if (ledColorState == 0) {
          analogWrite (redPin, (255 / totalBrightModes) * brightMode);
          analogWrite (greenPin, (255 / totalBrightModes)*brightMode);
          analogWrite (bluePin, (255 / totalBrightModes)*brightMode);
        } else if (ledColorState == 1) {
          analogWrite (redPin, (255 / totalBrightModes) * brightMode);
          analogWrite (greenPin, (0 / totalBrightModes)*brightMode);
          analogWrite (bluePin, (0 / totalBrightModes)*brightMode);
        } else if (ledColorState == 2) {
          analogWrite (redPin, (0 / totalBrightModes) * brightMode);
          analogWrite (greenPin, (255 / totalBrightModes)*brightMode);
          analogWrite (bluePin, (0 / totalBrightModes)*brightMode);
        } else if (ledColorState == 3) {
          analogWrite (redPin, (0 / totalBrightModes) * brightMode);
          analogWrite (greenPin, (0 / totalBrightModes)*brightMode);
          analogWrite (bluePin, (255 / totalBrightModes)*brightMode);
        } else if (ledColorState == 4) {
          analogWrite (redPin, (0 / totalBrightModes) * brightMode);
          analogWrite (greenPin, (255 / totalBrightModes)*brightMode);
          analogWrite (bluePin, (255 / totalBrightModes)*brightMode);
        } else if (ledColorState == 5) {
          analogWrite (redPin, (255 / totalBrightModes) * brightMode);
          analogWrite (greenPin, (0 / totalBrightModes)*brightMode);
          analogWrite (bluePin, (255 / totalBrightModes)*brightMode);
        } else if (ledColorState == 6) {
          analogWrite (redPin, (255 / totalBrightModes) * brightMode);
          analogWrite (greenPin, (255 / totalBrightModes)*brightMode);
          analogWrite (bluePin, (0 / totalBrightModes)*brightMode);
        }
        else if (brightMode == totalBrightModes) {
          brightMode = totalBrightModes;
        }
      }
        delay (dt);
        IR.resume();
        break;
      case 0xFFE01F:
        myComm = "down";
        if (brightMode <= totalBrightModes && brightMode > 0) {
          brightMode = brightMode - 1;
          if (ledColorState == 0) {
            analogWrite (redPin, (255 / totalBrightModes) * brightMode);
            analogWrite (greenPin, (255 / totalBrightModes)*brightMode);
            analogWrite (bluePin, (255 / totalBrightModes)*brightMode);
          } else if (ledColorState == 1) {
            analogWrite (redPin, (255 / totalBrightModes) * brightMode);
            analogWrite (greenPin, (0 / totalBrightModes)*brightMode);
            analogWrite (bluePin, (0 / totalBrightModes)*brightMode);
          } else if (ledColorState == 2) {
            analogWrite (redPin, (0 / totalBrightModes) * brightMode);
            analogWrite (greenPin, (255 / totalBrightModes)*brightMode);
            analogWrite (bluePin, (0 / totalBrightModes)*brightMode);
          } else if (ledColorState == 3) {
            analogWrite (redPin, (0 / totalBrightModes) * brightMode);
            analogWrite (greenPin, (0 / totalBrightModes)*brightMode);
            analogWrite (bluePin, (255 / totalBrightModes)*brightMode);
          } else if (ledColorState == 4) {
            analogWrite (redPin, (0 / totalBrightModes) * brightMode);
            analogWrite (greenPin, (255 / totalBrightModes)*brightMode);
            analogWrite (bluePin, (255 / totalBrightModes)*brightMode);
          } else if (ledColorState == 5) {
            analogWrite (redPin, (255 / totalBrightModes) * brightMode);
            analogWrite (greenPin, (0 / totalBrightModes)*brightMode);
            analogWrite (bluePin, (255 / totalBrightModes)*brightMode);
          } else if (ledColorState == 6) {
            analogWrite (redPin, (255 / totalBrightModes) * brightMode);
            analogWrite (greenPin, (255 / totalBrightModes)*brightMode);
            analogWrite (bluePin, (0 / totalBrightModes)*brightMode);
          }
        } else if (brightMode == 0) {
          brightMode = 0;
        }
        delay (dt);
        IR.resume();
        break;
      case 0xFF6897:
        myComm = "zero";
        ledColorState = 0;
        analogWrite (redPin, (255 / totalBrightModes) * brightMode);
        analogWrite (greenPin, (255 / totalBrightModes)*brightMode);
        analogWrite (bluePin, (255 / totalBrightModes)*brightMode);
        IR.resume();
        break;
      case 0xFF30CF:
        myComm = "one";
        ledColorState = 1;
        analogWrite (redPin, (255 / totalBrightModes) * brightMode);
        analogWrite (greenPin, (0 / totalBrightModes)*brightMode);
        analogWrite (bluePin, (0 / totalBrightModes)*brightMode);
        IR.resume();
        break;
      case 0xFF18E7:
        myComm = "two";
        ledColorState = 2;
        analogWrite (redPin, (0 / totalBrightModes) * brightMode);
        analogWrite (greenPin, (255 / totalBrightModes)*brightMode);
        analogWrite (bluePin, (0 / totalBrightModes)*brightMode);
        IR.resume();
        break;
      case 0xFF7A85:
        myComm = "three";
        ledColorState = 3;
        analogWrite (redPin, (0 / totalBrightModes)*brightMode);
        analogWrite (greenPin, (0 / totalBrightModes)*brightMode);
        analogWrite (bluePin, (255 / totalBrightModes)*brightMode);
        IR.resume();
        break;
      case 0xFF10EF:
        myComm = "four";
        ledColorState = 4;
        analogWrite (redPin, (0 / totalBrightModes)*brightMode);
        analogWrite (greenPin, (255 / totalBrightModes)*brightMode);
        analogWrite (bluePin, (255 / totalBrightModes)*brightMode);
        IR.resume();
        break;
      case 0xFF38C7:
        myComm = "five";
        ledColorState = 5;
        analogWrite (redPin, (255 / totalBrightModes)*brightMode);
        analogWrite (greenPin, (0 / totalBrightModes)*brightMode);
        analogWrite (bluePin, (255 / totalBrightModes)*brightMode);
        IR.resume();
        break;
      case 0xFF5AA5:
        myComm = "six";
        ledColorState = 6;
        analogWrite (redPin, (255 / totalBrightModes) * brightMode);
        analogWrite (greenPin, (255 / totalBrightModes)*brightMode);
        analogWrite (bluePin, (0 / totalBrightModes)*brightMode);
        IR.resume();
        break;
      case 0xFFE21D:
        myComm = "stp";
        analogWrite (redPin, 0);
        analogWrite (greenPin, 0);
        analogWrite (bluePin, 0);
        delay (dt);
        IR.resume();
        break;
      case 0xFFA25D:
        myComm = "pwr";
        brightMode = 5;
        analogWrite (redPin, 255);
        analogWrite (greenPin, 255);
        analogWrite (bluePin, 255);
        delay (dt);
        IR.resume();
        break;
  }
  
  Serial.print ("Input Button: ");
  Serial.print (myComm);
  Serial.print (" Color: ");
  Serial.print (ledColorState);
  Serial.print (" Brightness: ");
  Serial.println (brightMode);
  
  
}
