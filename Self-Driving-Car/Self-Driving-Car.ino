
const int Stepperpin1 = 5;
const int Stepperpin2 = 4;
const int Stepperpin3 = 3;
const int Stepperpin4 = 2;
const int trig =8;
const int echo = 9;
const int b1 = 12;
const int b2 = 13;

int StepNumber = 0;
int reading;
long distanceCM;
int Store = 0;
int lastButtonState = 1;
int lastButtonState1 = 1;
int lastButtonState2 = 1;
int Store1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
pinMode(trig, OUTPUT);
pinMode(echo, INPUT);
pinMode(Stepperpin1, OUTPUT);
pinMode(Stepperpin2, OUTPUT);
pinMode(Stepperpin3, OUTPUT);
pinMode(Stepperpin4, OUTPUT);
pinMode(b1, INPUT);
pinMode(b2, INPUT);

}

void loop() {
getDistance();
int switchstate1 = digitalRead(b1);
int switchstate2 = digitalRead(b2);  
Serial.print(distanceCM);

if(switchstate1 == HIGH){
    lastButtonState = !lastButtonState;
    delay(500);
}

if(lastButtonState == HIGH){
Direction(true, 10);
if(distanceCM < 10){
lastButtonState1 = !lastButtonState1;
lastButtonState = !lastButtonState;
}
}

if(lastButtonState1 == HIGH){
Direction(false, 10);
if(switchstate1 == HIGH){
  lastButtonState = !lastButtonState;
  lastButtonState1 = !lastButtonState1;
    delay(500);
}
}

if (switchstate2 == HIGH){
   lastButtonState2 = !lastButtonState2;
    delay(500);
}   
if(lastButtonState2 == HIGH){
Direction(false, 10);
}
}

void Direction(bool Positive, int Times_Of_Rotation){
if(Positive){
  for (int i = 0; i <= Times_Of_Rotation; i++){
    Steps(0);
    delay(3);
    Steps(1);
    delay(3);
    Steps(2);
    delay(3);
    Steps(3);
    delay(3);
  }
}
else{
   for (int i = 0; i <= Times_Of_Rotation; i++){
    Steps(3);
    delay(3);
    Steps(2);
    delay(3);
    Steps(1);
    delay(3);
    Steps(0);
    delay(3);
  } 
}
}

void getDistance()
{
  digitalWrite(trig, HIGH);
  digitalWrite(trig, LOW);
  reading = pulseIn(echo, HIGH);

  distanceCM = 0.017 * reading;
}

void Steps(int StepNumber){
  
  switch(StepNumber){
    case 0:
    digitalWrite(Stepperpin1, HIGH); 
    digitalWrite(Stepperpin2, LOW); 
    digitalWrite(Stepperpin3, LOW);
    digitalWrite(Stepperpin4, LOW);
    break;

    case 1:
    digitalWrite(Stepperpin1, LOW); 
    digitalWrite(Stepperpin2, HIGH); 
    digitalWrite(Stepperpin3, LOW);
    digitalWrite(Stepperpin4, LOW);
    break;
    
    case 2:
    digitalWrite(Stepperpin1, LOW); 
    digitalWrite(Stepperpin2, LOW); 
    digitalWrite(Stepperpin3, HIGH);
    digitalWrite(Stepperpin4, LOW);
    break;

    case 3:
    digitalWrite(Stepperpin1, LOW); 
    digitalWrite(Stepperpin2, LOW); 
    digitalWrite(Stepperpin3, LOW);
    digitalWrite(Stepperpin4, HIGH);
    break;
  
  }

}
