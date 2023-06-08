#include <esp_now.h>
#include <WiFi.h>
const int joystick_x_pin = A0; 
const int joystick_y_pin = A3;
// REPLACE WITH YOUR RECEIVER MAC Address
uint8_t broadcastAddress[] = {0xB0, 0xB2, 0x1C, 0xA8, 0xF6, 0xB8};

char myData;

esp_now_peer_info_t peerInfo;

// callback when data is sent
void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) {
  Serial.print("\r\nLast Packet Send Status:\t");
  Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Delivery Success" : "Delivery Fail");
}
 
void setup() {
  // Init Serial Monitor
  Serial.begin(115200);
 
  // Set device as a Wi-Fi Station
  WiFi.mode(WIFI_STA);

  // Init ESP-NOW
  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }

  // Once ESPNow is successfully Init, we will register for Send CB to
  // get the status of Trasnmitted packet
  esp_now_register_send_cb(OnDataSent);
  
  // Register peer
  memcpy(peerInfo.peer_addr, broadcastAddress, 6);
  peerInfo.channel = 0;  
  peerInfo.encrypt = false;
  
  // Add peer        
  if (esp_now_add_peer(&peerInfo) != ESP_OK){
    Serial.println("Failed to add peer");
    return;
  }
}
 
void loop() {
  // Set values to send
  myData = 's';
  ///////////////////////
  int x_adc_val, y_adc_val; 
  float x_volt, y_volt;
  x_adc_val = analogRead(joystick_x_pin); 
  y_adc_val = analogRead(joystick_y_pin);
  x_volt = ( ( x_adc_val * 3.3 ) / 4095 );  /*Convert digital value to voltage */
  y_volt = ( ( y_adc_val * 3.3 ) / 4095 );  /*Convert digital value to voltage */
  
  if(x_volt > 3.0)
  {
    Serial.println("Right");
  myData = 'r';
  }
  else if(x_volt < 0.5)
  {
  Serial.println("Left");
  myData = 'l';
  }
  
  if(y_volt > 3.0)
  {
  Serial.println("Backward");
  myData = 'b';
  }
  else if(y_volt < 0.5)
  {
  Serial.println("Forward");
  myData = 'f';
  }
  
    /////////////////////
  
  // Send message via ESP-NOW
  esp_err_t result = esp_now_send(broadcastAddress, (uint8_t *) &myData, sizeof(myData));
   
  if (result == ESP_OK) {
    Serial.println("Sent with success");
  }
  else {
    Serial.println("Error sending the data");
  }
  delay(1000);
}
