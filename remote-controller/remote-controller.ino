#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

const uint64_t pipeOut = 0xE9E8F0F0E1LL;

RF24 radio(7,8);

struct Signal{
  byte lthrottle;
  byte rthrottle;
};

Signal data;

#define joyAX A0
#define joyAY A1
#define joyBX A2
#define joyBY A3

void ResetData() 
{
  data.lthrottle = 43;
  data.rthrottle = 45;

}
void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(pipeOut);
  radio.stopListening();
//  ResetData();
  
}
 
void loop() {
  // put your main code here, to run repeatedly:
  int axValue = analogRead(joyAX);
  int ayValue = analogRead(joyAY);
  int bxValue = analogRead(joyBX);
  int byValue = analogRead(joyBY);
 
  //print the values with to plot or view
  Serial.print("A0: ");
  Serial.println(axValue);
  Serial.print("A2: ");
  Serial.println(bxValue);
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
  data.lthrottle = map(axValue,0,1023,0,90);
  data.rthrottle = map(bxValue,0,1023,0,90);
  
  Serial.println(data.lthrottle);//
  Serial.println(data.rthrottle);//
  radio.write(&data,sizeof(Signal));
}
