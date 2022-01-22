int LEDPin1 = 11;
int LEDPin2 = 10;
int LEDPin3 = 9;
int LEDPin4 = 6;
int bright = 15;
int bright2 = 35;
int bright3 = 50;
int bright4 = 75;
int bright5 = 100;
int bright6 = 150;
int bright7 = 255;
int waitTime = 125;

void setup() {
  // put your setup code here, to run once:
pinMode (LEDPin1, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

 //LED1
analogWrite(LEDPin1,bright);
delay (waitTime);

analogWrite(LEDPin1,bright2);
delay (waitTime);

analogWrite(LEDPin1,bright3);
delay (waitTime);

analogWrite(LEDPin1,bright4);
delay (waitTime);

analogWrite(LEDPin1,bright5);
delay (waitTime);

analogWrite(LEDPin1,bright6);
delay (waitTime);

analogWrite(LEDPin1,bright7);
delay (waitTime);

//LED2
analogWrite(LEDPin2,bright);
delay (waitTime);

analogWrite(LEDPin2,bright2);
delay (waitTime);

analogWrite(LEDPin2,bright3);
delay (waitTime);

analogWrite(LEDPin2,bright4);
delay (waitTime);

analogWrite(LEDPin2,bright5);
delay (waitTime);

analogWrite(LEDPin2,bright6);
delay (waitTime);

analogWrite(LEDPin2,bright7);
delay (waitTime);

//LED3
analogWrite(LEDPin3,bright);
delay (waitTime);

analogWrite(LEDPin3,bright2);
delay (waitTime);

analogWrite(LEDPin3,bright3);
delay (waitTime);

analogWrite(LEDPin3,bright4);
delay (waitTime);

analogWrite(LEDPin3,bright5);
delay (waitTime);

analogWrite(LEDPin3,bright6);
delay (waitTime);

analogWrite(LEDPin3,bright7);
delay (waitTime);

//LED4
analogWrite(LEDPin4,bright);
delay (waitTime);

analogWrite(LEDPin4,bright2);
delay (waitTime);

analogWrite(LEDPin4,bright3);
delay (waitTime);

analogWrite(LEDPin4,bright4);
delay (waitTime);

analogWrite(LEDPin4,bright5);
delay (waitTime);

analogWrite(LEDPin4,bright6);
delay (waitTime);

analogWrite(LEDPin4,bright7);
delay (waitTime);

}
