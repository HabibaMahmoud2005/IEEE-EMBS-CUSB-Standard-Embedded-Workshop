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