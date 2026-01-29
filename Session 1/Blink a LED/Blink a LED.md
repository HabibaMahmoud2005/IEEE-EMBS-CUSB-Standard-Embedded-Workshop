# Blinking a Led

[How to Blink an LED with Arduino (Lesson #2)](https://www.youtube.com/watch?v=FKekzzj5844)

## **Explanation**

- **Pin 13** is connected to the built-in LED on most Arduino boards.

![Screenshot 2026-01-28 204953.png](Screenshot_2026-01-28_204953.png)

- `pinMode()` tells Arduino whether a pin is an input or output.
- `digitalWrite()` sets the pin to:
    - **HIGH** → LED ON
    - **LOW** → LED OFF
- `delay(1000)` pauses the program for **1000 milliseconds (1 second)**.
- The `loop()` function repeats forever, so the LED keeps blinking.

## Code

```cpp
// The pin where the LED is connected
int ledPin = 13;

void setup() {
  // Set the LED pin as an OUTPUT
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Turn the LED ON
  digitalWrite(ledPin, HIGH);
  delay(1000);   // wait 1 second

  // Turn the LED OFF
  digitalWrite(ledPin, LOW);
  delay(1000);   // wait 1 second
}
```

## **Using a Variable to Control Speed**

This makes the code easier to modify.

```cpp
int ledPin = 13;
int blinkDelay = 1000;   // milliseconds

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  digitalWrite(ledPin, HIGH);
  delay(blinkDelay);
  digitalWrite(ledPin, LOW);
  delay(blinkDelay);
}

```

## **How `delay()` Affects Speed**

- `delay(time)` pauses the program for **time milliseconds**
- **Smaller delay** → faster blinking
- **Larger delay** → slower blinking

> 1000 milliseconds = 1 second
>
