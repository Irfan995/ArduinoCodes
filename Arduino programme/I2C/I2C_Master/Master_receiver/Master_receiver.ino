#include <Wire.h>

void setup() {
  Wire.begin();        // join i2c bus (address optional for master)
  Serial.begin(9600);  // start serial for output
}

void loop() {
  //int i;
  Wire.requestFrom(8, 1);    // request 6 bytes from slave device #8

  while (Wire.available()) { // slave may send less than requested
   int i = Wire.read(); // receive a byte as character
   Serial.println(i);         // print the character
  }
  delay(10);
  Wire.beginTransmission(8);
  Wire.write("H");
  Wire.endTransmission(8);
  delay(20);
}
