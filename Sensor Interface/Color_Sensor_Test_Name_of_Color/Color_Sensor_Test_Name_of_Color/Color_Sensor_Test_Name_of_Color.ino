/*   23-Jun-16
 *   TechshopBD.com
 *   Developer: Md. Fahimul Islam
 *   Research Engineer
 *   
 *  This code will light RED, GREEN and BLUE LED, each for half a second.
 *  During this time for each color it'll take 50 sample voltages through A0 pin 
 *  and output average voltage on serial monitor.
 *  
 *  
 *  HOW TO CALIBRATE?:
 *  1. Aim the sensor to a fresh white page perpendicularly 1 cm away.
 *  2. Run this code.
 *  3. Fix the smaller pot until you see nearly same values for each sensor.
 *  4. If some of the values are greater than or near 1023 then adjust bigger pots carefully.
 * 
 * Connection:
 * Sensor     Arduino Uno
 * VCC        5V
 * GND        GND
 * OUT        A0
 * RED        8
 * GREEN      9
 * BLU        10
 */

#define RED 8
#define GREEN 9
#define BLUE 10
#define SENSOROUTPUT A0

#define SAMPLE_NUM 50   //how many times there will be anlogRead to make an average. 
#define MILISEC 10      //wait between every analogRead
#define REST 0          //keep it zero
double value_red = 0.0, value_green = 0.0, value_blue = 0.0, value = 0.0;

//if you want to adjust gain of the sensor by software
//change these values from 1.0.
float red_factor = 1.0, green_factor = 1.0, blue_factor = 1.0;

void setup()
{
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  digitalWrite(RED, HIGH);
  digitalWrite(GREEN, HIGH);
  digitalWrite(BLUE, HIGH);

  pinMode(SENSOROUTPUT, INPUT);

  delay(500);
  Serial.begin(9600);
  delay(100);
}


void loop()
{
  value_red = red_factor * color_intensity(RED, SAMPLE_NUM, MILISEC);
  Serial.print("Red= "); Serial.print(value_red,0);
  value_green = green_factor * color_intensity(GREEN, SAMPLE_NUM, MILISEC);
  Serial.print("     Green= "); Serial.print(value_green,0);
  value_blue = blue_factor * color_intensity(BLUE, SAMPLE_NUM, MILISEC);
  Serial.print("     Blue= "); Serial.print(value_blue,0); Serial.print("\t");
  //Serial.print("     OFF="); Serial.println(color_intensity(0, SAMPLE_NUM, MILISEC));//just leave nothing on pin 0.

  
  //To know the what color the object is?
  sort(value_red, value_green, value_blue);
  
  delay(REST);
}


/*this function takes three parameter as input:
1.the pin which will turn LED on, 2.number of samples to make an average, 3. delay between each measure.
this function outputs the average amount of light the sensor got (between 0 to 1024)
*/
double color_intensity(char colorPin, int sample_num, int milisec)
{
  double value = 0.0;
  digitalWrite(colorPin, LOW);  //updated "value_green" global variable
  delay(50);
  for (int i = 1; i <= sample_num; i++)
  {
    value += analogRead(SENSOROUTPUT);
    delay(milisec);
  }
  value = value / (double) sample_num;
  digitalWrite(colorPin, HIGH);
  return value;
}


//////////////////////////////////////////sorting
void sort(int value_red, int value_green, int value_blue)
{
  if (value_red > value_green)
  {
    if (value_red > value_blue) Serial.println("RED.");
    else Serial.println("BLUE."); //value_red < value_blue ie. value_blue > value_red > value_green
  }
  else    //ie. value_green > vlaue_red
  {
    if (value_green > value_blue) Serial.println("GREEN.");
    else Serial.println("BLUE."); //value_green < value_blue ie. value_blue > value_green > value_red
  }
}
