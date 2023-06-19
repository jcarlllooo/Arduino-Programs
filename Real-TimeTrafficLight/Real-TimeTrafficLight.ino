const int D1 = 2;  // 7 segment display pin
const int D2 = 3;  // 7 segment display pin
const int D3 = 4;  // 7 segment display pin
const int D4 = 5;  // 7 segment display pin
const int a = 6;   // 7 segment display pin
const int b = 7;   // 7 segment display pin
const int c = 8;   // 7 segment display pin
const int d = 13;   // 7 segment display pin
const int e = 10;  // 7 segment display pin
const int f = 11;  // 7 segment display pin
const int g = 12;  // 7 segment display pin
const int DP;
const int buzzerPin = 9; // pin for the buzzer
int photocell = A5; // pin for the light sensor / untrasonic sensor
int button1 = A0; // pin for button 1 decrementer 
int button2 = A1; // pin for button 2incrementer
int GLed = A4;
int YLed = A3;
int RLed = A2;



int detect;
int data;
int count1 = 600;
int count2 = 250;
int count3 = 100;
int YellowCount = 5;
int RedCount1 = 5;
int RedCount2 = 1;
int GreenCount1 = 0;
int GreenCount2 = 3;

void setup() {
Serial.begin(9600);
  

  pinMode(GLed, OUTPUT);
  pinMode(YLed, OUTPUT);
  pinMode(RLed, OUTPUT);

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
  pinMode(photocell, INPUT);
  pinMode(buzzerPin, OUTPUT);
 


  digitalWrite(D1, HIGH);
  digitalWrite(D2, HIGH);
  digitalWrite(D3, HIGH);
  digitalWrite(D4, HIGH);
  
 
}

void loop() {
  
  if (GreenCount2 > -1){
    count1--;
  getDigit(1);
  getNumber(HIGH, GreenCount1);
  delay(1);
  allLedOff();
  
  getDigit(2);
  getNumber(HIGH, GreenCount2);
  delay(1);
  allLedOff();
  ButtonGreen();
  digitalWrite(GLed, HIGH);
  
  if (count1 == 0){
    GreenCount1--;
    count1 = 600;
    if (GreenCount1 < 0){
    digitalWrite(RLed, LOW);
    GreenCount2= GreenCount2 - 1;
    GreenCount1 = 9;
    }
    if (GreenCount2 == 0){
      YellowCount= 5;
    }
    if(GreenCount2 > 6 && GreenCount1 > 0){
      GreenCount2= 6;
      GreenCount1= 0;
    }
  }
  }

else if(GreenCount2 < 0){
count3--;

  getDigit(3);
  getNumber(HIGH, YellowCount);
  delay(1);
  allLedOff();
  digitalWrite(YLed, HIGH);
  digitalWrite(GLed, LOW);


    if (count3 == 0){
    YellowCount--;
    count3 = 1000;
    if (YellowCount == 2){
      RedCount1 = 5;
      RedCount2 = 1;
    }

}
    
}


if (YellowCount <= -1){
  count2--;
  digitalWrite(YLed, LOW);
  digitalWrite(RLed, HIGH);

  getDigit(3);
  getNumber(HIGH, RedCount1);
  delay(1);
  allLedOff();

  getDigit(4);
  getNumber(HIGH, RedCount2);
  delay(1);
  allLedOff();
  ButtonRed();
int detect = analogRead(photocell);
Serial.println(detect);

if (detect < 7){
  analogWrite(buzzerPin, 600);
  delay(500);
  analogWrite(buzzerPin,0);
  delay(500);
}
  
if (count2 == 0){
    RedCount1--;
    count2 = 300;
    if (RedCount1 < 0){
    RedCount2= RedCount2 - 1;
    RedCount1 = 9;
    }
    if(RedCount2 > 3 && RedCount1 > 0){
      RedCount2= 3;
      RedCount1= 0;

    }
  }
    
    if (RedCount2 == -1){
    GreenCount2 = 3;
    GreenCount1 = 0;
    YellowCount = 5;
    }
    if (RedCount2 == 14){
    YellowCount = 5;
    }
    
}


  

}


void ButtonGreen(){
  int switchState1 = digitalRead(button1);
  int switchState2 = digitalRead(button2);

  if(switchState1 == HIGH){
    GreenCount2= GreenCount2 + 3;
    delay(500);
  }
  if(switchState2 == HIGH){
    GreenCount1= GreenCount1 - 5;
    GreenCount2= GreenCount2 - 1;
    delay(500);
  }

}
void ButtonRed(){
  int switchState1 = digitalRead(button1);
  int switchState2 = digitalRead(button2);

  if(switchState1 == HIGH){
    RedCount1= RedCount1 + 0;
    RedCount2= RedCount2 + 3;
    delay(500);
  }
  if(switchState2 == HIGH){
    RedCount1= RedCount1 - 5;
    RedCount2= RedCount2 - 1;
    delay(500);
  }

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
    
    break;

  case 2:
    digitalWrite(D1, HIGH);
    digitalWrite(D2, LOW);
    digitalWrite(D3, HIGH);
    digitalWrite(D4, HIGH);
  
    break;

  case 3:
    digitalWrite(D1, HIGH);
    digitalWrite(D2, HIGH);
    digitalWrite(D3, LOW);
    digitalWrite(D4, HIGH);
    
    break;

  case 4:
    digitalWrite(D1, HIGH);
    digitalWrite(D2, HIGH);
    digitalWrite(D3, HIGH);
    digitalWrite(D4, LOW);
   
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
  
}


