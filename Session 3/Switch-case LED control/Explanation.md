# Switch-Case LED Control

## Explanation

Instead of multiple `if` statements, use `switch` when checking fixed values.

Example:

- 1 → LED ON
- 2 → LED OFF

## Code Example

```arduino
int ledPin =7;
int command =1; // Change manually for test

void setup() {
pinMode(ledPin,OUTPUT);
}

void loop() {

switch (command) {

case 1:
digitalWrite(ledPin,HIGH);
break;

case 2:
digitalWrite(ledPin,LOW);
break;

default:
break;
  }
}
```

`break` prevents fall-through.
