//libraries
#include <Stepper.h> //stepper
#include <LedControl.h> //8x8 LED
#include <IRremote.h> //IR remote and Recieveer

//stepper motor configuration
const int stepsPerRevolution = 1650; // steps per rev
int rotationCW = 0; //Clockwise rotation
int rotationCCW = 0; //Counter Clockwise rotation
int location = 1; //default location
Stepper myStepper = Stepper(stepsPerRevolution, 11, 9, 10, 8); //pin > port

//ultrasonic sensor configuration
const int trigPin = 13; //pin 13 > port
const int echoPin = 12; //pin 12 > port
long duration = 0;
int distance = 0;

//IR reciever and remote configuration
int reciever = 3; // pin 3
IRrecv irrecv(reciever); //pin > port
#define Button_Up 0xE718FF00 //HEX code for button 0 from remote
#define Button_Down 0xAD52FF00 //HEX code for button 1 from remote
uint32_t Previous;

//8x8 LED configuration
int DIN = 4; //pin 4
int CS =  5; //pin 5
int CLK = 6; //pin 6
LedControl lc=LedControl(DIN,CLK,CS,0); //LED CONTROL pin > port
byte x[8]={0x42,0xE7,0x7E,0x3C,0x3C,0x7E,0xE7,0x42}; // produces cross as a stop/warning signal
byte check[8]={0x38,0x70,0xE0,0x70,0x38,0x1C,0x0E,0x07}; //produces check as a go signal

void printByte(byte character []){ //function to produce the go or stop/warning signal
  int i = 0;
  for(i=0;i<8;i++)
  {
    lc.setRow(0,i,character[i]);
  }
}

void readDistance()
{
  //ultrasonic reading distance
  digitalWrite(trigPin, LOW); // Clears the trigPin
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); // Sets the trigPin on HIGH state for 10 micro seconds
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW); // Reads the echoPin, returns the sound wave travel time in microseconds
}

void setup() {
  //set up for steppermotor
  myStepper.setSpeed(15); //speed

  //set up for ultrasonic sensor
  pinMode(trigPin, OUTPUT); //trigger pin
  pinMode(echoPin, INPUT); // echo pin

  //set up for IRreciever and remote
  irrecv.enableIRIn(); //enable IR input

  //set up for LED 8x8
  lc.shutdown(0,false);       //The MAX72XX is in power-saving mode on startup
  lc.setIntensity(0,15);      // Set the brightness to maximum value
  lc.clearDisplay(0);    

  //serial monitor
  Serial.begin(9600); //serial communication baud rate of 9600
}

void loop() {
  
  //ultrasonic read
  readDistance();
  long duration = pulseIn(echoPin, HIGH);// Calculating the distance
  int distance = duration * 0.034 / 2;
  Serial.print("Distance: "); // Prints the distance on the Serial Monitor
  Serial.println(distance);
  
  //Gate control through IR reciever and Remote
  if (irrecv.decode()) 
  {
    if(irrecv.decodedIRData.decodedRawData == Button_Up && distance <= 7) //open gate button
    {
      rotationCCW = 0.33*-stepsPerRevolution;
      printByte(check); //output LED: check warning sign
      myStepper.step(rotationCCW); //open gate
      location = 1;
      delay(3000); // 3 second delay before closing the gate again
    }         
    else if(irrecv.decodedIRData.decodedRawData == Button_Down && distance > 7) // close gate button
    {
      rotationCW = (0.33*stepsPerRevolution);
      printByte(x); // output LED: cross warning sign
      myStepper.step(rotationCW); // close gate
      location = (2);
      delay(3000); // 3 second delay before opening the gate again
    }
    // print IR recieved data in hexa and resume taking data from remote
    Serial.println(irrecv.decodedIRData.decodedRawData, HEX);
    irrecv.resume();
  }

  //Gate control through Ultrasonic Sensor
  else if (distance <= 7 && location == 1) // closes the gate when train is detected
  {
    rotationCW = (0.33*stepsPerRevolution);
    printByte(x); // output LED: cross warning sign
    myStepper.step(rotationCW); // close gate
    location = (2);
    delay(2000); // 3 second delay before closing the gate again
  }
  else if(distance >= 7 && location == 2) // opens the gate when train is not detected
  {
    rotationCCW = 0.33*-stepsPerRevolution;
    printByte(check); //output LED: check warning sign
    myStepper.step(rotationCCW); //open gate
    location = 1;
    delay(1500); // 3 second delay before opening the gate again
  }
}  