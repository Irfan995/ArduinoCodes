#define potPin1 A1
#define potPin2 A2
int val1 = 0;
int val2 = 0;


void setup() {
  pinMode(potPin1, INPUT);
  pinMode(potPin2, INPUT);
  Serial.begin(9600);
}

void loop() {
  val1 = analogRead(potPin1);
  val2 = analogRead(potPin2);
  Serial.print(val1);
  Serial.print("    ");
  Serial.println(val2);
  
}
