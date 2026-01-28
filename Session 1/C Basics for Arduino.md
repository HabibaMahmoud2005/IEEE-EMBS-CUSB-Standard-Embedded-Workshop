# C Basics for Arduino

# 💻 C/C++ Basics for Arduino Students

Our goal is to **use programming as a tool** to build embedded systems — not to study programming theory.

## 1. Structure of an Arduino Program

Every Arduino program has two main parts:

```cpp
void setup() {
  // runs once when the board starts
}

void loop() {
  // runs repeatedly forever
}
```

- `setup()` → used to initialize pins and settings
- `loop()` → contains the logic that runs continuously

## 2. Variables (Storing Data)

Variables are used to store values like sensor readings or pin numbers.

```cpp
int ledPin = 13;
float temperature = 25.5;
bool isOn = true;
char letter = 'A';
```

| Type | Used For |
| --- | --- |
| `int` | Whole numbers |
| `float` | Decimal numbers |
| `bool` | True/False values |
| `char` | Single characters |

## 3. Operators

Used to perform calculations or comparisons.

### Arithmetic Operators

```cpp
+   -   *   /   %
```

### Comparison Operators

```cpp
>   <   >=   <=   ==   !=
```

### Logical Operators

```cpp
&&   (AND)
||   (OR)
!    (NOT)
```

## 4. Conditions (Decision Making)

Used to control behavior based on a condition.

```cpp
if (temperature >30) {
digitalWrite(13, HIGH);
}
else {
digitalWrite(13, LOW);
}
```

## 5. Loops (Repetition)

### For Loop

Used when the number of repetitions is known.

```cpp
for (int i =0; i <5; i++) {
digitalWrite(13, HIGH);
delay(500);
digitalWrite(13, LOW);
delay(500);
}
```

### While Loop

Runs while a condition is true.

```cpp
while (buttonState == LOW) {
// keep checking
}
```

## 6. Functions

Functions help organize code into **reusable** blocks.

```cpp
voidblinkLED(int times) {
for (int i =0; i < times; i++) {
digitalWrite(13, HIGH);
delay(500);
digitalWrite(13, LOW);
delay(500);
  }
}
```

Calling the function:

```cpp
blinkLED(3);
```

## 7. Comments

Used to explain code.

```cpp
// This is a single-line comment

/*
  This is a
  multi-line comment
*/
```

## 8. Basic Arduino Functions You'll Use

| Function | Purpose |
| --- | --- |
| `pinMode(pin, mode)` | Set pin as **INPUT** or **OUTPUT** |
| `digitalWrite(pin, value)` | Set pin **HIGH** or **LOW** |
| `digitalRead(pin)` | Read digital input |
| `analogRead(pin)` | Read analog sensor |
| `analogWrite(pin, value)` | Output PWM signal |
| `delay(ms)` | Pause program |
| `Serial.print()` | Print data for debugging |

# Resources will Help You

- [https://youtube.com/playlist?list=PLv5bCJpKDWIazJBFmeTLXOJ6CwLAxvVGY&si=d7YpEJYRHxn83qWW](https://youtube.com/playlist?list=PLv5bCJpKDWIazJBFmeTLXOJ6CwLAxvVGY&si=d7YpEJYRHxn83qWW)
- [https://youtu.be/BLrHTHUjPuw?si=i9qTa_51uaCld3FT](https://youtu.be/BLrHTHUjPuw?si=i9qTa_51uaCld3FT)
