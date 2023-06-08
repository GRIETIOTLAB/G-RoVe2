#define SENSOR1_PIN 16 
#define SENSOR2_PIN 17
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(115200);
  // initialize the Arduino's pin as aninput
  pinMode(SENSOR1_PIN, INPUT);
  pinMode(SENSOR2_PIN, INPUT);
}

void loop() {
  // read the state of the the input pin:
  int state1 = digitalRead(SENSOR1_PIN);
  int state2 = digitalRead(SENSOR2_PIN);

  if (state1 == LOW)
    Serial.println("The obstacle is present before sensor 1");
  else
    Serial.println("The obstacle is NOT present before sensor 1");
  if (state2 == LOW)
    Serial.println("The obstacle is present before sensor 2");
  else
    Serial.println("The obstacle is NOT present before sensor 2");
  delay(100);
}
