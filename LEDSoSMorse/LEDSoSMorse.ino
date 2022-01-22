int wait = 100;
int dah = 100;
int dit = 100;

void setup() {
  // put your setup code here, to run once:
pinMode (2,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //S
 digitalWrite(2, HIGH);
 delay(dit);
 digitalWrite(2,LOW);
 delay(wait);
 digitalWrite(2, HIGH);
 delay(dit);
 digitalWrite(2,LOW);
 delay(wait);
 digitalWrite(2, HIGH);
 delay(dit);
 digitalWrite(2,LOW);
 delay(wait);

//O

  digitalWrite(2, HIGH);
 delay(dah);
 digitalWrite(2,LOW);
 delay(wait);
 digitalWrite(2, HIGH);
 delay(dah);
 digitalWrite(2,LOW);
 delay(wait);
 digitalWrite(2, HIGH);
 delay(dah);
 digitalWrite(2,LOW);
 delay(wait);

//S

  digitalWrite(2, HIGH);
 delay(dit);
 digitalWrite(2,LOW);
 delay(wait);
 digitalWrite(2, HIGH);
 delay(dit);
 digitalWrite(2,LOW);
 delay(wait);
 digitalWrite(2, HIGH);
 delay(dit);
 digitalWrite(2,LOW);
 delay(wait);

 delay(90);
}
