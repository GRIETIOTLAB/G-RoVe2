#include <WiFi.h>
#include <WebServer.h>


/*Put your SSID & Password*/
const char* ssid = "IDEALab03";  // Enter SSID here
const char* password = "griet@idealab";  //Enter Password here

WebServer server(80);


void setup() {
  pinMode(14, OUTPUT);
  pinMode(2,OUTPUT);
 
  
  Serial.begin(115200);
  Serial.println("Connecting to ");
  Serial.println(ssid);

  //connect to your local wi-fi network
  WiFi.begin(ssid, password);

  //check wi-fi is connected to wi-fi network
  while (WiFi.status() != WL_CONNECTED) {
  digitalWrite(2,!digitalRead(2));  
  delay(1000);
  Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected..!");
  Serial.print("Got IP: ");  Serial.println(WiFi.localIP());

  server.on("/", handle_OnConnect);
  
  
  server.on("/lightOn", handle_lightOn);
  server.on("/lightOff", handle_lightOff);
  server.onNotFound(handle_NotFound);

  server.begin();
  Serial.println("HTTP server started");
}
void loop() {
  server.handleClient();
  
}

void handle_OnConnect() {
  Serial.println("ESP connected");
 
}



void handle_NotFound(){
  server.send(404, "text/plain", "Not found");
}


void handle_lightOn(){
   digitalWrite(14, HIGH);
  digitalWrite(2, HIGH);
   server.send(200, "text/html", "Light on command received"); 

}
void handle_lightOff(){
  digitalWrite(14, LOW);
  digitalWrite(2, LOW);
   server.send(200, "text/html", "Light off  command received"); 
  
}
