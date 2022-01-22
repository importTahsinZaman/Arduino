const int ledPin = 13;

int numOfBlinks[] = {1, 2, 3, 4}; //Declares an integer Array, the values within the array may be changed bu the length of the array may not be changed once declared
                                  //Arrays start at 0, meaning the 0 value is 1 and the 1 value, or first value is 2

void setup() {
  Serial.begin (9600);
  pinMode (ledPin, OUTPUT);

}

void loop() {
  int delayPeriod = 1000;

  numOfBlinks[0] = 5; //Changes the 0 value to 5 (so it goes from 1 to 5)
  int array2[10];     //Declares the integer array array2, specifies a length of 10 but leaves values to be determined
  char array3 [] = "Derek"; //Declares a character array array3, value of character array is D e r e k
  char *str = "Bananas"; //[UNSURE] the * declares a pointer to a memory address doing this is the alternative to writing char str[] = "Bananas"
  Serial.println (str);
  String myName = "Derek Bananas"; // Declares the string variable "Derek Bananas" string variables must be declared with ""
  Serial.println ("Name: " + myName); // Adds two strings and then prints two strings, this can only be done with the same type of data
  Serial.println (myName.length()); //Prints the length of myName
  Serial.println (myName.equals("Derek")); //Checks and prints if myName is equal to "Derek". 0 = false 1= true
  Serial.println (myName.equalsIgnoreCase("Derek")); // Checks and prints if myName is equal to "Derek" but ignores case. 0 = false 1= true
  Serial.println (myName.charAt (6)); //Checks and prints the character at index(location) 6 of the string array myName
  Serial.println (myName.indexOf('B')); //Checks and prints the index(location) of character 'B' in string array myName
  myName.remove (0, 6); //Starts at index 0 and removes 6 characters after, can be used with only the first parameter (would look like: myName.remove (0);)
  Serial.println (myName);
  myName.replace("nas", "s"); //Replaces the substring (chunk of characters) "nas" with "s"
  Serial.println (myName);
  Serial.println (myName.substring(0, 3)); //Starts at index 0 and and goes for 3 more indexes (this is a substring) and then prints.
                                           //Another explanation: if the variable myName were equal to "Banannas" this would grab the substring "Bana"
  myName.toUpperCase();                    //Makes all the characters in myName to upper case
  myName.toLowerCase();                    //Makes all the characters in myName to lower case
  String one = "1";                        //Declares the string variable one to be equal to "1"
  int num1 = one.toInt();                  //Declares an integer variable num1 to be equal to the value of string variable one
  int sum = num1 + num1;                   //Declares the integer varibale sum to be equal to num1 and num1
  Serial.println (sum);

  for (int i = 0; i < 5; i++) {           //Prints index 0 - 5 of array3 (Prints "Derek")
    Serial.print (array3[i]);
  }

  for (int i = 0; i < 4; i++) {           
    blinkLED(numOfBlinks[i]);             //blinkLED carries the i index value of numOfBlink, this is used in a function right below
    delay (delayPeriod);
    
  }

}

void blinkLED (int numOfBlinks) {          //Blinks LED the same number of times as the value of numOfBlinks
  for (int j = 0; j < numOfBlinks; j++) { 
    digitalWrite (ledPin, HIGH);
    delay (400);
    digitalWrite (ledPin, LOW);
    delay (400);
  }
}
