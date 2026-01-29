int ledPin = 13;
int buttonPin = 2;

voidsetup() {
pinMode(ledPin, OUTPUT);
pinMode(buttonPin, INPUT_PULLUP);
}

voidloop() {
int buttonState = digitalRead(buttonPin);

if (buttonState == LOW) {
	// Button pressed
	digitalWrite(ledPin, HIGH);
  }
  else {
	digitalWrite(ledPin, LOW);
  }
}
