#define SENSOR1_PIN 16 
#define SENSOR2_PIN 17
int IN1 = 14;
int IN2 = 27;
int IN3 = 25;
int IN4 = 26;
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(115200);
  // initialize the Arduino's pin as aninput
  pinMode(SENSOR1_PIN, INPUT);
  pinMode(SENSOR2_PIN, INPUT);
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
  // read the state of the the input pin:
  int state1 = digitalRead(SENSOR1_PIN);
  int state2 = digitalRead(SENSOR2_PIN);
  if((state1 == LOW)&&(state2 == LOW)) 
  {
  fwdMotion();
  delay(100);
  stpMotion();
  }
  if((state1 == HIGH) && (state2 == HIGH))
  {
    stpMotion();
    delay(100);
  }
  if((state1 == LOW) && (state2 == HIGH))
  {
  rgtMotion();
  delay(50);
  stpMotion();
  }
  if((state1 == HIGH) && (state2 == LOW))
  {
  lftMotion();
  delay(50);
  stpMotion();
  }
  delay(1000);
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
   digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

}
