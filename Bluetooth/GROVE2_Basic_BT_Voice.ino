#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;

int IN1 = 14;
int IN2 = 27;
int IN3 = 25;
int IN4 = 26;
unsigned long timeNow;
void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT); 
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT); 

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);

  Serial.begin(115200);
  SerialBT.begin("Grove2-05"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");
  }

void loop() {
   char c;
 if(SerialBT.available()){
 c = SerialBT.read();
switch (c){
  case 'f':
  fwdMotion();
  break;
  case 'b':
  bwdMotion();
  break;
  case 's':
  stpMotion();
  break;
  case 'l':
  lftMotion();
  timeNow= millis();
  while(millis() < timeNow + 300){}
  stpMotion();
  break;
  case 'r':
  rgtMotion();
  timeNow= millis();
  while(millis() < timeNow + 300){}
  stpMotion();
  break;
}
}
 
 }

void setDirection() {

  fwdMotion();
  delay(3000);
  bwdMotion();
  delay(3000);
  stpMotion();
  
}

void fwdMotion(){
   digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

}
void bwdMotion(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  
}
void stpMotion(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
void lftMotion(){
   digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

}
void rgtMotion(){
   digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);

}
