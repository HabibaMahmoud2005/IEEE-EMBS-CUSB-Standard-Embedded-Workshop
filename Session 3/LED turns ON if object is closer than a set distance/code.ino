const int trig =9;
const int echo =10;
const int ledPin =7;
float distanceThreshold =15.0;

void setup() {
pinMode(trig,OUTPUT);
pinMode(echo,INPUT);
pinMode(ledPin,OUTPUT);
}

void loop() {

digitalWrite(trig,LOW);
delayMicroseconds(2);

digitalWrite(trig,HIGH);
delayMicroseconds(10);
digitalWrite(trig,LOW);

long duration =pulseIn(echo,HIGH);
float distance =duration*0.034/2;

if (distance < distanceThreshold) {
digitalWrite(ledPin,HIGH);
  }
  else {
digitalWrite(ledPin,LOW);
  }

delay(200);
}