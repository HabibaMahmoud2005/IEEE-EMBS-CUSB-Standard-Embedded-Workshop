const int ledPin = 13;


void setup() {
pinMode(ledPin, OUTPUT);
}


void loop() {
for (int i = 0; i < 5; i++) { // Blink LED 5 times
digitalWrite(ledPin, HIGH);
delay(500);
digitalWrite(ledPin, LOW);
delay(500);
}
delay(2000); // Pause before repeating the sequence
}
