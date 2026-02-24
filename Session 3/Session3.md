# Serial Communication

## UART (Universal Asynchronous Receiver/Transmitter)

### Definition

**UART** is a **hardware communication protocol** used for **serial communication** between devices.

It converts **parallel data (inside a microcontroller)** into **serial data (one bit at a time)** for transmission, and vice versa.

It is called:

- **Universal** → widely used standard
- **Asynchronous** → no shared clock signal
- **Receiver/Transmitter** → can send and receive data

### Where UART Is Used

- Arduino ↔ PC (Serial Monitor)
- Microcontroller ↔ Bluetooth module
- Microcontroller ↔ GPS module
- Debug communication

On Arduino UNO, UART uses:

- **D0 → RX (Receive)**
- **D1 → TX (Transmit)**

### Why “Asynchronous”?

- UART **does NOT use a clock line**
- Both devices must agree on a **baud rate**

Example:

```arduino
Serial.begin(9600);
```

This means:

- 9600 bits per second

Both sides must use the same baud rate.

### How UART Sends Data

UART sends data in a **frame format**.

Typical frame structure:

```
Start Bit | Data Bits | Optional Parity | Stop Bit(s)
```

Example (8N1 format):

- 1 Start bit
- 8 Data bits
- No parity
- 1 Stop bit

### Transmission Steps

1. Line is normally HIGH (idle)
2. Start bit → LOW
3. Send 8 bits (LSB first)
4. Stop bit → HIGH

## What is Serial Communication?

Serial communication is a method of sending data **one bit at a time** between two devices.

In Arduino, it is commonly used for:

- Communication between **Arduino and PC**
- Debugging programs
- Printing sensor readings

It uses the **UART protocol** on:

- **D0 (RX) → Receive**
- **D1 (TX) → Transmit**

## Basic Serial Functions

### 1) `Serial.begin(baudRate)`

Initializes serial communication.

```arduino
Serial.begin(9600);
```

- Must be written inside `setup()`
- Baud rate must match Serial Monitor → The communication speed you set in your code **must be exactly the same** as the speed selected in the Serial Monitor window.

### 2) `Serial.print()`

Prints data on the **same line**.

```arduino
Serial.print("Temperature: ");
```

### 3) `Serial.println()`

Prints data and moves to **new line**.

```arduino
Serial.println(value);
```

## Serial Monitor (Debugging Tool)

The **Serial Monitor** allows you to:

- View sensor readings
- Print variable values
- Debug logic errors

📌 Open from:

```
Tools → Serial Monitor
```

# Sensors

Sensors are **input devices** that measure physical quantities and convert them into electrical signals.

# Temperature Sensors

## 1) LM35

- Analog temperature sensor
- Output voltage proportional to temperature
- 10 mV per °C

Example:

- 250 mV → 25°C

### Reading LM35

```arduino
int value =analogRead(A0);
float voltage =value* (5.0/1023.0);
float temperature =voltage*100;
```

These lines read the analog value from pin A0, convert it from a 0–1023 digital ADC value into a voltage (0–5V), then convert that voltage into temperature in °C.

## 2) DHT11

- Digital temperature & humidity sensor
- Uses digital communication
- Requires a library ( DHT sensor library )

Features:

- Measures temperature
- Measures humidity
- Slower than LM35
- Moderate accuracy

### Comparison: DHT11 vs LM35

### Type of Sensor

| Feature          | DHT11                  | LM35             |
| ---------------- | ---------------------- | ---------------- |
| Signal Type      | Digital                | Analog           |
| Measures         | Temperature + Humidity | Temperature only |
| Library Required | Yes                    | No               |

### Measurement Capability

| Feature           | DHT11       | LM35                       |
| ----------------- | ----------- | -------------------------- |
| Temperature Range | 0°C to 50°C | -55°C to 150°C             |
| Humidity          | ✅ Yes      | ❌ No                      |
| Resolution        | 1°C         | Very fine (depends on ADC) |

### Accuracy

| Feature           | DHT11         | LM35                           |
| ----------------- | ------------- | ------------------------------ |
| Temp Accuracy     | ±2°C          | ±0.5°C (typical)               |
| Stability         | Moderate      | High                           |
| Noise Sensitivity | Low (digital) | Higher (analog noise possible) |

👉 **LM35 is more precise for temperature-only applications.**

### Speed

| Feature                 | DHT11                 | LM35   |
| ----------------------- | --------------------- | ------ |
| Response Speed          | Slow (~1 reading/sec) | Fast   |
| Best for Fast Sampling? | ❌ No                 | ✅ Yes |

