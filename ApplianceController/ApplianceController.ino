#include <Servo.h> //librearies 
#include <Stepper.h>
#include <Keypad.h>

Servo servo1; // servo 
Stepper myStepper(2048, 10,11,12,13); // stepper settings for steps per second and pin configuration
int LED = A0; // led pin
int Speed = 10; //stepper speed

const byte ROWS = 4; // number of rows
const byte COLS = 4; // number of coloumns

char hexaKeys[ROWS][COLS] = { 
  { 5 , 4 , 2 , 3 },
  { 9 , 7 ,'6','7'},
  {'8','9','A','B'},
  {'C','D','E','F'}
};
char hexaKeys1[ROWS][COLS] = {
  { 5 , 4 , 2 , 3 },
  { 9 , 7 ,'6','7'},
  {'8','9','A','B'},
  {'C','D','E','F'}
};

byte rowPins[ROWS] = {5, 4, 3, 2}; /* connect to the row pinouts of the keypad */
byte colPins[COLS] = {6, 7, 8, A2}; 

Keypad myKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 
Keypad myKeypad1 = Keypad( makeKeymap(hexaKeys1), rowPins, colPins, ROWS, COLS); 

int data = 8;
int data1 = 8;
const int buzzerPin = 9; // pin for the buzzer 

void setup() // device setup
{
Serial.begin(9600);


pinMode(LED,OUTPUT);
servo1.attach(A1);
myStepper.setSpeed(Speed);
myKeypad.setDebounceTime(100);
pinMode(buzzerPin, OUTPUT);

}



void loop(){

 int myKey = myKeypad.getKey();
 if(myKey){
data = myKey;
 }

  if (data == 5 ){ // 1st application is a LED light
    int myKey1 = myKeypad1.getKey();
    if(myKey1){
    data1 = myKey1;
    }
    if (data1 == 9 ){
    digitalWrite(LED,HIGH);
    delayer(1000);
    digitalWrite(LED,LOW);
    delayer(1000);
    }
  }
  if (data == 4 ){ //  2nd application is the stepper motor
    int myKey1 = myKeypad1.getKey();
    if(myKey1){
    data1 = myKey1;
    }
    if (data1 == 9 ){
      myStepper.step(512);
      delayer(1000);
      myStepper.step(-512);
      delayer(1000);
    }
  }
  if (data == 2 ){ // 3rd application is the servo
    int myKey1 = myKeypad1.getKey();
    if(myKey1){
    data1 = myKey1;
    }
    if (data1 == 9 ){
    servo1.write(90);
    delayer(1000);
    servo1.write(-90);
    delayer(1000);
    }
  }
  if (data == 3 ){ // 4th application is buzzer 
    int myKey1 = myKeypad1.getKey();
    if(myKey1){
    data1 = myKey1;
    }
    if (data1 == 9 ){
    tone(buzzerPin, 600);
    delayer(500);
    noTone(buzzerPin);
    delayer(500);

    }
  }





Serial.println(data);

}




void stop(){ // stop void function to stop in the middle of the loop 
  char myKey1 = myKeypad1.getKey();
  if(myKey1 == 7){
    data1 = 100;
  noTone(buzzerPin);
    return;
  }
}

void delayer(int time){ // integrating the stop function inside the delay 
  stop();
  delay(time);
  stop();
}










