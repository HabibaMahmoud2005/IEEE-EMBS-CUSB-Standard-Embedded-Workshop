#include <Keypad.h>

const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {9,10,11,12};
byte colPins[COLS] = {A0,A1,A2,A3};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

int segmentPins[7] = {2,3,4,5,6,7,8};

byte digits[10][7] = {
  {1,1,1,1,1,1,0},
  {0,1,1,0,0,0,0},
  {1,1,0,1,1,0,1},
  {1,1,1,1,0,0,1},
  {0,1,1,0,0,1,1},
  {1,0,1,1,0,1,1},
  {1,0,1,1,1,1,1},
  {1,1,1,0,0,0,0},
  {1,1,1,1,1,1,1},
  {1,1,1,1,0,1,1}
};

void setup(){
  for(int i=0;i<7;i++)
    pinMode(segmentPins[i],OUTPUT);
}

void displayDigit(int num){
  for(int i=0;i<7;i++)
    digitalWrite(segmentPins[i],digits[num][i]);
}

void loop(){
  char key = keypad.getKey();
  if(key && key >= '0' && key <= '9'){
    displayDigit(key - '0');
  }
}