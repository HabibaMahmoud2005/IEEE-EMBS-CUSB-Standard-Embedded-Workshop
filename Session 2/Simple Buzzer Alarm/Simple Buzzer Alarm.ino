const int buzzerPin = 8;


void setup() {
pinMode(buzzerPin, OUTPUT);
}


void loop() {
tone(buzzerPin, 1000); // 1 kHz alarm tone
delay(500);
noTone(buzzerPin);
delay(500);
}
