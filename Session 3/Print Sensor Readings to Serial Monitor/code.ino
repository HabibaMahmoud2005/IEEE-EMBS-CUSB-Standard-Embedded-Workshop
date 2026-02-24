const int tempPin = A0;

void setup() {
  Serial.begin(9600);
}

void loop() {

  int value = analogRead(tempPin);
  float voltage = value * (5.0 / 1023.0);
  float temperature = voltage * 100;   // LM35: 10mV per °C

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" C");

  delay(1000);
}