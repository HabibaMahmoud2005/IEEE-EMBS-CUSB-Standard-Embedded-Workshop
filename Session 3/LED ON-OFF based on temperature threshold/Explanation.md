# LED ON/OFF Based on Temperature Threshold

## Explanation

1. Define a threshold (e.g., 30°C).
2. Compare temperature with threshold.
3. Turn LED ON if above threshold.
4. Turn LED OFF if below.

## Code Example

```arduino
const int tempPin =A0;
const int ledPin =7;
float threshold =30.0;

void setup() {
pinMode(ledPin,OUTPUT);
Serial.begin(9600);
}

void loop() {

int value =analogRead(tempPin);
float voltage =value* (5.0/1023.0);
float temperature =voltage*100;

if (temperature>threshold) {
digitalWrite(ledPin,HIGH);
  }else {
digitalWrite(ledPin,LOW);
  }

delay(500);
}
```

LED acts as temperature warning indicator.
