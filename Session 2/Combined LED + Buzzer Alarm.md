**Objective:** Integrate visual and audio indicators into a single alarm system.

**Expected Outcome:** LED blinks while the buzzer sounds, forming a basic alarm signal.

```arduino
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
```
