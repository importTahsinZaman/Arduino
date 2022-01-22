//IR Remote Variables
#include <IRremote.h>
int IRpin = 9;
IRrecv IR(IRpin);
decode_results cmd;
String myComm;

//Buzzer Variables
int buzzerPin = 11;
int buzzDuration = 15;
int buzz1 = 1000;
int buzz2 = 900;
int buzz3 = 800;
int buzz4 = 700;
int buzz5 = 600;
int buzz6 = 500;
int buzz7 = 400;
int buzz8 = 300;


//Counter
int j;

//Delay
int dt = 100;


void setup() {
  //IR Remote Setup
  Serial.begin (9600);
  IR.enableIRIn();

  pinMode (buzzerPin, OUTPUT);

}

void loop() {
  //Looking for Remote Input
  while (IR.decode(&cmd) == 0) { }
  IR.resume();

  //Remote Input Reads
  switch (cmd.value) {
    case 0x807F728D:
      myComm = "one";
      Serial.print (" = ");
      Serial.println (myComm);
      for (j = 1; j <= buzzDuration; j = j + 1) {
        digitalWrite (buzzerPin, HIGH);
        delayMicroseconds(buzz1);
        digitalWrite (buzzerPin, LOW);
        delayMicroseconds(buzz1);
      }
      delay (dt);
      IR.resume();
      break;
    case 0x807FB04F:
      myComm = "two";
      Serial.print (" = ");
      Serial.println (myComm);
      for (j = 1; j <= buzzDuration; j = j + 1) {
        digitalWrite (buzzerPin, HIGH);
        delayMicroseconds(buzz2);
        digitalWrite (buzzerPin, LOW);
        delayMicroseconds(buzz2);
      }
      delay (dt);
      IR.resume();
      break;
    case 0x807F30CF:
      myComm = "three";
      Serial.print (" = ");
      Serial.println (myComm);
      for (j = 1; j <= buzzDuration; j = j + 1) {
        digitalWrite (buzzerPin, HIGH);
        delayMicroseconds(buzz3);
        digitalWrite (buzzerPin, LOW);
        delayMicroseconds(buzz3);
      }
      delay (dt);
      IR.resume();
      break;
    case 0x807F52AD:
      myComm = "four";
      Serial.print (" = ");
      Serial.println (myComm);
      for (j = 1; j <= buzzDuration; j = j + 1) {
        digitalWrite (buzzerPin, HIGH);
        delayMicroseconds(buzz4);
        digitalWrite (buzzerPin, LOW);
        delayMicroseconds(buzz4);
      }
      delay (dt);
      IR.resume();
      break;
    case 0x807F906F:
      myComm = "five";
      Serial.print (" = ");
      Serial.println (myComm);
      for (j = 1; j <= buzzDuration; j = j + 1) {
        digitalWrite (buzzerPin, HIGH);
        delayMicroseconds(buzz5);
        digitalWrite (buzzerPin, LOW);
        delayMicroseconds(buzz5);
      }
      delay (dt);
      IR.resume();
      break;
    case 0x807F10EF:
      myComm = "six";
      Serial.print (" = ");
      Serial.println (myComm);
      for (j = 1; j <= buzzDuration; j = j + 1) {
        digitalWrite (buzzerPin, HIGH);
        delayMicroseconds(buzz6);
        digitalWrite (buzzerPin, LOW);
        delayMicroseconds(buzz6);
      }
      delay (dt);
      IR.resume();
      break;
    case 0x807F629D:
      myComm = "seven";
      Serial.print (" = ");
      Serial.println (myComm);
      for (j = 1; j <= buzzDuration; j = j + 1) {
        digitalWrite (buzzerPin, HIGH);
        delayMicroseconds(buzz7);
        digitalWrite (buzzerPin, LOW);
        delayMicroseconds(buzz7);
      }
      delay (dt);
      IR.resume();
      break;
    case 0x807FA05F:
      myComm = "eight";
      Serial.print (" = ");
      Serial.println (myComm);
      for (j = 1; j <= buzzDuration; j = j + 1) {
        digitalWrite (buzzerPin, HIGH);
        delayMicroseconds(buzz8);
        digitalWrite (buzzerPin, LOW);
        delayMicroseconds(buzz8);
      }
      delay (dt);
      IR.resume();
      break;
    case 0x807F02FD:
      myComm = "pwr";
      Serial.print (" = ");
      Serial.println (myComm);
      delay (dt);
      IR.resume();
      break;
  }
}
