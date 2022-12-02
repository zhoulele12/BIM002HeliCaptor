#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Servo.h>

Servo BLDC1;
Servo BLDC2;
RF24 radio(7,8);
struct Signal{
  byte lthrottle;
  byte rthrottle;
};
int left;
int right;
int input1;
int input2;

Signal data;
void ResetData() 
{
  data.lthrottle = 43;
  data.rthrottle = 45;

}

const uint64_t pipeIn = 0xE9E8F0F0E1LL;

void setup() {
  Serial.begin(9600);
//  ResetData();
  radio.begin();
  radio.openReadingPipe(1,pipeIn);
  radio.startListening();
  BLDC1.attach(3,1000,2000);
  BLDC2.attach(5,1000,2000);
}


void recvData()
{
  while (radio.available()) {
    radio.read(&data,sizeof(Signal));   
  }
}


void loop() {
  recvData();
  left = data.lthrottle;
  right = data.rthrottle;
  Serial.println("Left: ");
  Serial.println(left);
  Serial.println("Right: ");
  Serial.println(right);
  input1 = map(left,43,90,0,90);
  input2 = map(right,45,90,0,90);
  
  BLDC1.write(input1);
  BLDC2.write(input1);
}
