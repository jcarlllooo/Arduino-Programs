#include <Servo.h>
#include <Stepper.h>

 
Servo servo1;
Stepper myStepper(2048, 2,4,3,5);
int Speed = 15;

const int trig =A1;
const int echo = A0;

int reading;
long distanceCM;


void setup()
{
Serial.begin(9600);

pinMode(trig, OUTPUT);
pinMode(echo, INPUT);
servo1.attach(8);


myStepper.setSpeed(Speed);


}

void loop(){
getDistance();


if (distanceCM <= 3){
myStepper.step(512);
delay(1000);
servo1.write(90);
delay(5000);
myStepper.step(-512);
delay(1000);
servo1.write(-90);
delay(100);

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
