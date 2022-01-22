int blinkNum;
int LEDpin = 4;
String msg1 = "How many blinks would you like?";
int j;
int delayTime = 200;

void setup() {
  // put your setup code here, to run once:
pinMode (LEDpin, OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.println (msg1);
while (Serial.available ()==0){
  
}

blinkNum = Serial.parseInt();

Serial.print ("Initiating ");
Serial.print(blinkNum);
Serial.print(" blinks!");
Serial.println ( );
Serial.println ( );

for (j=1; j<=blinkNum; j=j+1){
  digitalWrite(LEDpin, HIGH);
  delay (delayTime);
  digitalWrite(LEDpin, LOW);
  delay (delayTime);
}
}
