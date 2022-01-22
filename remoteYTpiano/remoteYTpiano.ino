//IR Remote Variables
#include <IRremote.h>
int IRpin = 9;
IRrecv IR(IRpin);
decode_results cmd;
String myComm;

//Delay
int dt = 100;

#include <Keyboard.h>

void setup() {
  //IR Remote Setup
  Serial.begin (9600);
  IR.enableIRIn();

}

void loop() {
  //Looking for Remote Input
  while (IR.decode(&cmd) == 0) { }
  IR.resume();

  //Remote Input Reads
  switch (cmd.value) {
    case 0x807F807F:
      myComm = "zero";
      Serial.print (" = ");
      Serial.println (myComm);
      Keyboard.begin(); 
      Keyboard.write ('0');
      Keyboard.release();
      delay (dt);
      IR.resume();
      break;
    case 0x807F728D:
      myComm = "one";
      Serial.print (" = ");
      Serial.println (myComm);
      delay (dt);
      IR.resume();
      break;
    case 0x807FB04F:
      myComm = "two";
      Serial.print (" = ");
      Serial.println (myComm);
      delay (dt);
      IR.resume();
      break;
    case 0x807F30CF:
      myComm = "three";
      Serial.print (" = ");
      Serial.println (myComm);
      delay (dt);
      IR.resume();
      break;
    case 0x807F52AD:
      myComm = "four";
      Serial.print (" = ");
      Serial.println (myComm);
      delay (dt);
      IR.resume();
      break;
    case 0x807F906F:
      myComm = "five";
      Serial.print (" = ");
      Serial.println (myComm);
      delay (dt);
      IR.resume();
      break;
    case 0x807F10EF:
      myComm = "six";
      Serial.print (" = ");
      Serial.println (myComm);
      delay (dt);
      IR.resume();
      break;
    case 0x807F629D:
      myComm = "seven";
      Serial.print (" = ");
      Serial.println (myComm);
      delay (dt);
      IR.resume();
      break;
    case 0x807FA05F:
      myComm = "eight";
      Serial.print (" = ");
      Serial.println (myComm);
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
