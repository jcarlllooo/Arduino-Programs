#include <LiquidCrystal_I2C.h>
#include <Servo.h>
#include <SimpleDHT.h>


#define LED_PIN 13
#define LED_PIN1 A1
Servo servo1;

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
int hSensor = A0; // humidity sensor pin
SimpleDHT11 dht11(hSensor);
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2);


byte temperature = 0;
byte humidity = 0;
int data;
int count = 40;
int count1 = 40;
int trafficCountD1 = 0;
int trafficCountD2 = 6;
int pedCountD1 = 5;
int pedCountD2 = 1;

void setup() {
Serial.begin(9600);
  
int read = dht11.read(&temperature, &humidity,NULL);
 pinMode(LED_PIN, OUTPUT);
   pinMode(LED_PIN1, OUTPUT);

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
  
	servo1.attach(A2);
  lcd.init();
  lcd.backlight();
  pinMode(hSensor, INPUT);
  
  digitalWrite(D1, HIGH);
  digitalWrite(D2, HIGH);
  digitalWrite(D3, HIGH);
  digitalWrite(D4, HIGH);
  
  lcd.print("Temperature:");
  lcd.print((int)temperature); lcd.print("*C, "); 
  

}

void loop() {
  



  

if(pedCountD1 == 5){
  digitalWrite(LED_PIN, HIGH);
  digitalWrite(LED_PIN1, LOW);
 count--;
 
 servo1.write(90);

  getDigit(1);
  getNumber(HIGH, trafficCountD1);
  delay(1);
  allLedOff();
  
  getDigit(2);
  getNumber(HIGH, trafficCountD2);
  delay(1);
  allLedOff();

 if (count == 0){
   trafficCountD1--;
   count = 40;
 }
if (trafficCountD1 < 0){
  trafficCountD2--;
  trafficCountD1 = 9;
}
}

if(trafficCountD2 < 0){
  digitalWrite(LED_PIN, LOW);
  digitalWrite(LED_PIN1, HIGH);
  trafficCountD1 = -1;
  count1--;

  servo1.write(180);
  
  getDigit(3);
  getNumber(HIGH, pedCountD1);
  delay(1);
  allLedOff();

  getDigit(4);
  getNumber(HIGH, pedCountD2);
  delay(1);
  allLedOff();

if(count1 < 0 ){
   pedCountD1--;
   count1 = 40;
}
if (pedCountD1 < 0){
  pedCountD2--;
  pedCountD1 = 9;
}

if(pedCountD2 < 0){
  pedCountD2 = 1;
  pedCountD1 = 5;
  trafficCountD1 = 0;
  trafficCountD2 = 6;
}

}

  int read = dht11.read(&temperature, &humidity,NULL);

 Serial.println("Temperature:");
    Serial.println((int)temperature); Serial.print("*C, ");

 if(read != data){
    lcd.clear();   
    lcd.print("Temperature:");
    lcd.print((int)temperature); lcd.print("*C, ");
 }
  data = read; 


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


