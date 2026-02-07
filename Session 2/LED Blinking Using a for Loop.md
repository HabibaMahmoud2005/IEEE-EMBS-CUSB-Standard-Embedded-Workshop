# LED Blinking Using a for Loop

### Concept

Blinking an LED demonstrates **digital output control** and introduces loop-based repetition. Using a `for` loop allows a fixed number of blink cycles instead of continuous blinking.

```arduino
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
```

### Explanation

- `pinMode()` configures the LED pin as an output.
- The `for` loop controls how many times the LED blinks.
- `delay()` determines ON and OFF durations.
