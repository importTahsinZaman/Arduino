int redPin = 9;
int yellowPin = 4;
int delayTime = 500;
int yellowBlink = 3;
int redBlink = 5;
int j;

void setup() {
  // put your setup code here, to run once:
pinMode (redPin, OUTPUT);
pinMode (yellowPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
//yellow blink 3 times
  for(j=1;j<=yellowBlink;j=j+1){
digitalWrite (yellowPin, HIGH);
delay (delayTime);
digitalWrite (yellowPin, LOW);
delay (delayTime);
  }
//red blink 5 times

   for(j=1;j<=redBlink;j=j+1){
digitalWrite (redPin, HIGH);
delay (delayTime);
digitalWrite (redPin, LOW);
delay (delayTime);
   }
}
