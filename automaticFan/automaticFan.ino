void setup() {
  Serial.begin (9600);
  pinMode (4, OUTPUT);
  pinMode (5, OUTPUT);
}

void loop() {
    while (Serial.available() == 0) { }
    int input = Serial.parseInt();

    switch (input){
      case 1:
        Serial.println (input);
        digitalWrite (4, HIGH);
        delay (1500);
        digitalWrite (4, LOW);
        break;
      case 0:
        Serial.println (input);
        digitalWrite (5, HIGH);
        delay (1500);
        digitalWrite (5, LOW);
        break;
    }
}
