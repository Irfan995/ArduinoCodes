#include <NewPing.h>  //library for the SR04 ultrasonic sensor

#include <Servo.h>    //servo library, SR04 is mounted on this servo

 
Servo myservo;    

 

#define TRIGGER_PIN  6  //using analog pins as digital for SR04 sensor 

#define ECHO_PIN     7  //because I just happened to plug them in here

#define MAX_DISTANCE 200
 

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

 

#define runEvery(t) for (static typeof(t) _lasttime;(typeof(t))((typeof(t))millis() - _lasttime) > (t);_lasttime += (t))


const int ENA = 3;        //enable motor 1 = pin 1 of L293D

const int direction1 = 4;//direcion motor 1 = pin 2 of L293D

const int direction2 = 5;

const int ENB = 10;        //enable motor 2 = pin 9 of L293D

const int direction3 = 8; //direction motor 2 = pin 15 of L293D

const int direction4 = 9;





int uS;                  //value of SR04 ultrasonic sensor

int distance;            //distance in cm of ultrasonic sensor

int pos = 90;            //start position of servo = 90

int servoDirection = 0;  // sweeping left or right

int robotDirection = 0;  //0 = forward, 1 = backward, 2 = left, 3 = right

int lastRobotDirection;  //last direction of the robot

int distanceCenter;    

int distanceLeft;

int distanceRight;

int servoDelay = 20; //with this parameter you can change the sweep speed of the servo

const int speedLeft = 180; //there seems to be a bit of a difference between these cheap motors <img draggable="false" class="emoji" alt="🙁" src="https://s.w.org/images/core/emoji/2/svg/1f641.svg">

const int speedRight = 180; //this motor needs a bit more voltage to keep up with the other

long previousMillis = 0;

const int interval = 650; //interval to switch between the robotDirection, this value will determine

//how long the robot will turn left/right when it detects an obstacle

 

void setup() {               

  pinMode(ENA, OUTPUT); 

  pinMode(direction1, OUTPUT);

  pinMode(direction2, OUTPUT);

  pinMode(ENB, OUTPUT);

  pinMode(direction3, OUTPUT);

  pinMode(direction4, OUTPUT);

  analogWrite(ENA, 0);

  analogWrite(ENB, 0);

  
  Serial.begin(9600); //to use the serial monitor

  myservo.attach(11); //servo on pin 8

  myservo.write(pos); //center servo

  delay(1500); // delay so we have some time to put the robot on the floor

}

 

void loop() {


  sweepServo(); //function to sweep the servo

  getDistance();  //function to get the distance from the ultrasonic sensor

    if (pos >= 15 && pos <= 45)

  {

    distanceRight = distance;  //servo is to the right so measured distance = distanceRight

  }

  if (pos >= 135 && pos <= 165)

  {

    distanceLeft = distance; //servo is to the left so measured distance = distanceLeft

  } 

  if (pos > 70 && pos < 110)

  {

    distanceCenter = distance; //servo is centred so measured distance = distanceCenter

  }

  if (distanceCenter >= 25)    // coast is clear, full power forward

  {

    robotDirection = 0;        //move forward

  }

  else   //obstacle detected, turn left or right?

  {

    if (distanceLeft > distanceRight) 

    {

      robotDirection = 2; //turn left

    }

    if (distanceLeft < distanceRight)

    {

      robotDirection = 3; //turn right

    }

    if (distanceLeft <= 5 && distanceCenter <= 5 || distanceRight <= 5 && distanceCenter <= 5)

    {

      robotDirection = 1;  // we are stuck, lets try and backup

    }

  }

  unsigned long currentMillis = millis();  //set a timer

  if(robotDirection == 0 && robotDirection == lastRobotDirection) 

  {

    forward();

    lastRobotDirection = robotDirection;

  }

  if(robotDirection == 0 && robotDirection != lastRobotDirection && currentMillis - previousMillis > interval )

  { 

    forward();
    lastRobotDirection = robotDirection;

    previousMillis = currentMillis;

  }

  if(robotDirection == 1 && robotDirection == lastRobotDirection)

  {

    backward();

    lastRobotDirection = robotDirection;

  }

  if(robotDirection == 1 && robotDirection != lastRobotDirection && currentMillis - previousMillis > interval )

  { 

    backward();

    lastRobotDirection = robotDirection;

    previousMillis = currentMillis;

  }

  if(robotDirection == 2 && robotDirection == lastRobotDirection)

  {

    left();

    lastRobotDirection = robotDirection;

  }

  if(robotDirection == 2 && robotDirection != lastRobotDirection && currentMillis - previousMillis > interval )

  { 

    left();

    lastRobotDirection = robotDirection;

    previousMillis = currentMillis;

  }

  if(robotDirection == 3 && robotDirection == lastRobotDirection)

  {

    right();

    lastRobotDirection = robotDirection;

  }

  if(robotDirection == 3 && robotDirection != lastRobotDirection && currentMillis - previousMillis > interval )

  { 

    right();

    lastRobotDirection = robotDirection;

    previousMillis = currentMillis;

  }

}

 

void forward()

{

  digitalWrite(direction1, HIGH);

  digitalWrite(direction2, LOW);

  digitalWrite(direction3, HIGH);

  digitalWrite(direction4, LOW);

  analogWrite(ENA, speedLeft);

  analogWrite(ENB, speedRight);

}

void stop()

{

  digitalWrite(direction1, LOW);

  digitalWrite(direction1, LOW);

  digitalWrite(direction2, LOW);

  digitalWrite(direction1, LOW);

  analogWrite(ENA, 0);

  analogWrite(ENB, 0);

  
}

void backward()

{
  digitalWrite(direction1, LOW);

   digitalWrite(direction2, HIGH);

  digitalWrite(direction3, LOW);

    digitalWrite(direction4, HIGH);

  analogWrite(ENA, speedLeft+35);

  analogWrite(ENB, speedRight-15);

}

void left()

{

  digitalWrite(direction1, LOW);

  digitalWrite(direction2, HIGH);

  digitalWrite(direction3, HIGH);

    digitalWrite(direction4, LOW);

  analogWrite(ENA, speedLeft+35);

  analogWrite(ENB, speedRight);

  
}

 

void right()

{

  digitalWrite(direction1, HIGH);
  
  digitalWrite(direction2, LOW);

  digitalWrite(direction3, LOW); 

   digitalWrite(direction4, HIGH);

  analogWrite(ENA, speedLeft);

  analogWrite(ENB, speedRight-30);

  
}

void getDistance()

{

  runEvery(40)   //loop for ultrasonic measurement

  {

    uS = sonar.ping();

    distance = uS / US_ROUNDTRIP_CM;

    if (uS == NO_ECHO) // if the sensor did not get a ping       

    {

      distance = MAX_DISTANCE;      //so the distance must be bigger then the max vaulue of the sensor

    }

    Serial.print("Ping: "); //to check distance on the serial monitor

    Serial.print(distance);

    Serial.println("cm");

  }

}

 

void sweepServo()
{

  runEvery(servoDelay)  //this loop determines the servo position

  {

    if(pos < 165 && servoDirection == 0)    // 165 = servo to the left

    {                                 

      pos = pos + 5;                        // +1 was to slow

    }

    if(pos > 15 && servoDirection == 1)     // 15 = servo to the right

    {                               

      pos = pos - 5;

    }   

  }  

  if (pos == 165 )   

  {

    servoDirection = 1;  //changes the direction

  }

  if (pos == 15 )    

  {

    servoDirection = 0;  //changes the direction

  }  

  myservo.write(pos);  //move that servo!

}

