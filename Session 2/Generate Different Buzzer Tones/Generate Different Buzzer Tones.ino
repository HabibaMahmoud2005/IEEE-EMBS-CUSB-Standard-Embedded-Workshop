const int buzzerPin = 8;
int tones[] = {500, 1000, 1500};


void setup() {
pinMode(buzzerPin, OUTPUT);
}


void loop() {
for (int i = 0; i < 3; i++) {
tone(buzzerPin, tones[i]);
delay(300);
noTone(buzzerPin);
delay(200);
}
}
