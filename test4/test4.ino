#include <Servo.h>
Servo xServo;
Servo yServo;

String serialData;

void setup() {
  xServo.attach(10);
  yServo.attach(11);
  Serial.begin(9600);
  Serial.setTimeout(10);
}

void loop() {}

void serialEvent(){
  serialData = Serial.readString();

  xServo.write (parseDataX(serialData));
  yServo.write (parseDataY(serialData));
  
}

int parseDataX(String data){
  data.remove(data.indexOf("Y"));
  data.remove(data.indexOf("X"), 1);

  return data.toInt();
}

int parseDataY(String data){
  data.remove(0, data.indexOf("Y") + 1);
  return data.toInt();
}
