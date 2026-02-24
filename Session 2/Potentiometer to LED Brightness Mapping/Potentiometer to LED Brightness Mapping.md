### Concept

A potentiometer provides an **analog input (0–5 V)**. The ADC converts this voltage into a digital value (0–1023), which must be scaled to the PWM range (0–255).

```arduino
int potPin = A0;
int ledPin = 9;

void setup() {
pinMode(ledPin, OUTPUT);
}

void loop() {
int potValue = analogRead(potPin); // 0–1023
int pwmValue = map(potValue, 0, 1023, 0, 255);
analogWrite(ledPin, pwmValue);
}
```

### Explanation

- `analogRead()` samples the potentiometer.
- `map()` rescales ADC output to PWM range.
- LED brightness changes proportionally with knob position.
