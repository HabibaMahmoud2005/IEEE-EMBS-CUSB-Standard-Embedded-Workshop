const int ledPin = 13;
const int buzzerPin = 8;


void setup() {
pinMode(ledPin, OUTPUT);
pinMode(buzzerPin, OUTPUT);
}


void loop() {
digitalWrite(ledPin, HIGH);
tone(buzzerPin, 1200);
delay(300);


digitalWrite(ledPin, LOW);
noTone(buzzerPin);
delay(300);
}
