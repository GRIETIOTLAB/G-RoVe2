int range;
int trigPin = 12;
int echoPin = 13;
int IN1 = 14;
int IN2 = 27;
int IN3 = 25;
int IN4 = 26;

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT); 
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT); 
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  Serial.begin(115200);
  }

void loop() {

   while((range = getRange())!= 0){ 
    Serial.println(range);
    if(range > 29)
    {
      fwdMotion();
    }
    
    if(range < 28)
    {
    stpMotion();
    delay(500);
    bwdMotion();
    delay(500);
    stpMotion();
    delay(100);
    lftMotion();
    delay(500);
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
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

}
void rgtMotion(){
   digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);

}
int getRange(){
long duration,distance;  
digitalWrite(trigPin, LOW);
delayMicroseconds(2);   
digitalWrite(trigPin, HIGH);     // send waves for 10 us
delayMicroseconds(10);
duration = pulseIn(echoPin, HIGH); // receive reflected waves
distance = duration / 58.2;   // convert to distance
return distance;
delay(50);
}
