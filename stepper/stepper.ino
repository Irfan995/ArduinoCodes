const int stepPin_1 = 3; 
const int dirPin_1 = 2; 
const int stepPin_2 = 5; 
const int dirPin_2 = 4; 
 
void setup() {
  // Sets the two pins as Outputs
  pinMode(stepPin_1,OUTPUT); 
  pinMode(dirPin_1,OUTPUT);
  pinMode(stepPin_2,OUTPUT); 
  pinMode(dirPin_2,OUTPUT);
}
void loop() {
  digitalWrite(dirPin_1,HIGH); // Enables the motor to move in a particular direction
  digitalWrite(dirPin_2,LOW);
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 1300; x++) {
    digitalWrite(stepPin_1,HIGH);
    digitalWrite(stepPin_2,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin_1,LOW);
    digitalWrite(stepPin_2,LOW); 
    delayMicroseconds(500); 
  }
  //delay(1000); // One second delay
  
  /*digitalWrite(dirPin_2,LOW); //Changes the rotations direction
  // Makes 400 pulses for making two full cycle rotation
  for(int x = 0; x < 1300; x++) {
    digitalWrite(stepPin_2,HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin_2,LOW);
    delayMicroseconds(500);
  }
  delay(1000);*/ 
}
