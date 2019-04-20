long sensors_average;
int sensors_sum;
int pos;
long sensors[] = {0, 0, 0, 0, 0};
void setup()
{ 
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  Serial.begin(9600);
}
void loop()
{ sensors_average = 0;
sensors_sum = 0;
for (int i = 0; i < 5; i++)
{
  sensors[i] = analogRead(i);
sensors_average += sensors[i] * i * 1000;
sensors_sum += int(sensors[i]);
}
pos = int(sensors_average / sensors_sum);//This is the required set point.
Serial.print("Sensor Values: ");
Serial.print(analogRead(A0));
Serial.print(' ');
Serial.print(analogRead(A1));
Serial.print(' ');
Serial.print(analogRead(A2));
Serial.print(' ');
Serial.print(analogRead(A3));
Serial.print(' ');
Serial.print(analogRead(A4));
Serial.println(' ');
Serial.println();
Serial.println();
Serial.print("Average: ");
Serial.print(sensors_average);
Serial.print("  ");
Serial.print("Sum: ");
Serial.print(sensors_sum);
Serial.print("  ");
Serial.print("Position: ");
Serial.println(pos);
Serial.println();
delay(1500);
}
