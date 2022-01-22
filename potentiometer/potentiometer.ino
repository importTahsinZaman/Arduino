int readPin = A0; 
int readVal;
float voltage;
int delayTime = 100;
int warningLED = 9;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode (readPin, INPUT);
pinMode (warningLED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
readVal = analogRead(readPin); 
voltage = (5./1023.) * readVal; 
Serial.print("Potentiometer voltage is: ");
Serial.println(voltage);
if (voltage>2 && voltage<3){
    digitalWrite (warningLED, HIGH);
  }

if (voltage<2 || voltage>3){
    digitalWrite (warningLED, LOW);
  }
delay(delayTime);
}
