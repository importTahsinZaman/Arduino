#define numOfValsRec 5
#define digitsPerValRec 1

int valsRec [numOfValsRec];
int stringLength = numOfValsRec * digitsPerValRec + 1; //$00000
int counter = 0;
bool counterStart = false;
String receivedString;

void setup() {
  Serial.begin (9600);
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

}
