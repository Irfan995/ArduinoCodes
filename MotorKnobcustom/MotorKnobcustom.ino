/*
 * MotorKnob
 *
 * A stepper motor follows the turns of a potentiometer
 * (or other sensor) on analog input 0.
 *
 * http://www.arduino.cc/en/Reference/Stepper
 * This example code is in the public domain.
 */

//#include <Stepper.h>

// change this to the number of steps on your motor
//#define STEPS 100

// create an instance of the stepper class, specifying
// the number of steps of the motor and the pins it's
// attached to
//Stepper stepper(STEPS, 10, 8, 11, 9);

// the previous reading from the analog input
int previous = 0;

void setup()
{
  // set the speed of the motor to 30 RPMs
  //stepper.setSpeed(30);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(A0, INPUT);
  digitalWrite(10,HIGH);digitalWrite(8, HIGH);digitalWrite(11, HIGH);digitalWrite(9, HIGH);
  delay(500);
}

void loop()
{
  anticlockwise();
  anticlockwise();
  anticlockwise();
  delay(2000);
  clockwise();
  clockwise();
  clockwise();
  digitalWrite(10, LOW);digitalWrite(8, LOW);digitalWrite(11, LOW);digitalWrite(9, HIGH);
  delay(2000);
  
  
  /*
  int val = analogRead(A0);
  float deg = (360/1024)*val;
  int degree = int(deg);
  int i = abs(degree-previous);
  if(degree > previous){
    for(int x=0;x<= i; x++){
    clockwise();
    }
  }
  else if(degree < previous){
    for(int x=0;x<= i; x++){
    anticlockwise();
    }
  }
  else stopstep();
  previous = degree;
  */
}
void anticlockwise(){
digitalWrite(10, HIGH);digitalWrite(8, LOW);digitalWrite(11, LOW);digitalWrite(9, LOW);
  delay(500);
  digitalWrite(10, LOW);digitalWrite(8, HIGH);digitalWrite(11, LOW);digitalWrite(9, LOW);
  delay(500);
  digitalWrite(10, LOW);digitalWrite(8, LOW);digitalWrite(11, HIGH);digitalWrite(9, LOW);
  delay(500);
  digitalWrite(10, LOW);digitalWrite(8, LOW);digitalWrite(11, LOW);digitalWrite(9, HIGH);
  delay(500);
}

void clockwise(){
digitalWrite(10, LOW);digitalWrite(8, LOW);digitalWrite(11, LOW);digitalWrite(9, HIGH);
  delay(500);
  digitalWrite(10, LOW);digitalWrite(8, LOW);digitalWrite(11, HIGH);digitalWrite(9, LOW);
  delay(500);
  digitalWrite(10, LOW);digitalWrite(8, HIGH);digitalWrite(11, LOW);digitalWrite(9, LOW);
  delay(500);
  digitalWrite(10, HIGH);digitalWrite(8, LOW);digitalWrite(11, LOW);digitalWrite(9, LOW);
  delay(500);
}

void stopstep(){
  digitalWrite(10, HIGH);digitalWrite(8, HIGH);digitalWrite(11, HIGH);digitalWrite(9, HIGH);
}
