#include <Servo.h>
#include <SimpleDHT.h>

Servo myservo; // declaring servo name

int LED1 = 10;
int sSensor =A0; // sound sensor pin
int hSensor = 8; // humidity sensor pin

SimpleDHT11 dht11(hSensor);

byte temperature = 0;
byte humidity = 0;


void setup() {
 Serial.begin(9600);

 myservo.attach(9); 
 pinMode(LED1, OUTPUT); 
 pinMode(sSensor, INPUT);
 pinMode(hSensor, INPUT);

}

void loop() {
  int data = digitalRead(sSensor);
 
  int read;
  read = dht11.read(&temperature, &humidity,NULL);
   
  Serial.print("Sample OK: ");
  Serial.print((int)temperature); Serial.print(" *C, "); 
  Serial.print((int)humidity); Serial.println(" H");

  
   if (data == 1 ){
    kettleOFF();
    delay(1000);
   }

  if (temperature == 39 && humidity >= 93){ 
   kettleOFF();
   delay(1000);
  }
  if (temperature <= 33){
 kettleON();
  }
  Serial.println(data);
}


void kettleOFF(){
  digitalWrite(LED1, HIGH);
  myservo.write(90);
  digitalWrite(LED1, LOW);
}

void kettleON(){
  myservo.write(0);
}