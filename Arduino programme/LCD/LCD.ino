#include<LiquidCrystal.h>

LiquidCrystal lcd(7,8,9,10,11,12);

int ch='a';

void setup()
{
  lcd.begin(16,2);
  lcd.cursor();
}

void loop()
{
  lcd.leftToRight();
  if(ch=='q')
  lcd.setCursor(0,2);

  if(ch>'z')
  {
    lcd.clear();
    lcd.setCursor(0,0);
  }

  lcd.write(ch);
  delay(500);
  ch++;
}

