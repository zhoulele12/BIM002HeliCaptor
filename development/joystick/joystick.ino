#define joyAX A0
#define joyAY A1
#define joyBX A2
#define joyBY A3

void setup() {
  Serial.begin(9600);
}
 
void loop() {
  // put your main code here, to run repeatedly:
  int axValue = analogRead(joyAX);
  int ayValue = analogRead(joyAY);
  int bxValue = analogRead(joyBX);
  int byValue = analogRead(joyBY);
 
  //print the values with to plot or view

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
}
