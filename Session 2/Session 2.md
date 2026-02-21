# Digital Debouncing, Analog Input, and PWM (Arduino UNO)

This document presents a concise and structured explanation of **digital debouncing**, **analog vs. digital signals**, **ADC usage**, and **PWM output** on the Arduino UNO. The content is organized to reflect typical signal flow: **input → processing → output**.

## 1. Digital Debouncing

### 1.1 Why Debouncing Is Necessary

Mechanical switches do **not** transition cleanly from **OFF** to **ON**. When a button is pressed or released, the internal contacts physically **bounce** for a short period (typically a few milliseconds), generating multiple rapid **HIGH/LOW** transitions.

**Without debouncing:**

- A single physical press may be interpreted as **multiple presses** by the microcontroller.

### 1.2 Simple Software Debouncing Using `delay()`

The most basic software debouncing technique introduces a short delay after detecting a state change to allow the signal to stabilize.

**Debouncing steps:**

1. Detect an initial button press.
2. Wait for a short, fixed delay (typically 20–50 ms).
3. Read the button state again.
4. If the state is unchanged, treat the press as valid.

This delay gives the mechanical contacts time to settle.

### 1.3 Debouncing Example

```cpp
const int buttonPin = 2;
const int ledPin = 13;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  if (digitalRead(buttonPin) == LOW) {   // Button pressed
    delay(50);                           // Debounce delay
    if (digitalRead(buttonPin) == LOW) { // Confirm press
      digitalWrite(ledPin, HIGH);
    }
  } else {
    digitalWrite(ledPin, LOW);
  }
}
```

**Explanation:**

1. `digitalRead()` detects a potential press.
2. `delay(50)` pauses execution to ignore bouncing.
3. The button is read again.
4. If still pressed, the input is considered stable.

### 1.4 Choosing an Appropriate Delay

- **10–20 ms** → High-quality switches, fast response
- **30–50 ms** → Most common and reliable choice
- **> 50 ms** → Adds unnecessary latency

> ⚠️ Note: `delay()` blocks the CPU and is unsuitable for time-critical or multitasking systems.
> 

## 2. Analog vs. Digital Signals

### 2.1 Digital Signals

A **digital signal** has only two possible logic states.

| State | Meaning | Voltage (Arduino UNO) |
| --- | --- | --- |
| LOW | Logic 0 | 0 V |
| HIGH | Logic 1 | 5 V |

**Typical uses:**

- Push buttons
- LEDs (ON/OFF)
- Logic control

```cpp
digitalWrite(13, HIGH);
```

### 2.2 Analog Signals

An **analog signal** can take **any voltage value within a continuous range**.

On the Arduino UNO:

```
0 V → 5 V (continuous)
```

**Typical sources:**

- Potentiometers
- Temperature sensors
- Light sensors (LDR)

Analog signals represent **real-world physical quantities**.

![Arduino UNO Board](images/arduino%20adc%20pins%201.webp)

## 3. ADC (Analog-to-Digital Converter)

Microcontrollers operate digitally and **cannot process analog voltages directly**. An **ADC** converts analog voltages into numerical values.

### 3.1 Arduino UNO ADC Specifications

- Resolution: **10-bit**
- Number of levels:
    
    ```
    2¹⁰ = 1024
    ```
    
- Output range:
    
    ```
    0 → 1023
    ```
    

| Input Voltage | ADC Output |
| --- | --- |
| 0 V | 0 |
| 2.5 V | ≈ 512 |
| 5 V | 1023 |

### 3.2 ADC Conversion Formula

```
ADC Value = (Vin / Vref) × 1023
```

Where `Vref` is the reference voltage (5 V by default).

## 4. `analogRead()`

`analogRead()` samples an analog input pin and returns the corresponding **digital ADC value**.

### 4.1 Basic Example: Potentiometer

```cpp
int potValue;

void setup() {
  Serial.begin(9600);
}

void loop() {
  potValue = analogRead(A0);
  Serial.println(potValue);
  delay(200); // Prevent Serial Monitor flooding
}
```

**Characteristics:**

- Input voltage: **0–5 V**
- Output value: **0–1023**
- Conversion time: **~100 µs**

