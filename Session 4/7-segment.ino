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

void setup() {
  for(int i=0;i<7;i++)
    pinMode(segmentPins[i],OUTPUT);
}

void displayDigit(int num){
  for(int i=0;i<7;i++)
    digitalWrite(segmentPins[i],digits[num][i]);
}

void loop() {
  for(int i=0;i<10;i++){
    displayDigit(i);
    delay(1000);
  }
}