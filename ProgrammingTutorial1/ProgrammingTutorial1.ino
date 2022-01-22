const int ledPin = 13; // Constant int: https://www.arduino.cc/reference/en/language/variables/variable-scope-qualifiers/const/

void setup() { //All starting code goes in Void Setup: (Every arduino program requires this)
  Serial.begin (9600); //Begins the serial port at a baud rate of 9600 (9600 bits per second)
  pinMode (ledPin, OUTPUT); //Sets led at pin 13 as an OUTPUT

  countDown (5); //setup of countDown function that is declared later, this function carries the value 5 (go down to function declaration to see how the 5 is used)

  int j = 3; //declares an integer variable j
    
  while (j > 0) { //While loop, this loops while the parameters inside () are true
    Serial.print (j); //print j
    Serial.print (" , ");
    j--; //Subtracts 1 from j, this is the same thing as j = j - 1
  }
  Serial.println ("Go...\n"); // the \n forces a new line to be started afterwards (it signifies the end of the line)
  Serial.print("3.11111111 + 4.11111111 ="); 
  Serial.println (addFloats (3.11111111, 4.11111111), 8);  //https://www.arduino.cc/reference/en/language/variables/data-types/float/
                                                           //this prints the two floats (3.11111111, 4.11111111) and prints it at a bit accuaracy of 8
  Serial.println (addDoubles (3.11111111, 4.11111111), 8); //this prints the two doubles (3.11111111, 4.11111111) and prints it at a bit accuaracy of 8
                                                           //floats and doubles are almost the same thing https://www.arduino.cc/reference/en/language/variables/data-types/double/

  bool canVote = true; //Boolean: https://www.arduino.cc/reference/en/language/variables/data-types/bool/

  Serial.print("Can I Vote? ");
  Serial.println (((canVote == true) ? "yes" : "no")); //This is a ternary operator, it checks if canVote == true, then prints "yes" if it is and no if it isnt
                                                       //This is similiar to an if statement
                                                       
  char letD = 'D'; // Character type data: https://www.arduino.cc/reference/en/language/variables/data-types/char/
  Serial.println (letD);

  //Other data types:
  //byte: 0 to 255; Stores a value from 0 to 255 https://www.arduino.cc/reference/en/language/variables/data-types/byte/
  //unsigned int: 0 - 65535 https://www.arduino.cc/reference/en/language/variables/data-types/unsignedint/
  //long: -2,147,483,648 - 2,147,483,647 https://www.arduino.cc/reference/en/language/variables/data-types/long/
  //unsigned long : 0 - 4,294,967,295 https://www.arduino.cc/reference/en/language/variables/data-types/unsignedlong/
  
}

void loop() { //Void loop is the second mandatory function in every arduino program (after void setup) the main code goes here
  static int delayPeriod = 100; //These two static integers are used only one (hence the "static") and their values are stick in the void loop since they were declared here
  static int countDir = 1;

  digitalWrite (ledPin, HIGH); //Sends 5v to ledPin (we declared this to be 13)
  delay (delayPeriod);         // Delays for delayPeriod microseconds, we declared delayPeriod to be a static int of 100
  digitalWrite (ledPin, LOW);
  delay (delayPeriod);

  countDir = checkDirChange (delayPeriod, countDir); //declares the variable countDir to be equal to checkDirChange, a function that is declared later on

  delayPeriod += 100 * countDir; //Delay period is declared to now be equal to 100 * countir + delay period. (+= is shorthand) This value is recalculated every loop. 
                                 //https://www.arduino.cc/reference/en/language/structure/compound-operators/compoundaddition/
                                 //The value for countDir is gotten from the countDir function that is declared later down
                                 
  Serial.print("New wait Time: ");
  Serial.println (delayPeriod);
}

int checkDirChange (int delayPeriod, int countDir) { //declares a function that will return the value of the integer checkDirChange.
                                                     //this function has the values of delayPeriod and countDir from voidLoop, NOT THE ENTIRE VARIABLE, JUST THE VALUE
                                                     
  if (delayPeriod == 1000 || delayPeriod == 0) {     //the code inside this if statement runs if delay period == 100 or if it equals 0 (delayPeriod == 0)
    countDir *= -1;                                  //same as countDir = countDir * -1

    if (countDir < 0) {                              //if statement inside if statement.
      Serial.println ("Going down");
    } else {                                         //else statement runs if parameters for if statement right above it is not met
      Serial.println ("Going Up");
    }
  }
  return countDir;                                   //this returns the value of countDir that was calculated from this function back to voidLoop since that is where the variable-
                                                     //countDir was declared
}

void countDown(int max) {                           //declares function countDown (rememer this function carries a value of 5 from before)

  for (int i = max; i > 0; i--) {                   //for statement runs as long as the parameters i = max (max is 5) and i > 0 are still true whie subtracting 1 from i (i--)
    Serial.print (i);
    Serial.print (" , ");

  }
  Serial.println ("go...\n");


}

float addFloats(float num1, float num2){            //returns float values num1 + num2 (these were declared to be 3.11111111 and 4.11111111 earlier on
  return num1 + num2;
}

double addDoubles(double num1, double num2){        //returns double values num1 + num2 (these were declared to be 3.11111111 and 4.11111111 earlier on
  return num1 + num2;
}
