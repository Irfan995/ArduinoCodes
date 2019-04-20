#define relay_1 2
#define relay_2 3
#define relay_3 4
#define relay_4 5
#define relay_5 6
#define relay_6 7
#define relay_7 8
#define relay_8 9
#define in1 10
#define in2 13
#define in3 11
#define in4 12

void setup() {
  // put your setup code here, to run once:
  
  pinMode(relay_1, OUTPUT);
  pinMode(relay_2, OUTPUT);
  pinMode(relay_3, OUTPUT);
  pinMode(relay_4, OUTPUT);
  pinMode(relay_5, OUTPUT);
  pinMode(relay_6, OUTPUT);
  pinMode(relay_7, OUTPUT);
  pinMode(relay_8, OUTPUT);
  
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(relay_1, LOW);
  delay(2000);
  Serial.print("0");
  Serial.print("\t");
  digitalWrite(relay_2, HIGH);
  delay(2000);
  Serial.print("1");
  Serial.print("\t");
  digitalWrite(relay_3, LOW);
  delay(2000);
  Serial.print("0");
  Serial.print("\t");
  digitalWrite(relay_4, HIGH);
  delay(2000);
  Serial.print("1");
  Serial.print("\t");
  digitalWrite(relay_5, LOW);
  delay(2000);
  Serial.print("0");
  Serial.print("\t");
  digitalWrite(relay_6, HIGH);
  delay(2000);
  Serial.print("1");
  Serial.print("\t");
  digitalWrite(relay_7, LOW);
  delay(2000);
  Serial.print("0");
  Serial.print("\t");
  digitalWrite(relay_8, HIGH);
  delay(2000);
  Serial.print("1");
  Serial.print("\t");

  /*forward();
  delay(1000);
  reverse();
  delay(1000);*/
}

/*void forward(){
  analogWrite(in1, 255);
  analogWrite(in2, 0);
  analogWrite(in3, 255);
  analogWrite(in4, 0);
}
void reverse(){
  analogWrite(in1, 0);
  analogWrite(in2, 255);
  analogWrite(in3, 0);
  analogWrite(in4, 255);
}*/


