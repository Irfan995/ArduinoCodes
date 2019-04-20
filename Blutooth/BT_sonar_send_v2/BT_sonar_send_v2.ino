#include <SoftwareSerial.h>

SoftwareSerial BTserial(10, 11); // RX | TX

int trigPin = 8;    //Trig - green Jumper
int echoPin = 9;    //Echo - yellow Jumper
long duration, cm, inches;

void setup() {
  
  BTserial.begin(9600); 
  //Serial Port begin
  Serial.begin (9600);
  //Define inputs and outputs
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(4);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigPin, LOW);

   pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
 
  // convert the time into a distance
  cm = (duration/2) / 29.1;
  inches = (duration/2) / 74; 

  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  
  delay(250);


  if(cm<=8)
  {
    BTserial.print("Stop");
    BTserial.print(",");
  }
  else
  {
    BTserial.print("Start");
    BTserial.print(",");
  }
  BTserial.print(cm);
  BTserial.print(",");
  BTserial.print(inches);
  BTserial.print(",");
//message to the receiving device

delay(20);

}
