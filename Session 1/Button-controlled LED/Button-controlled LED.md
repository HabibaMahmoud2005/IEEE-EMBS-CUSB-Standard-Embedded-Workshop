# Button-controlled LED

[Arduino Tutorials: Control a LED with a Button](https://www.youtube.com/watch?v=ksNbEuhO4fU)

---

A **button-controlled LED** is a simple digital input/output application where a **push button** is used to control the **ON and OFF state of an LED**.

## **1. Concept**

- The **button** acts as a **digital input**
- The **LED** acts as a **digital output**
- When the button is pressed, the Arduino reads the input and changes the LED state accordingly

## **2. Hardware Setup (Basic Idea)**

- **Button connected to:** Digital input pin
- **LED connected to:** Digital output pin
- **Resistor required** to avoid floating input or LED damage

👉 For beginners, Arduino’s **internal pull-up resistor** is recommended.

## **3. Button Using Internal Pull-Up Resistor**

### **How It Works**

- Button not pressed → pin reads **HIGH**
- Button pressed → pin reads **LOW**

This is called **active-LOW logic**.

## **4. Example Code**

```cpp
int ledPin = 13;
int buttonPin = 2;

voidsetup() {
pinMode(ledPin, OUTPUT);
pinMode(buttonPin, INPUT_PULLUP);
}

voidloop() {
int buttonState = digitalRead(buttonPin);

if (buttonState == LOW) {
	// Button pressed
	digitalWrite(ledPin, HIGH);
  }
  else {
	digitalWrite(ledPin, LOW);
  }
}
```

## **5. Code Explanation**

- `INPUT_PULLUP` enables an internal resistor
- No external resistor needed
- `digitalRead()` checks button state
- `if` statement decides LED ON or OFF
- **Digital pins D0–D13** can be used as button inputs but Avoid if possible:
    
    
    | Pin | Reason |
    | --- | --- |
    | D0, D1 | Used for Serial communication |
    | D13 | Connected to built-in LED |
    | RESET | Resets the board |
    
    > Best beginner choices: **D2–D7**
    > 

## **6. Truth Table**

| Button State | Pin Reading | LED |
| --- | --- | --- |
| Not pressed | HIGH | OFF |
| Pressed | LOW | ON |
