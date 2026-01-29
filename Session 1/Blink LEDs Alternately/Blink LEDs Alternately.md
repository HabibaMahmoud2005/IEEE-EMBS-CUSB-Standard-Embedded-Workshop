# Blink LEDs alternately

[(39624) How To Alternative blinking of two LEDs with programming using arduino - YouTube](https://www.youtube.com/watch?v=Pt3oQL4KEpw)

---

Blinking LEDs alternately means switching two LEDs ON and OFF in opposite states using digital output pins and delays.

This exercise teaches:

- Using **multiple digital output pins**
- Controlling timing with `delay()`
- Understanding **sequential logic**

## **1. Concept**

- Two LEDs are connected to **two different digital output pins**
- Only **one LED is ON at a time**
- The LEDs swap states after a fixed delay

## **2. Hardware**

- LED 1 → Digital pin **8**
- LED 2 → Digital pin **9**
- Each LED has a **current-limiting resistor.** An **LED (Light Emitting Diode)** must always be used with a **current-limiting resistor** to **control the amount of current** flowing through it.
    
    **👉🏼What the Resistor Does**
    
    - Limits the current to a safe value
    - Protects the LED from overheating
    - Protects the Arduino pin from excessive current

## **3. Example Code**

```cpp
int led1 =8;
int led2 =9;

voidsetup() {
pinMode(led1, OUTPUT);
pinMode(led2, OUTPUT);
}

voidloop() {
digitalWrite(led1, HIGH);// LED 1 ON
digitalWrite(led2, LOW);// LED 2 OFF
delay(500);

digitalWrite(led1, LOW);// LED 1 OFF
digitalWrite(led2, HIGH);// LED 2 ON
delay(500);
}
```

## **4. Code Explanation**

- Two pins are set as **OUTPUT**
- First state: LED1 ON, LED2 OFF
- After delay: LED1 OFF, LED2 ON
- `loop()` repeats continuously

## **5. Timing Control**

Change the delay value to adjust speed:

| Delay (ms) | Effect |
| --- | --- |
| 100 | Very fast |
| 500 | Medium |
| 1000 | Slow |

## **6. Truth Table**

| LED 1 | LED 2 | Time |
| --- | --- | --- |
| ON | OFF | First interval |
| OFF | ON | Second interval |
