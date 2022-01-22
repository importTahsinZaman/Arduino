void setup() {
  Serial.begin (9600);

  char grade = 'Z'; //This is a switch statement there are different possible values of the char variable Z indicated by the "cases" and different things happen based on the value of Z
  switch (grade) {
    case 'A':
      Serial.print ("Great!");
      break;
    case 'B':
      Serial.print ("Good");
      break;
    case 'C':
      Serial.print ("Better luck next time!");
      break;
    default:
      Serial.println ("confused!");
      break;
  }

  int i = 0;  

  while (i < 20) {
    if (i % 2) {  // "%" divides two values and returns the remainder, so in this case it divides i and 2 and then gives the remainder
      Serial.print(i);
      i++;
      continue; //"continue" forces the iteration of the statement to stop and continue on to the next iteration (would jump back to the top of the while loop)
    }
    if (i == 14) {
      break; //"break" forces the program to jump out of the loop (would leave the while loop entirely)
    }
    i++;
  }

  Serial.println (5 + 2); //addition
  Serial.println (5 - 2); //subraction
  Serial.println (5 * 2); //multiplication
  Serial.println (5 / 2); //division
  Serial.println (5 % 2); //remainder

  Serial.println (fabs(-2)); //absolute value

  Serial.println (fmin(2.5, 3)); //minimum value
  Serial.println (fmax(2.5, 3)); //maximum value

  Serial.println (round(2.5));  //rounds the value
  Serial.println (floor(2.5));  //rounds the value down
  Serial.println (ceil(2.5));   //rounds the value up

  Serial.println (sqrt(25));    //square root

  Serial.println (square(3));   //squares the value (3^2 in this example)

  Serial.println (pow(5, 2));   //power (5 ^ 2 in this example)
  
  Serial.print (cbrt(8));       // finds the cube root

  Serial.println (log(2.718));  //finds log
  Serial.println (log10(1000)); //find log with specified base (in this case, log 1000 with base 10)

  Serial.println (constrain(5, 1, 6));  //https://www.arduino.cc/reference/en/language/functions/math/constrain/

  Serial.println (sin(1.57)); //sine
  Serial.println (cos(1.57)); //cosine
  Serial.println (tan(3.14)); //tangent
  Serial.println (sinh(1.57)); //hyperbolic sin
  Serial.println (cosh(1.57)); //hyperbolic cos
  Serial.println (tanh(1.57)); //hyperbolic tangent
  Serial.println (asin(1.57)); // arc/inverse sine
  Serial.println (acos(1.57)); // arc/invrse cosine
  Serial.println (atan(1.57)); // arc/inverse tangent

  randomSeed(analogRead(0)); //initializes the generation of random numbers, you must declare a randomSeed, in this case an unused pin.  
                             //https://www.arduino.cc/reference/en/language/functions/random-numbers/randomseed/
  for (int i = 0; i < 10; i++) { 
    Serial.println (random(1, 10)); //prints a random number using the randomSeed ^ See Link
  }

  //BIT Manipulation:
  //Binary 1111:  1*2^3 + 1*2^2 + 1*2^1 + 1*2^0 = Base 10:  1 + 2 + 4 + 8 = 15  (short binary to base 10 explanation)
  int bin1 = 0b10101010;
  int bin2 = 0b11111111;

  Serial.println (bin1 & bin2); // This returns a 1 only if both values in that digit place is 1 for both integers so this would print the base 10 number 170
  Serial.println (bin1 | bin2); // This returns a 1 no matter if the value in that digit place is a 1 or 0 for either integer
  Serial.println (bin1 ^ bin2); //Returns a 1 only if the value in the digit place of one integer is 1 but not 1 for the other integer (Exclusive OR)
  Serial.println (~0b0111); //Switches every value, this prints a -8 becauase the top bit in any number is a sign bit and whenever it is changed to a 1, the number becomses negative
  Serial.println (bin2 >> 2); //Shifts to the right by two. Becomes 00111111
  Serial.println (bin2 << 2); // Shifts to the left by two. Becomes 1111111100

  struct RGB { //https://www.youtube.com/watch?v=7ox8F9RGFzw&ab_channel=MicrocontrollersLabMicrocontrollersLab
    byte red;
    byte green;
    byte blue;
  };

  RGB color = {0, 255, 0};  
  if (color.red == 0 && color.green == 255 && color.blue == 0) { //see link for structs above
    Serial.println ("It's green");
  }

  printTime(1, 12); // Function declared later down

  int * ptr;  //A pointer refers to a memory location for a variable. * signifies that it is a pointer
  int val1 = 15; 
  ptr = &val1;  //Stores variable val1 using the "&"
  Serial.println (*ptr);
  int primes[] = {2,3,5,7}; //an array is basically a pointer
  Serial.println(*primes); //since an array is a pointer, you can use this to print the first index of the array
  Serial.println(*primes + 1); //this prints the second value in the index
  printArray(primes, 4);

}

void loop() {
  // put your main code here, to run repeatedly:

}

void printTime (int hour, int minute) {  //prints using styleprint (google more info :))
  char buffer[6] = "";
  sprintf(buffer, "%02d:%02d", hour, minute)
  Serial.print(buffer);
}

  void printArray (int arr[], int size){ //function printArray declared
    for(int = 0; int < size; i++){
      Serial.println (arr[i]);
    }
  }
  
