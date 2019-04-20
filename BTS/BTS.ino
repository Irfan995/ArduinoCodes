
#define R_PWM 10
#define L_PWM 11
#define R_EN 5
#define L_EN 6



void setup() {
  // put your setup code here, to run once:
  pinMode(R_PWM, OUTPUT);
  pinMode(L_PWM, OUTPUT);
}

void go_straight(){
  digitalWrite(R_EN, HIGH);
  digitalWrite(L_EN, HIGH);
  analogWrite(R_PWM, 120);
}

/*void go_backward(){
  digitalWrite(R_EN, LOW);
  digitalWrite(L_EN, HIGH);
  analogWrite(L_PWM, 200);
}

void my_stop(){
  digitalWrite(R_EN, LOW);
  digitalWrite(L_EN, LOW);
  analogWrite(R_PWM, 0);
}*/

void loop() {
  // put your main code here, to run repeatedly:
  
  go_straight();
  delay(1000);
 /* my_stop();
  delay(1000);
  
  go_backward();
  delay(1000);
 
  my_stop();
  delay(1000);*/
 }
