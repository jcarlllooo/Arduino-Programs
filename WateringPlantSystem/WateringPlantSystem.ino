#include <LiquidCrystal_I2C.h>
#include <Servo.h>
#include <Stepper.h>


#define sensorPin A0
#define sensorPower 8

Servo servo1;
Stepper myStepper(2048, 2,4,3,5);
int Speed = 10;
int Threshold = 500;
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2);


void setup() {
Serial.begin(9600);
  pinMode(sensorPower, OUTPUT);
  myStepper.setSpeed(Speed);
	// Initially keep the sensor OFF
	digitalWrite(sensorPower, LOW);
	servo1.attach(6);


  lcd.init();
  lcd.backlight();
}

void loop() {
  int getMoisturelvl = analogRead(sensorPin);
	Serial.print("Analog output: ");
	Serial.println(getMoisturelvl);
	
  lcd.clear();
  lcd.print("Moisture: ");
  lcd.println(getMoisturelvl);
  delay(10); 
  //get the reading from the function below and print it


  if( getMoisturelvl > Threshold){
    servo1.write(180);
    delay(100);
  myStepper.step(512);
  
  }
  if( getMoisturelvl < Threshold ){
    servo1.write(0);
    delay(1000);
  }
 
}





