# Display Numbers 0–9 on 7-Segment

## Explanation

1. Connect segments a–g to Arduino digital pins.
2. Define binary patterns for digits (0–9).
3. Turn ON required segments for each digit.
4. Loop through digits to display them sequentially.

Assumption:

- Common Cathode display
- Segment ON → HIGH

# Keypad-Controlled Outputs

## Explanation

1. Connect keypad rows and columns to Arduino.
2. Use Keypad library to detect pressed key.
3. If pressed key is a number (0–9), display it on 7-segment.

This creates user-controlled output. 4. Move back from 180° to 0°.

This demonstrates position control using PWM pulses.

```
bytecolPins[COLS] = {A0,A1,A2,A3};
```

### Why are we using **A0–A3** for a keypad?

Even though they are called **analog pins**, on Arduino UNO they can also work as **digital pins**.

---

### Important Concept

On Arduino UNO:

- A0–A5 are **analog input pins**
- But they can ALSO be used as **digital I/O pins**

Internally:

| Analog Pin | Digital Pin Number |
| ---------- | ------------------ |
| A0         | 14                 |
| A1         | 15                 |
| A2         | 16                 |
| A3         | 17                 |
| A4         | 18                 |
| A5         | 19                 |

So this:

```
A0
```

is the same as:

```
14
```

---

### Why Use A0–A3 for Keypad?

Because a 4×4 keypad needs:

- 4 row pins
- 4 column pins
- Total = 8 digital pins

If digital pins 2–13 are already used (e.g., 7-segment display), we can use A0–A3 as extra digital pins.

So this is perfectly valid:

```arduino
pinMode(A0,INPUT);
digitalWrite(A0,HIGH);
digitalRead(A0);
```

It behaves exactly like a digital pin.

---

### When Are They Truly "Analog"?

They are analog only when using:

```arduino
analogRead(A0);
```

That reads a voltage (0–5V) and converts it to a value (0–1023).

If you use:

```arduino
digitalRead(A0);
```

then it acts as a digital input (HIGH or LOW only).

---

# Servo Sweep Control

## Explanation

1. Attach servo to a PWM pin.
2. Use Servo library for angle control.
3. Move servo gradually from 0° to 180°.
4. Move back from 180° to 0°.

This demonstrates position control using PWM pulses.
