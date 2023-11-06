#include <Stepper.h>
#include <Keypad.h>
#include <Servo.h>

const int STEPS = 2048;
Stepper myStepper(STEPS, 2,3,4,5);
int Speed = 7;
Servo MyServo;


const byte ROWS = 4; // number of rows
const byte COLS = 4; // number of coloumns

char hexaKeys[ROWS][COLS] = { 
  { '1' , '2' , '3' , 'A'},
  { '4' , '5' , '6' ,'B'},
  { '7' , '8' , '9' ,'C'},
  { '*' , '0' , '#' ,'D'}
};
char hexaKeys1[ROWS][COLS] = { 
  { '1' , '2' , '3' ,'A' },
  { '4' , '5' , '6' ,'B'},
  { '7' , '8' , '9' ,'C'},
  { '*' , '0' , '#' ,'D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6}; /* connect to the row pinouts of the keypad */
byte colPins[COLS] = {10, 11, 12 , 13}; 

Keypad myKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 
Keypad myKeypad1 = Keypad( makeKeymap(hexaKeys1), rowPins, colPins, ROWS, COLS); 

int passLength = 6;
char Data;
char Data1;
int Store;

char Password = '200132A' ;


void setup() {
Serial.begin(9600);
MyServo.attach(A0);
myStepper.setSpeed(Speed);
myKeypad.setDebounceTime(100);
}

void loop() {
char Key = myKeypad.getKey(); 
if (Key){
Data = Key;
Serial.print(Data);
}

if(Data == Password){
  char Key = myKeypad.getKey(); 
  if(Key){
    Data1 = Key;
  }
  if(Data1 == 'B'){
    Store = Store + 10000;
  }

  MyServo.write(180);
  myStepper.step(512);
  delay(10000 + Store);
  Data = 100;

}

if(Data == 100){
MyServo.write(-180);
myStepper.step(-2048);
Data = 150;
}
}