> `analogRead()` is significantly slower than `digitalRead()` due to ADC conversion.
> 

### 4.2 Converting ADC Value to Voltage

```cpp
int sensorPin = A0;
int digitalValue = 0;
float analogVoltage = 0.0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  digitalValue = analogRead(sensorPin);
  analogVoltage = (digitalValue * 5.0) / 1023.0;

  Serial.print("Digital Value = ");
  Serial.print(digitalValue);
  Serial.print(" | Analog Voltage = ");
  Serial.println(analogVoltage);

  delay(1000);
}
```

### 4.3 `analogReference()`

The function `analogReference(type)` configures the **reference voltage** used by the ADC, allowing improved resolution for lower voltage ranges.

## 5. `analogWrite()` and PWM

The Arduino UNO **cannot output true analog voltages**. Instead, it uses **Pulse Width Modulation (PWM)** to simulate analog behavior.

### 5.1 Pulse Width Modulation (PWM)

PWM controls the **average power** delivered to a load by rapidly switching a digital signal ON and OFF.

- Voltage amplitude remains constant
- **Duty cycle** changes

| Duty Cycle | Effective Output |
| --- | --- |
| 0% | 0 V |
| 50% | ≈ 2.5 V |
| 100% | 5 V |

### 5.2 `analogWrite()`

```cpp
analogWrite(9, 128); // ~50% duty cycle
```

- Value range: **0–255** (8-bit)
- Works only on **PWM-capable pins**

| Value | Duty Cycle |
| --- | --- |
| 0 | 0% |
| 127 | ≈ 50% |
| 255 | 100% |

**Applications:**

- LED brightness control
- Motor speed control
- Buzzer volume control

## 6. PWM Frequency Basics

PWM signals also have a **frequency**, which affects system behavior.

### Arduino UNO PWM Frequencies

| Pins | Frequency |
| --- | --- |
| 3, 9, 10, 11 | ~490 Hz |
| 5, 6 | ~980 Hz |

![arduino pwm pins.webp](images/arduino%20pwm%20pins.webp)

**Why frequency matters:**

- LEDs → usually insensitive
- Motors → low frequency causes vibration
- Buzzers → frequency determines pitch

> `analogWrite()` modifies **duty cycle only**, not frequency.
> 

## 7. `map()` Function

`map()` rescales a value from one range into another.

### Syntax

```cpp
map(value, fromLow, fromHigh, toLow, toHigh);
```

### Example: Potentiometer to PWM

```cpp
int pot;
int pwm;

void loop() {
  pot = analogRead(A0);      // 0–1023
  pwm = map(pot, 0, 1023, 0, 255);
  analogWrite(9, pwm);
}
```

Used when:

- ADC and PWM ranges differ
- Sensor scaling is required

## 8. Buzzer Basics

A **buzzer** converts electrical signals into sound.

| Type | Description |
| --- | --- |
| Active | Produces sound when powered |
| Passive | Requires a frequency signal |

### 8.1 `tone()` Function

`tone()` generates a square wave of a specified frequency.

```cpp
tone(8, 1000);  // 1 kHz
 delay(500);
 noTone(8);
```

**Parameters:**

- Pin: Output pin
- Frequency: Sound pitch (Hz)

Used for alarms, alerts, and simple melodies.

> ⚠️ `tone()` uses timers and may interfere with PWM on certain pins.
>

**What actually happens internally?**

1. The microcontroller:

- Configures a hardware timer.
- Toggles pin 8 HIGH and LOW automatically.
- Creates a square wave.

Since it's a square wave:

- HIGH for 0.5 ms
- LOW for 0.5 ms

Repeats continuously, So the pin switches: HIGH → LOW → HIGH → LOW ...
1000 times per second.

2. delay(500);

This pauses the program for: 500 ms
During this time:

- The CPU is waiting
- The timer continues running
- The 1 kHz tone keeps playing

So the buzzer sounds for half a second.

3. noTone(8);

- This Stops the timer
- Stops toggling pin 8
- Sets the pin LOW
- Sound stops

## References

- [ElectronicWings – Arduino ADC Overview](https://www.electronicwings.com/arduino/adc-in-arduino)
- https://www.electronicwings.com/arduino/adc-in-arduino
