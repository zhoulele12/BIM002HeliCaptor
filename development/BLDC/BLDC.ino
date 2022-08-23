#include <Servo.h>

Servo BLDC1;
void setup() {
  // put your setup code here, to run once:
  BLDC1.attach(9,3000,4000);
}

void loop() {
  // put your main code here, to run repeatedly:
  BLDC1.write(180);
}
