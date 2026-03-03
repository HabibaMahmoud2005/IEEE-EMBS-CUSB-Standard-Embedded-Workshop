#include <Servo.h>

Servo myServo;

void setup() {
  myServo.attach(6);
}

void loop() {

  // Forward sweep
  for(int angle=0; angle<=180; angle++){
    myServo.write(angle);
    delay(15);
  }

  // Backward sweep
  for(int angle=180; angle>=0; angle--){
    myServo.write(angle);
    delay(15);
  }
}