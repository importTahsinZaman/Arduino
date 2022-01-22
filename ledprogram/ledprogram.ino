int wait = 170;
int dah = 500;
int dit = 250;

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

 delay(2000);
}
