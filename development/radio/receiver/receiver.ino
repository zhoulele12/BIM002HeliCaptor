#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7,8);
struct Signal{
  byte lthrottle;
  byte rthrottle;
};
int left;
int right;
boolean state = 0;
Signal data;
void ResetData() 
{
  data.lthrottle = 43;
  data.rthrottle = 45;

}
unsigned long lastRecvTime = 0;

const uint64_t pipeIn = 0xE9E8F0F0E1LL;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  ResetData();
  radio.begin();
  radio.openReadingPipe(1,pipeIn);
  radio.startListening();
  

//  pinMode(2,OUTPUT);/
//  digitalWrite(2,LOW);/
  
}


void recvData()
{
  while (radio.available()) {
//    radio.read(&state,sizeof(state));/
//    radio.read(&left, sizeof(left));/
    radio.read(&data,sizeof(Signal));
    lastRecvTime = millis();
  }
}


void loop() {
//  if(radio.available()){/
  recvData();
  
//    radio.read(&state,sizeof(state)/);
//    radio.read(&left,sizeof(left/));
  
  // put your main code here, to run repeatedly:
  unsigned long now = millis();
//  if ( now - lastRecvTime > 10/00 ) {
//    ResetData();/
//  }/
  left = data.lthrottle;
  right = data.rthrottle;
  Serial.println("Left: ");
//  Serial.println(state);/
  Serial.println(left);
  Serial.println("Right: ");
  Serial.println(right);

/*
  if(state==HIGH){
    digitalWrite(2,HIGH);  
  }
  else{
    digitalWrite(2,LOW);  
  }
  */
//  delay(50);/
}
