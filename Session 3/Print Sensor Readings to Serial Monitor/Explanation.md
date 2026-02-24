# Print Sensor Readings to Serial Monitor

We will use:

- LM35 (temperature)
- HC-SR04 (distance)

## Explanation

1. Initialize Serial communication.
2. Read sensor value.
3. Convert to meaningful units.
4. Print using `Serial.print()` / `Serial.println()`.

## Code Example

```arduino
const int tempPin =A0;

void setup() {
Serial.begin(9600);
}

void loop() {

int value =analogRead(tempPin);
float voltage =value* (5.0/1023.0);
float temperature =voltage*100;// LM35: 10mV per °C

Serial.print("Temperature: ");
Serial.print(temperature);
Serial.println(" C");

delay(1000);
}
```

This prints temperature every second.
