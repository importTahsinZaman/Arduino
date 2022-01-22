//IR Remote Variables
#include <IRremote.h>
int IRpin = 10;
IRrecv IR(IRpin);
decode_results cmd;
String myComm;

//LED pins Setups
int LED1pin = 2;
int LED2pin = 3;
int LED3pin = 4;
int LED4pin = 5;
int LED5pin = 6;
int LED6pin = 7;
int LED7pin = 8;
int LED8pin = 9;

//LED states Variables
int LED1state = 0;
int LED2state = 0;
int LED3state = 0;
int LED4state = 0;
int LED5state = 0;
int LED6state = 0;
int LED7state = 0;
int LED8state = 0;
int allLEDstate = 0;

//Delay Variable
int dt = 100;

void setup() {
  //IR Remote Setup
  Serial.begin (9600);
  IR.enableIRIn();

  //LED Pin Setups
  pinMode (LED1pin, OUTPUT);
  pinMode (LED2pin, OUTPUT);
  pinMode (LED3pin, OUTPUT);
  pinMode (LED4pin, OUTPUT);
  pinMode (LED5pin, OUTPUT);
  pinMode (LED6pin, OUTPUT);
  pinMode (LED7pin, OUTPUT);
  pinMode (LED8pin, OUTPUT);
}

void loop() {
  //Looking for Remote Input
  while (IR.decode(&cmd) == 0) { }
  IR.resume();

  //Remote Input Reads
  switch (cmd.value) {
    case 0xFF30CF:
      myComm = "one";
      Serial.print (" = ");
      Serial.println (myComm);
      if (LED1state == 0) {
        LED1state = 1;
        digitalWrite (LED1pin, HIGH);
      } else {
        LED1state = 0;
        digitalWrite (LED1pin, LOW);
      }
      delay (dt);
      IR.resume();
      break;
    case 0xFF18E7:
      myComm = "two";
      Serial.print (" = ");
      Serial.println (myComm);
      if (LED2state == 0) {
        LED2state = 1;
        digitalWrite (LED2pin, HIGH);
      } else {
        LED2state = 0;
        digitalWrite (LED2pin, LOW);
      }
      delay (dt);
      IR.resume();
      break;
    case 0xFF7A85:
      myComm = "three";
      Serial.print (" = ");
      Serial.println (myComm);
      if (LED3state == 0) {
        LED3state = 1;
        digitalWrite (LED3pin, HIGH);
      } else {
        LED3state = 0;
        digitalWrite (LED3pin, LOW);
      }
      delay (dt);
      IR.resume();
      break;
    case 0xFF10EF:
      myComm = "four";
      Serial.print (" = ");
      Serial.println (myComm);
      if (LED4state == 0) {
        LED4state = 1;
        digitalWrite (LED4pin, HIGH);
      } else {
        LED4state = 0;
        digitalWrite (LED4pin, LOW);
      }
      delay (dt);
      IR.resume();
      break;
    case 0xFF38C7:
      myComm = "five";
      Serial.print (" = ");
      Serial.println (myComm);
      if (LED5state == 0) {
        LED5state = 1;
        digitalWrite (LED5pin, HIGH);
      } else {
        LED5state = 0;
        digitalWrite (LED5pin, LOW);
      }
      delay (dt);
      IR.resume();
      break;
    case 0xFF5AA5:
      myComm = "six";
      Serial.print (" = ");
      Serial.println (myComm);
      if (LED6state == 0) {
        LED6state = 1;
        digitalWrite (LED6pin, HIGH);
      } else {
        LED6state = 0;
        digitalWrite (LED6pin, LOW);
      }
      delay (dt);
      IR.resume();
      break;
    case 0xFF42BD:
      myComm = "seven";
      Serial.print (" = ");
      Serial.println (myComm);
      if (LED7state == 0) {
        LED7state = 1;
        digitalWrite (LED7pin, HIGH);
      } else {
        LED7state = 0;
        digitalWrite (LED7pin, LOW);
      }
      delay (dt);
      IR.resume();
      break;
    case 0xFF4AB5:
      myComm = "eight";
      Serial.print (" = ");
      Serial.println (myComm);
      if (LED8state == 0) {
        LED8state = 1;
        digitalWrite (LED8pin, HIGH);
      } else {
        LED8state = 0;
        digitalWrite (LED8pin, LOW);
      }
      delay (dt);
      IR.resume();
      break;
    case 0xFFA25D:
      myComm = "pwr";
      Serial.print (" = ");
      Serial.println (myComm);
      if (allLEDstate==0) {
          LED1state = 1;
          digitalWrite (LED1pin, HIGH);
          LED2state = 1;
          digitalWrite (LED2pin, HIGH);
          LED3state = 1;
          digitalWrite (LED3pin, HIGH);
          LED4state = 1;
          digitalWrite (LED4pin, HIGH);
          LED5state = 1;
          digitalWrite (LED5pin, HIGH);
          LED6state = 1;
          digitalWrite (LED6pin, HIGH);
          LED7state = 1;
          digitalWrite (LED7pin, HIGH);
          LED8state = 1;
          digitalWrite (LED8pin, HIGH);
          allLEDstate = 1;
      }else {
          LED1state = 0;
          digitalWrite (LED1pin, LOW);
          LED2state = 0;
          digitalWrite (LED2pin, LOW);
          LED3state = 0;
          digitalWrite (LED3pin, LOW);
          LED4state = 0;
          digitalWrite (LED4pin, LOW);
          LED5state = 0;
          digitalWrite (LED5pin, LOW);
          LED6state = 0;
          digitalWrite (LED6pin, LOW);
          LED7state = 0;
          digitalWrite (LED7pin, LOW);
          LED8state = 0;
          digitalWrite (LED8pin, LOW);
          allLEDstate = 0;
      }
      delay (dt);
      IR.resume();
      break;
  }

  Serial.print (allLEDstate);
  Serial.print ("  ");
  Serial.print (LED1state);
  Serial.print ("  ");
  Serial.print (LED2state);
  Serial.print ("  ");
  Serial.print (LED3state);
  Serial.print ("  ");
  Serial.print (LED4state);
  Serial.print ("  ");
  Serial.print (LED5state);
  Serial.print ("  ");
  Serial.print (LED6state);
  Serial.print ("  ");
  Serial.print (LED7state);
  Serial.print ("  ");
  Serial.println (LED8state);
}
