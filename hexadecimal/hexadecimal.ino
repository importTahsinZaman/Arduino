int myByte = 100;
int dt = 500;

void setup() {
  Serial.begin (9600);

}

void loop() {
  Serial.print (myByte, DEC);
  Serial.print ("    ");
  Serial.print (myByte, HEX);
  Serial.print ("    ");
  Serial.println (myByte, BIN);
  delay(dt);
  myByte = myByte + 1;
}
