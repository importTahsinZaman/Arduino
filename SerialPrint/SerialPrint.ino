int j=2;
int waitT=1;
String myString="j=";

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.print(myString);
Serial.println(j);
delay(waitT);
j=j*j;
}
