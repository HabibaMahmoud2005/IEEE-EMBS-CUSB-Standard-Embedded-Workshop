**Objective:** Control LED brightness manually using a potentiometer.

**Skills Practiced:** ADC reading, PWM output, signal scaling.

**Expected Outcome:** Rotating the potentiometer smoothly adjusts LED brightness.

```arduino
const int potPin = A0; // Analog input pin
const int ledPin = 9; // PWM output pin

void setup() {
pinMode(ledPin, OUTPUT);
}

void loop() {
int potValue = analogRead(potPin); // 0–1023
int pwmValue = map(potValue, 0, 1023, 0, 255);
analogWrite(ledPin, pwmValue);
}
```
