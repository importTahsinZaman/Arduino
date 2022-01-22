#define numOfValsRec 5
#define digitsPerValRec 1

int ledOne = 6; //Red LED (Pinky)
int ledTwo = 5; //Green LED (Ring)
int ledThree = 4; //Middle (Yellow)
int ledFour = 3;  //Index (Blue)
int ledFive = 2; //White LED (Thumb)

int valsRec [numOfValsRec];
int stringLength = numOfValsRec * digitsPerValRec + 1; //$00000
int counter = 0;
bool counterStart = false;
String receivedString;

void setup() {
  Serial.begin (9600);
  pinMode (ledOne, OUTPUT);
  pinMode (ledTwo, OUTPUT);
  pinMode (ledThree, OUTPUT);
  pinMode (ledFour, OUTPUT);
  pinMode (ledFive, OUTPUT);
}

void receiveData () {
  while (Serial.available ()) {
    char c = Serial.read();

    if (c == '$') {
      counterStart = true;
    }

    if (counterStart) {
      if (counter < stringLength) {
        receivedString = String(receivedString + c);
        counter++;
      }
      if (counter >= stringLength) {
        for (int i = 0; i < numOfValsRec; i++) {
          int num = (i * digitsPerValRec) + 1;
          valsRec [i] = receivedString.substring(num, num + digitsPerValRec).toInt();
        }
        receivedString = "";
        counter = 0;
        counterStart = false;
      }
    }
  }
}


void loop() {
  receiveData ();
  if (valsRec [0] == 1) {digitalWrite (ledFive, HIGH);} else {digitalWrite (ledFive, LOW);} //Thumb
  if (valsRec [1] == 1) {digitalWrite (ledFour, HIGH);} else {digitalWrite (ledFour, LOW);} //Index
  if (valsRec [2] == 1) {digitalWrite (ledThree, HIGH);} else {digitalWrite (ledThree, LOW);} //Middle
  if (valsRec [3] == 1) {digitalWrite (ledTwo, HIGH);} else {digitalWrite (ledTwo, LOW);} //Ring
  if (valsRec [4] == 1) {digitalWrite (ledOne, HIGH);} else {digitalWrite (ledOne, LOW);} //Pinky
}
