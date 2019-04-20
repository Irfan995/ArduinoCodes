#define whitePin1 2
#define whitePin2 3
#define whitePin3 4
#define redPin1 5
#define redPin2 6
#define redPin3 7
#define greenPin1 8
#define greenPin2 9
#define greenPin3 10
#define yellowPin1 11
#define yellowPin2 12
#define yellowPin3 13
String readString;

void setup() 
{
  Serial.begin(9600);
  pinMode(whitePin1, OUTPUT);
  pinMode(whitePin2, OUTPUT);
  pinMode(whitePin3, OUTPUT);
  pinMode(redPin1, OUTPUT);
  pinMode(redPin2, OUTPUT);
  pinMode(redPin3, OUTPUT);
  pinMode(greenPin1, OUTPUT);
  pinMode(greenPin2, OUTPUT);
  pinMode(greenPin3, OUTPUT);
  pinMode(yellowPin1, OUTPUT);
  pinMode(yellowPin2, OUTPUT);
  pinMode(yellowPin3, OUTPUT);

 digitalWrite(whitePin1, LOW);
 digitalWrite(whitePin2, LOW);
 digitalWrite(whitePin3, LOW);
 digitalWrite(redPin1, LOW);
 digitalWrite(redPin2, LOW);
 digitalWrite(redPin3, LOW);
 digitalWrite(greenPin1, LOW);
 digitalWrite(greenPin2, LOW);
 digitalWrite(greenPin3, LOW);
 digitalWrite(yellowPin1, LOW);
 digitalWrite(yellowPin2, LOW);
 digitalWrite(yellowPin3, LOW);
}

void loop() 
{
  while(Serial.available())
  {
    delay(3);
    char c = Serial.read();
    readString += c;
  }
  if (readString.length()>0)
  {
    Serial.println(readString);

    if(readString == "white_on")
    {
      digitalWrite(whitePin1, HIGH);
      digitalWrite(whitePin2, HIGH);
      digitalWrite(whitePin3, HIGH);
    }
     if(readString == "white_off")
    {
      digitalWrite(whitePin1, LOW);
      digitalWrite(whitePin2, LOW);
      digitalWrite(whitePin3, LOW);
    }
    if(readString == "white_blink")
    {
      digitalWrite(whitePin1, HIGH);
      delay(100);
      digitalWrite(whitePin1, LOW);
      delay(100);
      digitalWrite(whitePin2, HIGH);
      delay(100);
      digitalWrite(whitePin2, LOW);
      delay(100);
      digitalWrite(whitePin3, HIGH);
      delay(100);
      digitalWrite(whitePin3, LOW);
      delay(100);
    }
    if(readString == "red_on")
    {
      digitalWrite(redPin1, HIGH);
      digitalWrite(redPin2, HIGH);
      digitalWrite(redPin3, HIGH);
    }
     if(readString == "red_off")
    {
      digitalWrite(redPin1, LOW);
      digitalWrite(redPin2, LOW);
      digitalWrite(redPin3, LOW);
    }
    if(readString == "red_blink")
    {
      digitalWrite(redPin1, HIGH);
      delay(100);
      digitalWrite(redPin1, LOW);
      delay(100);
      digitalWrite(redPin2, HIGH);
      delay(100);
      digitalWrite(redPin2, LOW);
      delay(100);
      digitalWrite(redPin3, HIGH);
      delay(100);
      digitalWrite(redPin3, LOW);
      delay(100);
    }
    if(readString == "green_on")
    {
      digitalWrite(greenPin1, HIGH);
      digitalWrite(greenPin2, HIGH);
      digitalWrite(greenPin3, HIGH);
    }
     if(readString == "green_off")
    {
      digitalWrite(greenPin1, LOW);
      digitalWrite(greenPin2, LOW);
      digitalWrite(greenPin3, LOW);
    }
    if(readString == "green_blink")
    {
      digitalWrite(greenPin1, HIGH);
      delay(100);
      digitalWrite(greenPin1, LOW);
      delay(100);
      digitalWrite(greenPin2, HIGH);
      delay(100);
      digitalWrite(greenPin2, LOW);
      delay(100);
      digitalWrite(greenPin3, HIGH);
      delay(100);
      digitalWrite(greenPin3, LOW);
      delay(100);
    }
    if(readString == "yellow_on")
    {
      digitalWrite(yellowPin1, HIGH);
      digitalWrite(yellowPin2, HIGH);
      digitalWrite(yellowPin3, HIGH);
    }
     if(readString == "yellow_off")
    {
      digitalWrite(yellowPin1, LOW);
      digitalWrite(yellowPin2, LOW);
      digitalWrite(yellowPin3, LOW);
    }
    if(readString == "yellow_blink")
    {
      digitalWrite(yellowPin1, HIGH);
      delay(100);
      digitalWrite(yellowPin1, LOW);
      delay(100);
      digitalWrite(yellowPin2, HIGH);
      delay(100);
      digitalWrite(yellowPin2, LOW);
      delay(100);
      digitalWrite(yellowPin3, HIGH);
      delay(100);
      digitalWrite(yellowPin3, LOW);
      delay(100);
    }

    readString="";
  }
  

}
