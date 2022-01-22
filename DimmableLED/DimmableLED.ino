int potPin = A1;
int gPin = 3;
int potVal;
float LEDval;
 
 void setup() {
  // put your setup code here, to run once:
pinMode (potPin, INPUT);
pinMode (gPin, OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
potVal = analogRead(potPin);
LEDval = (255./1023.)*potVal;
Serial.println (LEDval);
analogWrite (gPin, LEDval);
}
