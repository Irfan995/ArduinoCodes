#include<LiquidCrystal.h>
#define ledPin 12
#define switchPin 11
#define buzzPin 10
#define lPot A1
#define tPot A2

LiquidCrystal lcd(7,6,5,4,3,2);

int switchState = 0;
int ledState = LOW;
int buzzState = LOW;
unsigned long previousMillis = 0;
const long interval = 1000; 

int val1 = 0;
int val2 = 0;

int lastVal1 = 0;
int lastVal2 = 0;

void setup()
{
  pinMode(ledPin, OUTPUT);
  pinMode(buzzPin, OUTPUT);
  pinMode(switchPin, INPUT);
  pinMode(lPot, INPUT);
  pinMode(tPot, INPUT);
  
  lcd.begin(16,2);
  lcd.setCursor(1,0);
  lcd.print("Please wait...");
  delay(1000);
  lcdfunc();
  lcdDelay();
  //Serial.begin(9600);
}

void loop()
{
  switchState = digitalRead(switchPin);
  if(switchState == 1)
  {
    ledBuzz();
    val1 = analogRead(lPot);
    val2 = analogRead(tPot);
    lastVal1 = val1;
    lastVal2 = val2;
        
    lcd.setCursor(1,0);
    lcd.print("Set Load: ");
    lcd.setCursor(11,0);
    lcd.print(val1);
    lcd.print("    ");
    lcd.setCursor(1,1);
    lcd.print("Set Thick: ");
    lcd.setCursor(12,1);
    lcd.print(val2);
    lcd.print("    ");
    delay(250);
    
  }
  else
  {
    digitalWrite(ledPin, LOW);
    digitalWrite(buzzPin, LOW);
    lcd.setCursor(1,0);
    lcd.print("Load: ");
    lcd.setCursor(7,0);
    lcd.print(lastVal1);
    lcd.print("    ");
    lcd.setCursor(0,1);
    lcd.print(" ");
    lcd.print("Thickness: ");
    lcd.setCursor(12,1);
    lcd.print(lastVal2);
  
    lcd.print("    ");
    delay(50);
  }
  //Serial.print(lastVal1);
  //Serial.print("    ");
  //Serial.println(lastVal2);
}

void lcdfunc()
{
  lcd.clear();

  lcd.display();

  lcd.setCursor(1,0);
  lcd.print("Industrial");
  lcd.setCursor(3,1);
  lcd.print("Automation");
  delay(1500);

  lcdDelay();
  
  lcd.setCursor(2,0);
  lcd.print("with Object");
  lcd.setCursor(3,1);
  lcd.print("Sorting");
  delay(1500);

  lcdDelay();

  lcd.setCursor(1,0);
  lcd.print("Presented by:-");
  delay(1500);

  lcdDelay();

  lcd.setCursor(1,0);
  lcd.print("Saikot, Parvez");
  lcd.setCursor(1,1);
  lcd.print("Rahim, Nafis");
  delay(2000);

  lcdDelay();

  lcd.setCursor(2,0);
  lcd.print("& Digonto");
  delay(2000);

  lcdDelay();
  
  
}

void lcdDelay()
{
  lcd.noDisplay();
  delay(10);
  lcd.display();
  lcd.clear();
}

void ledBuzz()
{
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
}
previousMillis = currentMillis;

    
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }
    digitalWrite(ledPin, ledState);
    digitalWrite(buzzPin, ledState);
  }

