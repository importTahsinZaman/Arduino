
int firstNumber;
int secondNumber;
int p;
String msg = "This is a calculator that adds two numbers. Please enter your first number: ";
String msg2 = "Please enter your second number: ";
String msg3 = "Your number is: ";
String msg4 = "This is the sum:";

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // Introduce the program and ask for first number
Serial.println (msg);

while(Serial.available()==0){
 
}

firstNumber = Serial.parseInt();
p = Serial.parseInt();

//Ask for second number

Serial.println (msg2);
while(Serial.available()==0){
  
}
secondNumber = Serial.parseInt();
Serial.print (secondNumber);
p = Serial.parseInt();

//Give the sum

Serial.println (msg4);
Serial.print (firstNumber + secondNumber);
Serial.println ( );
Serial.println ( );
}
