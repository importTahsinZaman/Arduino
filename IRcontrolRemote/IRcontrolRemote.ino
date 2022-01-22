#include <IRremote.h>
int IRpin = 10;
IRrecv IR(IRpin);
decode_results cmd;
String myComm;
int dt = 100;

void setup() {
  Serial.begin (9600);
  IR.enableIRIn();

}

void loop() {
  while (IR.decode(&cmd) == 0) { }
  IR.resume();

  if (cmd.value == 0xFF6897) {
    myComm = "zero";
    Serial.print (" = ");
    Serial.println (myComm);
    delay (dt);
    IR.resume();
  }

  if (cmd.value == 0xFF30CF) {
    myComm = "one";
    Serial.print (" = ");
    Serial.println (myComm);
    delay (dt);
    IR.resume();
  }

  if (cmd.value == 0xFF18E7) {
    myComm = "two";
    Serial.print (" = ");
    Serial.println (myComm);
    delay (dt);
    IR.resume();
  }

  if (cmd.value == 0xFF7A85) {
    myComm = "three";
    Serial.print (" = ");
    Serial.println (myComm);
    delay (dt);
    IR.resume();
  }

  if (cmd.value == 0xFF10EF) {
    myComm = "four";
    Serial.print (" = ");
    Serial.println (myComm);
    delay (dt);
    IR.resume();
  }

  if (cmd.value == 0xFF38C7) {
    myComm = "five";
    Serial.print (" = ");
    Serial.println (myComm);
    delay (dt);
    IR.resume();
  }

  if (cmd.value == 0xFF5AA5) {
    myComm = "six";
    Serial.print (" = ");
    Serial.println (myComm);
    delay (dt);
    IR.resume();
  }

  if (cmd.value == 0xFF42BD) {
    myComm = "seven";
    Serial.print (" = ");
    Serial.println (myComm);
    delay (dt);
    IR.resume();
  }

  if (cmd.value == 0xFF4AB5) {
    myComm = "eight";
    Serial.print (" = ");
    Serial.println (myComm);
    delay (dt);
    IR.resume();
  }

  if (cmd.value == 0xFF52AD) {
    myComm = "nine";
    Serial.print (" = ");
    Serial.println (myComm);
    delay (dt);
    IR.resume();
  }

  if (cmd.value == 0xFFA25D) {
    myComm = "pwr";
    Serial.print (" = ");
    Serial.println (myComm);
    delay (dt);
    IR.resume();
  }

  if (cmd.value == 0xFF629D) {
    myComm = "volUp";
    Serial.print (" = ");
    Serial.println (myComm);
    delay (dt);
    IR.resume();
  }

  if (cmd.value == 0xFFA857) {
    myComm = "volDown";
    Serial.print (" = ");
    Serial.println (myComm);
    delay (dt);
    IR.resume();
  }

  if (cmd.value == 0xFFE01F) {
    myComm = "down";
    Serial.print (" = ");
    Serial.println (myComm);
    delay (dt);
    IR.resume();
  }

  if (cmd.value == 0xFF906F) {
    myComm = "up";
    Serial.print (" = ");
    Serial.println (myComm);
    delay (dt);
    IR.resume();
  }


  if (cmd.value == 0xFF22DD) {
    myComm = "fBck";
    Serial.print (" = ");
    Serial.println (myComm);
    delay (dt);
    IR.resume();
  }

  if (cmd.value == 0xFFC23D) {
    myComm = "fFwd";
    Serial.print (" = ");
    Serial.println (myComm);
    delay (dt);
    IR.resume();
  }

  if (cmd.value == 0xFF02FD) {
    myComm = "skp";
    Serial.print (" = ");
    Serial.println (myComm);
    delay (dt);
    IR.resume();
  }

  if (cmd.value == 0xFFE21D) {
    myComm = "stp";
    Serial.print (" = ");
    Serial.println (myComm);
    delay (dt);
    IR.resume();
  }

  if (cmd.value == 0xFF9867) {
    myComm = "EQ";
    Serial.print (" = ");
    Serial.println (myComm);
    delay (dt);
    IR.resume();
  }

  if (cmd.value == 0xFFB04F) {
    myComm = "ST";
    Serial.print (" = ");
    Serial.println (myComm);
    delay (dt);
    IR.resume();
  }

}
