#include <Wire.h>
#define trigPin 3
#define echoPin 2

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  Wire.begin(8);                // join i2c bus with address #8
  Wire.onRequest(requestEvent);
  Wire.onReceive(receiveEvent);// register event
}

void loop() {
  delay(10);
}

// function that executes whenever data is requested by master
// this function is registered as an event, see setup()
void requestEvent() {
  int distance, duration;
  int r,b;
  r=1;
  b=2;
  //g='G';
  digitalWrite(trigPin, HIGH);
  delay(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2)/29.1;
  //Serial.print(distance);
  //Serial.println("");
  if (distance < 5)
  {
  Wire.write(r);
  }
  else
  {
    Wire.write(b);
  }
}

void receiveEvent(int byets)
{
 while(Wire.available())
 {
  char x=Wire.read();
  Serial.println(x);
 }
}

