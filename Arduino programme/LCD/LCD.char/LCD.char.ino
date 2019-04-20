#include<LiquidCrystal.h>
LiquidCrystal lcd(7,8,9,10,11,12);



byte o[8] = {
  B11111,
  B00010,
  B00101,
  B00001,
  B10001,
  B01001,
  B00110,
  B00000,
};
byte a[8] = {
  B11000,
  B01000,
  B01000,
  B01000,
  B01000,
  B11000,
  B01000,
};
byte mo[8] = {
  B11111,
  B01001,
  B01001,
  B01001,
  B11111,
  B11001,
  B00001,
  B00000,
};
byte ro[8] = {
  B01111,
  B00011,
  B00101,
  B01001,
  B00101,
  B00011,
  B00101,
  B00000,
};
byte e[8] = {
  B00111,
  B00101,
  B00001,
  B00001,
  B10001,
  B01111,
  B00001,
  B00000,
};
byte ko[8] = {
  B01111,
  B00011,
  B00101,
  B01001,
  B00101,
  B00011,
  B00001,
  B00000,
};




void setup() {
  lcd.createChar(0,o);
  lcd.createChar(1,a);
  lcd.createChar(2,mo);
  lcd.createChar(3,ro);
  lcd.createChar(4,e);
  lcd.createChar(5,ko);
  lcd.begin(16,2);
   lcd.write(byte(0));
  lcd.write(byte(1));
  lcd.write(byte(2));
  lcd.write(byte(3));

}

void loop() {
  lcd.setCursor(5,0);
  
  lcd.write(byte(4));
  lcd.write(byte(5));
  

}
