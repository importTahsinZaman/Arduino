String incoming_value;
int Green_pin = 2;
int Blue_pin = 3;
int Yellow_pin = 4;
int Red_pin = 5;

void setup() {
  Serial.begin (9600);
  pinMode (Green_pin, OUTPUT);
  pinMode (Blue_pin, OUTPUT);
  pinMode (Yellow_pin, OUTPUT);
  pinMode (Red_pin, OUTPUT);

}

void loop() {
  if (Serial.available() > 0) {
    incoming_value = Serial.readString();

    if (incoming_value == "green on") {
      Serial.print (incoming_value);
      Serial.print ("\n");
      digitalWrite (Green_pin, HIGH);
    } else if (incoming_value == "green off") {
      Serial.print (incoming_value);
      Serial.print ("\n");
      digitalWrite (Green_pin, LOW);
    } else if (incoming_value == "blue on" || incoming_value == "blew on" ) {
      Serial.print (incoming_value);
      Serial.print ("\n");
      digitalWrite (Blue_pin, HIGH);
    } else if (incoming_value == "blue off" || incoming_value == "blew off" ) {
      Serial.print (incoming_value);
      Serial.print ("\n");
      digitalWrite (Blue_pin, LOW);
    } else if (incoming_value == "yellow on") {
      Serial.print (incoming_value);
      Serial.print ("\n");
      digitalWrite (Yellow_pin, HIGH);
    } else if (incoming_value == "yellow off") {
      Serial.print (incoming_value);
      Serial.print ("\n");
      digitalWrite (Yellow_pin, LOW);
    } else if (incoming_value == "red on" || incoming_value == "read on") {
      Serial.print (incoming_value);
      Serial.print ("\n");
      digitalWrite (Red_pin, HIGH);
    } else if (incoming_value == "red off" || incoming_value == "read off") {
      Serial.print (incoming_value);
      Serial.print ("\n");
      digitalWrite (Red_pin, LOW);
    } else if (incoming_value == "1" || incoming_value == "all on" || incoming_value == "on") {
      Serial.print (incoming_value);
      Serial.print ("\n");
      digitalWrite (Green_pin, HIGH);
      digitalWrite (Blue_pin, HIGH);
      digitalWrite (Yellow_pin, HIGH);
      digitalWrite (Red_pin, HIGH);
    } else if (incoming_value == "0" || incoming_value == "all off" || incoming_value == "off") {
      Serial.print (incoming_value);
      Serial.print ("\n");
      digitalWrite (Green_pin, LOW);
      digitalWrite (Blue_pin, LOW);
      digitalWrite (Yellow_pin, LOW);
      digitalWrite (Red_pin, LOW);
    } else {
      Serial.print (incoming_value);
      Serial.print (" *ERROR* ");
      Serial.print ("\n");
    }
  }
}
