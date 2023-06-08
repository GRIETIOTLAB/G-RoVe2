#include <esp_now.h>
#include <WiFi.h>

char myData = 's';
int IN1 = 14;
int IN2 = 27;
int IN3 = 25;
int IN4 = 26;
unsigned long timeNow;

// callback function that will be executed when data is received
void OnDataRecv(const uint8_t * mac, const uint8_t *incomingData, int len) {
  memcpy(&myData, incomingData, sizeof(myData));
  Serial.print("Bytes received: ");
  Serial.println(len);
  Serial.print("Char: ");
  Serial.println(myData);
  Serial.println();
}
 
void setup() {
  // Initialize Serial Monitor
  Serial.begin(115200);
  
  // Set device as a Wi-Fi Station
  WiFi.mode(WIFI_STA);

  // Init ESP-NOW
  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }
  
  // Once ESPNow is successfully Init, we will register for recv CB to
  // get recv packer info
  esp_now_register_recv_cb(OnDataRecv);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT); 
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT); 

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
 
void loop() {

  switch (myData){
  case 'f':
  fwdMotion();
  timeNow= millis();
  while(millis() < timeNow + 500){}
  myData='s';
  stpMotion();
  break;
  case 'b':
  bwdMotion();
  timeNow= millis();
  while(millis() < timeNow + 500){}
  myData='s';
  stpMotion();
  break;
  case 's':
  myData='s';
  stpMotion();
  break;
  case 'l':
  lftMotion();
  timeNow= millis();
  while(millis() < timeNow + 100){}
  myData='s';
  stpMotion();
  break;
  case 'r':
  rgtMotion();
  timeNow= millis();
  while(millis() < timeNow + 100){}
  myData='s';
  stpMotion();
  break;
}


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
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

}
void rgtMotion(){
   digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);

}
