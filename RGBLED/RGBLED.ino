int rValue;
int gValue;
int bValue;
int redPin = 6;
int greenPin = 10;
int bluePin = 11;
String redAsk = "Enter a Red Value from 0-255";
String greenAsk = "Enter a Green Value from 0-255";
String blueAsk = "Enter a Blue Value from 0-255";
String errorMsg = "*Error* Enter a value between 0 and 255 *ERROR*";

void setup() {
  // put your setup code here, to run once:
  pinMode (redPin, OUTPUT);
  pinMode (greenPin, OUTPUT);
  pinMode (bluePin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
//Asks for Red Value
  Serial.println (redAsk);
  while (Serial.available() == 0) { }
  rValue = Serial.parseInt();

//Red Warning
  while (rValue > 255 || rValue < 0) {
    Serial.println (errorMsg);
    Serial.println (redAsk);
    while (Serial.available() == 0) { }
    rValue = Serial.parseInt();
  }

//Asks for Green Value
  Serial.println (greenAsk);
  while (Serial.available() == 0) { }
  gValue = Serial.parseInt();

//Green Warning
  while (gValue > 255 || gValue < 0) {
    Serial.println (errorMsg);
    Serial.println (greenAsk);
    while (Serial.available() == 0) { }
    gValue = Serial.parseInt();
  }

//Asks for Blue Value
  Serial.println (blueAsk);
  while (Serial.available() == 0) { }
  bValue = Serial.parseInt();

//Blue Warning
  if (bValue > 255 || bValue < 0) {
    Serial.println (errorMsg);
    Serial.println (blueAsk);
    while (Serial.available() == 0) { }
    bValue = Serial.parseInt();
  }

//Displays Color
  analogWrite (redPin, rValue);
  analogWrite (greenPin, gValue);
  analogWrite (bluePin, bValue);

//Output Message
  Serial.print ("Output: R");
  Serial.print (rValue);
  Serial.print (" G");
  Serial.print (gValue);
  Serial.print (" B");
  Serial.print (bValue);
  Serial.println( );

}
