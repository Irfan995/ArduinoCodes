int sensorValue = 0;

void setup() {
  pinMode(A0, INPUT);
  Serial.begin(9600);
}

void loop() {
   
  Serial.print(analogRead(A0));
  Serial.println();
  delay(500);
}
