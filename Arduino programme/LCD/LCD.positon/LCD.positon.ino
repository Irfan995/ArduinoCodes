#include<LiquidCrystal.h>
LiquidCrystal lcd(7,6,5,4,3,2);

void setup() {
  
  lcd.begin(16, 2);
 
  lcd.print("Hello World!");
  delay(1000);
}

void loop() {
 
  for (int positionCounter = 0; positionCounter <= 13; positionCounter++) {
  
    lcd.scrollDisplayLeft();
   
    delay(150);
  }

 
  for (int positionCounter = 0; positionCounter <= 30; positionCounter++) {
   
    lcd.scrollDisplayRight();
  
    delay(150);
  }


  for (int positionCounter = 0; positionCounter <= 16; positionCounter++) {
 
    lcd.scrollDisplayLeft();

    delay(150);
  }


  delay(1000);

}
