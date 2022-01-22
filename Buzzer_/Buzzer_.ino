int buzzPin = 11;
int buzzTime;
int potPin = A5;
int potVal;
float sound;
int buzzMin = 500;
int buzzMax = 20000;

void setup() {

  Serial.begin(9600);
  pinMode (buzzPin, OUTPUT);
  pinMode (potPin, INPUT);
}

void loop() {

  potVal = analogRead(potPin);
  buzzTime = ((buzzMax - buzzMin)/1023.) * potVal + buzzMin;
 // Serial.println (buzzTime);


  digitalWrite (buzzPin, HIGH);
  delayMicroseconds (buzzTime);
  digitalWrite (buzzPin, LOW);
  delayMicroseconds (buzzTime);
}
