String LEDchoice;
String msg1 = "Choose from Red green or blue for what color LED you would like ";
String msg2= "How many volts would you like from 0.1-5";
String warningMsg1 = "*WARNING* Please choose red, green or blue *WARNING*";
String warningMsg2 = "*WARNING* Voltage is too LOW, please input a voltage from 0.1-5 *WARNING*";
String warningMsg3 = "*WARNING* Voltage is too HIGH, please input a voltage from 0.1-5 *WARNING*";
int redLED = 6;
int greenLED = 10;
int blueLED = 11;
//This is user brightness:
float brightness;
//This is analog voltage:
float voltage;

void setup() {
Serial.begin (9600);
pinMode (redLED, OUTPUT);
pinMode (greenLED, OUTPUT);
pinMode (blueLED, OUTPUT);
}

void loop() {
  //Asking for LED
Serial.println (msg1);
 
while (Serial.available()==0){
  
}
LEDchoice = Serial.readString();

//LED Warning

while (LEDchoice != "red" && LEDchoice != "Red" && LEDchoice != "RED" && LEDchoice != "green" && LEDchoice != "Green" && LEDchoice != "GREEN" && LEDchoice != "blue" && LEDchoice != "Blue" && LEDchoice != "BLUE" && LEDchoice != "off" && LEDchoice != "OFF" && LEDchoice != "Off"){
  Serial.println (warningMsg1);
  Serial.println (msg1);
 
while (Serial.available()==0){
  
}
LEDchoice = Serial.readString();
}

//OFF Command

if (LEDchoice == "off" || LEDchoice == "OFF" || LEDchoice == "Off"){
  voltage = 0;
}

//Asking for brightness
Serial.println (msg2);
 
while (Serial.available()==0){
  
}
brightness = Serial.parseFloat();

voltage = (255./51. * brightness);
//Brightness warning

while (brightness<0.1){
  Serial.println (warningMsg2);
  Serial.println (msg2);
 
while (Serial.available()==0){
  
}
brightness = Serial.parseFloat();

voltage = (255./51. * brightness);
}

while (brightness>5){
  Serial.println (warningMsg3);
  Serial.println (msg2);
 
while (Serial.available()==0){
  
}
brightness = Serial.parseFloat();

voltage = (255./51. * brightness);
}

//Turning on LED

if (LEDchoice == "red" || LEDchoice == "Red" || LEDchoice == "RED"){
  analogWrite (redLED, voltage);}
  else {
  digitalWrite (redLED, LOW);
}

if (LEDchoice == "green" || LEDchoice == "Green" || LEDchoice == "GREEN"){
  analogWrite (greenLED, voltage);}
  else {
  digitalWrite (greenLED, LOW);
}

if (LEDchoice == "blue" || LEDchoice == "Blue" || LEDchoice == "BLUE"){
  analogWrite (blueLED, voltage);}
  else {
  digitalWrite (blueLED, LOW);
}

}
