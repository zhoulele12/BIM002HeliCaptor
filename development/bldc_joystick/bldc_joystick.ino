#define joyAX A0
#define joyAY A1
#define joyBX A2
#define joyBY A3
#include <Servo.h>
Servo BLDC1;
Servo BLDC2;
int input1;
int input2;
void setup() {
  Serial.begin(9600);
  BLDC1.attach(9,1000,2000);
  BLDC2.attach(11,1000,2000);
}
 
void loop() {
  // put your main code here, to run repeatedly:
  int axValue = analogRead(joyAX);
  int ayValue = analogRead(joyAY);
  int bxValue = analogRead(joyBX);
  int byValue = analogRead(joyBY);
 
  //print the values with to plot or view
  /*
  Serial.print("A0: ");
  Serial.print(axValue);
  Serial.print("\t");
  Serial.print("A1: ");
  Serial.println(ayValue);
  Serial.print("A2: ");
  Serial.print(bxValue);
  Serial.print("\t");
  Serial.print("A3: ");
  Serial.println(byValue);
  Serial.println(" ");
  */
  input1 = map(bxValue,513,1023,0,180);
  BLDC1.write(input1);
  input2 = map(axValue,513,1023,0,180);
  BLDC2.write(input2);
  
}
