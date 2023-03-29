#include <Servo.h>

Servo servo1;
Servo servo2;
const int DP = 13; // 7 segment display pin
const int D1 = 2;  // 7 segment display pin
const int D2 = 3;  // 7 segment display pin
const int D3 = 4;  // 7 segment display pin
const int D4 = 5;  // 7 segment display pin
const int a = 6;   // 7 segment display pin
const int b = 7;   // 7 segment display pin
const int c = 8;   // 7 segment display pin
const int d = 9;   // 7 segment display pin
const int e = 10;  // 7 segment display pin
const int f = 11;  // 7 segment display pin
const int g = 12;  // 7 segment display pin
const int photocell = A0;
const int trig = A1;
const int echo = A2;
int detect;
long reading;
long distanceCM;
int counter2 = 1;
int counter1 = 0;

void setup()
{
  Serial.begin(9600);
  servo1.attach(A3);
  servo2.attach(A4);

  pinMode(a, OUTPUT);  // Setting 7 segment a as an output
  pinMode(b, OUTPUT);  // Setting 7 segment b as an output
  pinMode(c, OUTPUT);  // Setting 7 segment c as an output
  pinMode(d, OUTPUT);  // Setting 7 segment d as an output
  pinMode(e, OUTPUT);  // Setting 7 segment e as an output
  pinMode(f, OUTPUT);  // Setting 7 segment f as an output
  pinMode(g, OUTPUT);  // Setting 7 segment g as an output
  pinMode(D1, OUTPUT); // Setting 7 segment d as an output
  pinMode(D2, OUTPUT); // Setting 7 segment e as an output
  pinMode(D3, OUTPUT); // Setting 7 segment f as an output
  pinMode(D4, OUTPUT); // Setting 7 segment g as an output
  pinMode(DP, OUTPUT); // Setting 7 segment g as an output
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(photocell, INPUT);

  digitalWrite(D1, HIGH);
  digitalWrite(D2, HIGH);
  digitalWrite(D3, HIGH);
  digitalWrite(D4, HIGH);
}

void loop()
{
  getDigit(1);
  getNumber(HIGH, counter1);
  delay(1);
  allLedOff();
  
  getDigit(2);
  getNumber(HIGH, counter2);
  delay(1);
  allLedOff();
  
  getDigit(3);
  getNumber(HIGH, counter1);
  delay(1);
  allLedOff();

  getDigit(4);
  getNumber(HIGH, counter2);
  delay(1);
  allLedOff();


  int detect = analogRead(photocell);

  if (detect <= 5)
  {
    if (counter2 == 1)
    {
    servo2.write(180);
      counter2 = 0;
      counter1 = 10;
    }
    if (counter2 == 0 && counter1 != 0)
    {
      servo2.write(180);
      counter1--;
    }
    delay(1000);
  }
  else
  {
    servo2.write(90);
  }
   

  getDistance();
  if (distanceCM <= 7)

  {
    if(counter2 == 0)
    {
    servo1.write(0);
      counter1++;
    }
    

    if(counter1 > 9)
    {
      counter2 = 1;
      counter1 = 0;
    }
    delay(1000);
  }
  else
  {

    servo1.write(90);
  }
 
  Serial.println(distanceCM);
}



void getDistance()
{
  digitalWrite(trig, HIGH);
  digitalWrite(trig, LOW);
  reading = pulseIn(echo, HIGH);

  distanceCM = 0.017 * reading;
}

void getDigit(int digit)
{
  switch (digit)
  {
  case 1:
    digitalWrite(D1, LOW);
    digitalWrite(D2, HIGH);
    digitalWrite(D3, HIGH);
    digitalWrite(D4, HIGH);
    digitalWrite(DP, LOW);
    break;

  case 2:
    digitalWrite(D1, HIGH);
    digitalWrite(D2, LOW);
    digitalWrite(D3, HIGH);
    digitalWrite(D4, HIGH);
    digitalWrite(DP, LOW);
    break;

  case 3:
    digitalWrite(D1, HIGH);
    digitalWrite(D2, HIGH);
    digitalWrite(D3, LOW);
    digitalWrite(D4, HIGH);
    digitalWrite(DP, HIGH);
    break;

  case 4:
    digitalWrite(D1, HIGH);
    digitalWrite(D2, HIGH);
    digitalWrite(D3, HIGH);
    digitalWrite(D4, LOW);
    digitalWrite(DP, LOW);
    break;
  }
}

void getNumber(int x, byte number)
{
  switch (number)
  {
  case 0:
    number0(x);
    break;

  case 1:
    number1(x);
    break;

  case 2:
   number2(x);
    break;

  case 3:
    number3(x);
    break;

  case 4:
    number4(x);
    break;

  case 5:
    number5(x);
    break;

  case 6:
    number6(x);
    break;

  case 7:
    number7(x);
    break;

  case 8:
    number8(x);
    break;

  case 9:
    number9(x);
    break;
  }
}

void number0(int state)
{
  digitalWrite(a, state);
  digitalWrite(b, state);
  digitalWrite(c, state);
  digitalWrite(d, state);
  digitalWrite(e, state);
  digitalWrite(f, state);
}
void number1(int state)
{
  digitalWrite(b, state);
  digitalWrite(c, state);
}
void number2(int state)
{
  digitalWrite(a, state);
  digitalWrite(b, state);
  digitalWrite(g, state);
  digitalWrite(e, state);
  digitalWrite(d, state);
}
void number3(int state)
{
  digitalWrite(a, state);
  digitalWrite(b, state);
  digitalWrite(c, state);
  digitalWrite(d, state);
  digitalWrite(g, state);
}
void number4(int state)
{
  digitalWrite(b, state);
  digitalWrite(c, state);
  digitalWrite(g, state);
  digitalWrite(f, state);
}
void number5(int state)
{
  digitalWrite(a, state);
  digitalWrite(f, state);
  digitalWrite(g, state);
  digitalWrite(c, state);
  digitalWrite(d, state);
}
void number6(int state)
{
  digitalWrite(a, state);
  digitalWrite(c, state);
  digitalWrite(d, state);
  digitalWrite(e, state);
  digitalWrite(f, state);
  digitalWrite(g, state);
}
void number7(int state)
{
  digitalWrite(a, state);
  digitalWrite(b, state);
  digitalWrite(c, state);
}
void number8(int state)
{
  digitalWrite(a, state);
  digitalWrite(b, state);
  digitalWrite(c, state);
  digitalWrite(d, state);
  digitalWrite(e, state);
  digitalWrite(f, state);
  digitalWrite(g, state);
}
void number9(int state)
{
  digitalWrite(a, state);
  digitalWrite(b, state);
  digitalWrite(c, state);
  digitalWrite(d, state);
  digitalWrite(f, state);
  digitalWrite(g, state);
}

void allLedOff()
{ // creating a function that all leds off for off button
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
  digitalWrite(DP, LOW);
}
