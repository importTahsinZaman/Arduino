int ledPin = 5;

void setup () {
  pinMode (ledPin, OUTPUT);
  Serial.begin (9600);
}

void loop ()
{
  if (Serial.available() > 0)  // Checks whether data is comming from the serial port
  {
    const int state = Serial.read();     // Reads the data from the serial port
    switch (state)
    {
      case '0':
        digitalWrite(ledPin, LOW); // Turn LED OFF
        Serial.println("LED: OFF"); // Send back, to the phone, the String "LED: ON"
        break;
 
       case '1':
        digitalWrite(ledPin, HIGH);
        Serial.println("LED: ON");
    }
  }
}
