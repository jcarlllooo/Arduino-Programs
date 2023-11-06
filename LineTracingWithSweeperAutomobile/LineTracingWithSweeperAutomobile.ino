#include <Ultrasonic.h>
#include <Servo.h>
#include <AFMotor.h>

Servo myservo;

const int infra1 = 9;
const int infra2 = 10;

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

Ultrasonic ultrasonic(A0, A1);
int distance;
int sweep = 5;

void setup()
{
    // put your setup code here, to run once:
    Serial.begin(9600);
    myservo.attach(A5);
    ultrasonic.setTimeout(40000UL);
}

void loop()
{
    // Controlling speed (0 = off and 255 = max speed):
    int IRright = digitalRead(infra2);
    int IRleft = digitalRead(infra1);

   if(IRright == 0 && IRleft == 0){
    motor3.setSpeed(50);
    motor4.setSpeed(50);
    motor3.run(BACKWARD);
    motor4.run(BACKWARD);
   }

   if(IRright == 1 && IRleft == 1){
    motor3.run(RELEASE);
    motor4.run(RELEASE);
   }
if(IRright == 1 ){
   motor3.setSpeed(155);
   motor3.run(BACKWARD);
    motor4.run(RELEASE);
   }
if(IRleft == 1 ){
    motor4.setSpeed(155);
    motor3.run(RELEASE);
    motor4.run(BACKWARD);
   }

    Serial.print("Distance in CM: ");
    Serial.println(IRleft);
    distance = ultrasonic.read();
    Serial.print("Distance in A: ");
    Serial.println(IRright);
    if (distance <= sweep)
    {
        motor3.run(RELEASE);
        motor4.run(RELEASE);
        myservo.write(180);
        delay(1000);
        myservo.write(-180);
        delay(1000);
    }
}