### When to Use Each?

Use LM35 When:

- You need **high accuracy temperature**
- You need **fast readings**
- You want simple implementation
- Humidity is NOT required
- Industrial or control systems

Example:

- Temperature control system
- Overheat protection
- Lab measurements

Use DHT11 When:

- You need **both temperature and humidity**
- Project is educational
- Precision is not critical
- Low cost is important

Example:

- Weather station project
- Smart room monitoring
- Beginner IoT project

# Ultrasonic Sensor – HC-SR04

Used to measure **distance** using sound waves.

## Working Principle

1. Sends ultrasonic pulse.
2. Waits for echo.
3. Measures time taken.
4. Calculates distance.

### Distance Formula

```arduino
Distance = (Time × Speed of Sound) / 2
```

Speed of sound ≈ 343 m/s

## Basic Example Logic

```arduino
digitalWrite(trig,LOW);           // Ensures the trigger pin starts from LOW
delayMicroseconds(2);             // Stabilizes the sensor before sending a pulse

digitalWrite(trig,HIGH);
delayMicroseconds(10);           // Sends a 10 microsecond HIGH pulse
// This tells the sensor to emit an ultrasonic sound wave (≈40 kHz).
digitalWrite(trig,LOW);

long duration =pulseIn(echo,HIGH);   // measures how long the echo pin stays HIGH
float distance =duration*0.034/2;   // Divide by 2 → because it traveled forward AND back
```

# Comparisons & Decision Making

Used to control behavior based on conditions.

## Comparison Operators

| Operator | Meaning          |
| -------- | ---------------- |
| `>`      | Greater than     |
| `<`      | Less than        |
| `==`     | Equal to         |
| `>=`     | Greater or equal |
| `<=`     | Less or equal    |
| `!=`     | Not equal        |

```arduino
if (temperature > 30) {
Serial.println("High Temperature");
}
```

# Threshold Concept

A **threshold** is a predefined limit used to trigger an action.

Example:

- Temperature threshold = 30°C
- Distance threshold = 10 cm

## Example

```arduino
if (distance < 10) {
Serial.println("Object too close!");
}
```

👉 Thresholds simplify decision-making in embedded systems.

# Functions in Arduino

Functions help organize code into reusable blocks.

## Why Use Functions?

Advantages of Modular Programming:

- Code is cleaner
- Easier debugging
- Reusability
- Better readability
- Reduces repetition

# Function Syntax

```arduino
return_type functionName(parameters) {
// body
return value;
}
```

## Example 1: Function Without Return

```arduino
void printMessage() {
Serial.println("Hello");
}
```

## Example 2: Function With Return

```arduino
int add(int a,int b) {
return a+b;
}
```

# Passing Arguments & Returning Values

## Passing Arguments

Arguments allow the function to receive input.

```arduino
int square(int x) {
return x*x;
}
```

Calling:

```arduino
int result =square(4);
```

## Returning Values

- `void` → no return
- `int`, `float`, `bool` → returns value

Example:

```arduino
float readTemperature() {
int value =analogRead(A0);
float voltage =value* (5.0/1023.0);
return voltage*100;
}
```

# switch-case Statement

Used when checking **multiple fixed values**.

## Syntax

```arduino
switch(variable) {

casevalue1:
// code
break;

casevalue2:
// code
break;

default:
// code
}
```

## Example

```arduino
switch(option) {

case1:
Serial.println("LED ON");
break;

case2:
Serial.println("LED OFF");
break;

default:
Serial.println("Invalid choice");
}
```

## Important: `break`

- Stops execution of switch block
- Without it → fall-through occurs

# continue Statement

Used inside loops.

- Skips current iteration
- Moves to next loop cycle

Example:

```arduino
for (inti =0;i<5;i++) {

if (i==2)
continue;

Serial.println(i);
}
```

Output:

```
0
1
3
4
```

# Practical Integration Example

Example System:

- Read temperature
- If temperature > threshold → Print warning
- Measure distance
- If object too close → Print alert
- Use functions for modular design

Structure:

```arduino
float readTemperature();
float readDistance();
void checkTemperature(float t);
void checkDistance(float d);
```

This design:

- Separates logic
- Improves readability
- Makes debugging easier using Serial Monitor

# Common Beginner Mistakes

1. Forgetting `Serial.begin()`
2. Wrong baud rate
3. Missing `break` in switch
4. Using `==` incorrectly
5. Forgetting `return` in non-void function
6. Blocking program using too many `delay()` calls
7. Not defining thresholds clearly
