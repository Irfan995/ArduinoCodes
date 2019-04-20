#define rmotorf 10
#define rmotorb 9
#define lmotorf 6
#define lmotorb 5
#define ena 11
#define enb 3
#define sensor_1 A0
#define sensor_2 A1
#define sensor_3 A2
#define sensor_4 A3
#define sensor_5 A4
#define sensor_6 A5
#define sensor_7 A6

int max_speed = 200;
int left_speed;
int right_speed;
int sensor_sum, pos, error, proportional = 0, intregal = 0, derivative = 0;
long long unsigned sensor_avg;
long sensor[] = {0, 0, 0};
int kp = 0;
int kd = 0;
int ki = 0;


void setup()
{
  pinMode(sensor_1, INPUT);
  pinMode(sensor_2, INPUT);
  pinMode(sensor_3, INPUT);
  pinMode(sensor_4, INPUT);
  pinMode(sensor_5, INPUT);
  pinMode(sensor_6, INPUT);
  pinMode(sensor_7, INPUT);
  pinMode (lmotorf, OUTPUT);
  pinMode (lmotorb, OUTPUT);
  pinMode (rmotorf, OUTPUT);
  pinMode (rmotorb, OUTPUT);
  pinMode(ena, OUTPUT);
  pinMode(enb, OUTPUT);
  digitalWrite (lmotorf, HIGH);
  digitalWrite (lmotorb, HIGH);
  digitalWrite (rmotorf, HIGH);
  digitalWrite (rmotorb, HIGH);
  Serial.begin(9600);
}


void loop()
{
  sensor_read();
  pid_calc();
  turn();
  motor_drive(120, 120);
}

void pid_calc()
{
  int last_proportional;
  pos = int(sensor_avg / sensor_sum);
  proportional = pos - 2500;
  intregal = intregal + proportional;
  derivative = proportional - last_proportional;
  last_proportional = proportional;

  error = int(proportional * kp + intregal * ki + derivative * kd);
}

void sensor_read()
{
  sensor_avg = 0;
  sensor_sum = 0;

  for (int i = 0; i < 7; i++)
  {
    sensor[i] = analogRead(i);
    sensor_avg += sensor[i] * i * 1000;
    sensor_sum += int(sensor[i]);
  }
}

void turn()
{


  if (error < -256)
  {
    error = -256;
  }
  if (error > 256)
  {
    error = 256;
  }

  if (error < 0)
  {
    right_speed = max_speed + error;
    left_speed = max_speed;
  }

  else
  {
    right_speed = max_speed;
    left_speed = max_speed - error;
  }
}

void motor_drive(int right_speed, int left_speed)
{
  if (left_speed == 0)
  {
    digitalWrite(lmotorf, HIGH);
    digitalWrite(lmotorb, HIGH);
  }
  else if (left_speed > 0)
  {
    digitalWrite(lmotorf, HIGH);
    digitalWrite(lmotorb, LOW);
  }

  else if (left_speed < 0)
  {
    digitalWrite(lmotorf, LOW);
    digitalWrite(lmotorb, HIGH);
  }

  if (right_speed == 0)
  {
    digitalWrite(rmotorf, HIGH);
    digitalWrite(rmotorb, HIGH);
  }
  else if (right_speed > 0)
  {
    digitalWrite(rmotorf, HIGH);
    digitalWrite(rmotorb, LOW);
  }

  else if (right_speed < 0)
  {
    digitalWrite(rmotorf, LOW);
    digitalWrite(rmotorb, HIGH);
  }

  if (left_speed > 254) left_speed = 254;
  if (left_speed < -254) left_speed = -254;
  if (right_speed > 254) right_speed = 254;
  if (right_speed < -254) right_speed = -254;

  analogWrite(ena, abs(right_speed));
  analogWrite(enb, abs(left_speed));
}

