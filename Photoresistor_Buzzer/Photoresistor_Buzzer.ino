int photoPin = A5;
int buzzPin = 3;
int buzzTime;
int lightVal;


void setup() {
  pinMode (photoPin, INPUT);
  Serial.begin (9600);
  pinMode (buzzPin, OUTPUT);
}

void loop() {
  lightVal = analogRead (photoPin);

  buzzTime = 9./150. * lightVal - (9./5.)+1;
  Serial.println (buzzTime);
  
  digitalWrite (buzzPin, HIGH);
  delay (buzzTime);
  digitalWrite (buzzPin, LOW);
  delay (buzzTime);
  
}
