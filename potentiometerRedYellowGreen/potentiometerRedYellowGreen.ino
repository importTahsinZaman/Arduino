int Red = 2;
int Yellow = 3;
int Green = 4;
int readPin = A0; 
int readVal;
float voltage;

void setup() {
  // put your setup code here, to run once:
pinMode (Red, OUTPUT);
pinMode (Yellow, OUTPUT);
pinMode (Green, OUTPUT);
Serial.begin(9600);
pinMode (readPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
 readVal = analogRead(readPin); 
voltage = (5./1023.) * readVal; 
Serial.print("Potentiometer voltage is: ");
Serial.println(voltage);

if (voltage<3){
    digitalWrite (Green, HIGH);
  }else {
    digitalWrite (Green, LOW);
  }
  
if (voltage>3 && voltage<4){
    digitalWrite (Yellow, HIGH);
  }else {
    digitalWrite (Yellow, LOW);
  }

if (voltage>4){
    digitalWrite (Red, HIGH);
  }else {
    digitalWrite (Red, LOW);
  }

}
