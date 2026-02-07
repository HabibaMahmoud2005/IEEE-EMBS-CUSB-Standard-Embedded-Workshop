### Concept

Because the Arduino UNO cannot generate true analog voltages, **PWM (Pulse Width Modulation)** is used to simulate varying brightness by changing the duty cycle of a digital signal.

```arduino
const int ledPin = 9; // PWM pin

void setup() {
pinMode(ledPin, OUTPUT);
}

void loop() {
for (int brightness = 0; brightness <= 255; brightness++) {
analogWrite(ledPin, brightness);
delay(10);
}

for (int brightness = 255; brightness >= 0; brightness--) {
analogWrite(ledPin, brightness);
delay(10);
}
}
```

### Explanation

- `analogWrite()` controls LED brightness (0–255).
- Increasing duty cycle → brighter LED.
- Decreasing duty cycle → dimmer LED.
