### Concept

A buzzer converts electrical signals into sound. The `tone()` function generates a square wave of a specified frequency, suitable for alarms and alerts.

```arduino
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
```

### Explanation

- `tone()` outputs a frequency (Hz).
- `noTone()` stops sound generation.
- Delay controls alarm pattern.
