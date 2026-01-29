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
