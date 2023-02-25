const int switch1 = 2; // declaring pin number of push buttons
const int switch2 = 3;// declaring pin number of push buttons
const int switch3 = 4;// declaring pin number of push buttons
const int switch4 = 13;// declaring pin number of push buttons
const int pinOne = 5; // declaring pin number of LED
const int pinTwo = 6;// declaring pin number of LED
const int pinThree = 7;// declaring pin number of LED
const int pinFour = 8;// declaring pin number of LED
const int pinFive = 9;// declaring pin number of LED
const int pinSix = 10;// declaring pin number of LED
const int pinSeven = 11;// declaring pin number of LED
const int pinEight = 12;// declaring pin number of LED

int switchState = 0; // declaring switchStare to 0

void setup()
{
  Serial.begin(9600);

  pinMode(switch1, INPUT); // setting pinMode of buttons as input
  pinMode(switch2, INPUT);// setting pinMode of buttons as input
  pinMode(switch3, INPUT);// setting pinMode of buttons as input
  pinMode(switch4, INPUT);// setting pinMode of buttons as input
  pinMode(pinOne, OUTPUT); // setting pinMode of Leds as output
  pinMode(pinTwo, OUTPUT);// setting pinMode of Leds as output
  pinMode(pinThree, OUTPUT);// setting pinMode of Leds as output
  pinMode(pinFour, OUTPUT);// setting pinMode of Leds as output
  pinMode(pinFive, OUTPUT);// setting pinMode of Leds as output
  pinMode(pinSix, OUTPUT);// setting pinMode of Leds as output
  pinMode(pinSeven, OUTPUT);// setting pinMode of Leds as output
  pinMode(pinEight, OUTPUT);// setting pinMode of Leds as output
}

void loop()
{ // setting the loop function

  int switchstate = digitalRead(switch4); // reading the state of buttons
  int switchstate2 = digitalRead(switch1);// reading the state of buttons
  int switchstate3 = digitalRead(switch2);// reading the state of buttons
  int switchstate4 = digitalRead(switch3);// reading the state of buttons

  if (switchstate2 == LOW)
  {                  // creating a boolean function for switchstate2 is equal to LOW, the following statement will run
    ILikeToMoveIt(); // calling ILikeToMoveIt() function
  }

  if (switchstate3 == LOW)
  { // creating a boolean function for switchstate3 is equal to LOW, the following statement will run
    MarriedLife();// calling MarriedLife()function
  }

  if (switchstate4 == LOW)
  { // creating a boolean function for switchstate4 is equal to LOW, the following statement will run
  allGirlsAreTheSame();// calling allGirlsAreTheSame() function
  }
}

void tone(char a, char b, int delayDurationOn, int delayDurationOff)
{ // creating statement that will lit two LEDs and delay input in the on and off 
  
  {
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    int switchstate = digitalRead(switch4);
    if (switchstate == LOW)
    {
      allLedOff();
      return;
    }
    delay(delayDurationOff);
  }
  {
    digitalWrite(a, LOW);
    digitalWrite(b, LOW);
    int switchstate = digitalRead(switch4);
    if (switchstate == LOW)
    {
      allLedOff();
      return;
    }
    delay(delayDurationOff);
  }
}

void OnOffLedFromOneToOne(int delayDurationOn, int delayDurationOff)
{ // creating statement that will lit leds from one to one-eight using incrementer and decrementer
  for (int i = pinOne; i <= pinOne; i++)
  {
    digitalWrite(i, HIGH);
    int switchstate = digitalRead(switch4);
    if (switchstate == LOW)
    {
      allLedOff();
      return;
    }
    delay(delayDurationOn);
  }
  for (int i = pinOne; i >= pinOne; i--)
  {
    digitalWrite(i, LOW);
    int switchstate = digitalRead(switch4);
    if (switchstate == LOW)
    {
      allLedOff();
      return;
    }
    delay(delayDurationOff);
  }
}

void OnOffLedFromOneToTwo(int delayDurationOn, int delayDurationOff)
{ // creating statement that will lit leds from one to one-eight using incrementer and decrementer
  for (int i = pinOne; i <= pinTwo; i++)
  {
    digitalWrite(i, HIGH);
    int switchstate = digitalRead(switch4);
    if (switchstate == LOW)
    {
      allLedOff();
      return;
    }
    delay(delayDurationOn);
  }
  for (int i = pinTwo; i >= pinOne; i--)
  {
    digitalWrite(i, LOW);
    int switchstate = digitalRead(switch4);
    if (switchstate == LOW)
    {
      allLedOff();
      return;
    }
    delay(delayDurationOff);
  }
}

void OnOffLedFromOneToThree(int delayDurationOn, int delayDurationOff)
{ // creating statement that will lit leds from one to one-eight using incrementer and decrementer
  for (int i = pinOne; i <= pinThree; i++)
  {
    digitalWrite(i, HIGH);
    int switchstate = digitalRead(switch4);
    if (switchstate == LOW)
    {
      allLedOff();
      return;
    }
    delay(delayDurationOn);
  }
  for (int i = pinThree; i >= pinOne; i--)
  {
    digitalWrite(i, LOW);
    int switchstate = digitalRead(switch4);
    if (switchstate == LOW)
    {
      allLedOff();
      return;
    }
    delay(delayDurationOff);
  }
}

void OnOffLedFromOneToFour(int delayDurationOn, int delayDurationOff)
{ // creating statement that will lit leds from one to one-eight using incrementer and decrementer
  for (int i = pinOne; i <= pinFour; i++)
  {
    digitalWrite(i, HIGH);
    int switchstate = digitalRead(switch4);
    if (switchstate == LOW)
    {
      allLedOff();
      return;
    }
    delay(delayDurationOn);
  }
  for (int i = pinFour; i >= pinOne; i--)
  {
    digitalWrite(i, LOW);
    int switchstate = digitalRead(switch4);
    if (switchstate == LOW)
    {
      allLedOff();
      return;
    }
    delay(delayDurationOff);
  }
}

void OnOffLedFromOneToFive(int delayDurationOn, int delayDurationOff)
{ // creating statement that will lit leds from one to one-eight using incrementer and decrementer
  for (int i = pinOne; i <= pinFive; i++)
  {
    digitalWrite(i, HIGH);
    int switchstate = digitalRead(switch4);
    if (switchstate == LOW)
    {
      allLedOff();
      return;
    }
    delay(delayDurationOn);
  }
  for (int i = pinFive; i >= pinOne; i--)
  {
    digitalWrite(i, LOW);
    int switchstate = digitalRead(switch4);
    if (switchstate == LOW)
    {
      allLedOff();
      return;
    }
    delay(delayDurationOff);
  }
}

void OnOffLedFromOneToSix(int delayDurationOn, int delayDurationOff)
{ // creating statement that will lit leds from one to one-eight using incrementer and decrementer
  for (int i = pinOne; i <= pinSix; i++)
  {
    digitalWrite(i, HIGH);
    int switchstate = digitalRead(switch4);
    if (switchstate == LOW)
    {
      allLedOff();
      return;
    }
    delay(delayDurationOn);
  }
  for (int i = pinSix; i >= pinOne; i--)
  {
    digitalWrite(i, LOW);
    int switchstate = digitalRead(switch4);
    if (switchstate == LOW)
    {
      allLedOff();
      return;
    }
    delay(delayDurationOff);
  }
}

void OnOffLedFromOneToSeven(int delayDurationOn, int delayDurationOff)
{ // creating statement that will lit leds from one to one-eight using incrementer and decrementer
  for (int i = pinOne; i <= pinSeven; i++)
  {
    digitalWrite(i, HIGH);
    int switchstate = digitalRead(switch4);
    if (switchstate == LOW)
    {
      allLedOff();
      return;
    }
    delay(delayDurationOn);
  }
  for (int i = pinSeven; i >= pinOne; i--)
  {
    digitalWrite(i, LOW);
    int switchstate = digitalRead(switch4);
    if (switchstate == LOW)
    {
      allLedOff();
      return;
    }
    delay(delayDurationOff);
  }
}

void OnOffLedFromOneToEight(int delayDurationOn, int delayDurationOff)
{ // creating statement that will lit leds from one to one-eight using incrementer and decrementer
  for (int i = pinOne; i <= pinEight; i++)
  {
    digitalWrite(i, HIGH);
    int switchstate = digitalRead(switch4);
    if (switchstate == LOW)
    {
      allLedOff();
      return;
    }
    delay(delayDurationOn);
  }
  for (int i = pinEight; i >= pinOne; i--)
  {
    digitalWrite(i, LOW);
    int switchstate = digitalRead(switch4);
    if (switchstate == LOW)
    {
      allLedOff();
      return;
    }
    delay(delayDurationOff);
  }
}

void delayPerLedLighting(int Delay)
{ // creating delay parameters with button stopper
  int switchstate = digitalRead(switch4);
  if (switchstate == LOW)
  {
    allLedOff();
    return; // return to the loop
  }
  delay(Delay);
}

void allLedOff()
{ // creating a function that all leds off for off button
  digitalWrite(pinOne, LOW);
  digitalWrite(pinTwo, LOW);
  digitalWrite(pinThree, LOW);
  digitalWrite(pinFour, LOW);
  digitalWrite(pinFive, LOW);
  digitalWrite(pinSix, LOW);
  digitalWrite(pinSeven, LOW);
  digitalWrite(pinEight, LOW);
}

void ILikeToMoveIt()
{ // *1st song* Madagascar I Like To Move It The Best of King Julien
  {

    OnOffLedFromOneToFour(30, 20);
    delayPerLedLighting(250);
    OnOffLedFromOneToSix(20, 35);
    delayPerLedLighting(250);

    OnOffLedFromOneToFour(30, 20);
    delayPerLedLighting(250);
    OnOffLedFromOneToSix(20, 35);
    delayPerLedLighting(250);

    OnOffLedFromOneToFour(30, 20);
    delayPerLedLighting(250);
    OnOffLedFromOneToSix(20, 35);
    delayPerLedLighting(250);

    OnOffLedFromOneToFour(30, 20);
    delayPerLedLighting(250);
    OnOffLedFromOneToSix(20, 35);
    delayPerLedLighting(250);

    OnOffLedFromOneToFour(30, 20);
    delayPerLedLighting(250);
    OnOffLedFromOneToSix(20, 35);
    delayPerLedLighting(250);

    OnOffLedFromOneToFour(30, 20);
    delayPerLedLighting(250);
    OnOffLedFromOneToSix(20, 35);
    delayPerLedLighting(250);

    OnOffLedFromOneToFour(30, 20);
    delayPerLedLighting(250);
    OnOffLedFromOneToSix(20, 35);
    delayPerLedLighting(250);

    OnOffLedFromOneToFour(30, 20);
    delayPerLedLighting(250);
    OnOffLedFromOneToSix(20, 35);
    delayPerLedLighting(250);

    OnOffLedFromOneToFour(30, 20);
    delayPerLedLighting(250);
    OnOffLedFromOneToSix(20, 35);
    delayPerLedLighting(250);

    OnOffLedFromOneToFour(30, 20);
    delayPerLedLighting(250);
    OnOffLedFromOneToSix(20, 35);
    delayPerLedLighting(250);

    OnOffLedFromOneToFour(30, 20);
    delayPerLedLighting(250);
    OnOffLedFromOneToSix(20, 35);
    delayPerLedLighting(250);

    OnOffLedFromOneToFour(30, 20);
    delayPerLedLighting(250);
    OnOffLedFromOneToSix(20, 35);
    delayPerLedLighting(250);

    OnOffLedFromOneToFour(30, 20);
    delayPerLedLighting(250);
    OnOffLedFromOneToSix(20, 35);
    delayPerLedLighting(250);

    OnOffLedFromOneToFour(30, 20);
    delayPerLedLighting(250);
    OnOffLedFromOneToSix(20, 35);
    delayPerLedLighting(250);

    OnOffLedFromOneToFour(30, 20);
    delayPerLedLighting(250);
    OnOffLedFromOneToSix(20, 35);
    delayPerLedLighting(250);

    OnOffLedFromOneToFour(30, 20);
    delayPerLedLighting(250);
    OnOffLedFromOneToSix(20, 35);
    delayPerLedLighting(250);

    OnOffLedFromOneToFour(30, 20);
    delayPerLedLighting(250);
    OnOffLedFromOneToSix(20, 35);
    delayPerLedLighting(250);

    OnOffLedFromOneToFour(30, 20);
    delayPerLedLighting(250);
    OnOffLedFromOneToSix(20, 35);
    delayPerLedLighting(250);

    OnOffLedFromOneToFour(30, 20);
    delayPerLedLighting(250);
    OnOffLedFromOneToSix(20, 35);
    delayPerLedLighting(250);

    OnOffLedFromOneToFour(30, 20);
    delayPerLedLighting(250);
    OnOffLedFromOneToSix(20, 35);
    delayPerLedLighting(250);

    OnOffLedFromOneToFour(30, 20);
    delayPerLedLighting(250);
    OnOffLedFromOneToSix(20, 35);
    delayPerLedLighting(250);

    OnOffLedFromOneToFour(30, 20);
    delayPerLedLighting(250);
    OnOffLedFromOneToSix(20, 35);
    delayPerLedLighting(250);

    OnOffLedFromOneToFour(30, 20);
    delayPerLedLighting(250);
    OnOffLedFromOneToSix(20, 35);
    delayPerLedLighting(250);

    OnOffLedFromOneToFour(30, 20);
    delayPerLedLighting(250);
    OnOffLedFromOneToSix(20, 35);
    delayPerLedLighting(250);

    OnOffLedFromOneToFour(30, 20);
    delayPerLedLighting(250);
    OnOffLedFromOneToSix(20, 35);
    delayPerLedLighting(250);

    OnOffLedFromOneToFour(30, 20);
    delayPerLedLighting(250);
    OnOffLedFromOneToSix(20, 35);
    delayPerLedLighting(250);

    delayPerLedLighting(5350);

    OnOffLedFromOneToFour(20, 10);
    delayPerLedLighting(270);
    OnOffLedFromOneToEight(10, 25);
    delayPerLedLighting(270);

    OnOffLedFromOneToFour(20, 10);
    delayPerLedLighting(270);
    OnOffLedFromOneToEight(10, 25);
    delayPerLedLighting(270);

    OnOffLedFromOneToFour(20, 10);
    delayPerLedLighting(270);
    OnOffLedFromOneToEight(10, 25);
    delayPerLedLighting(270);

    OnOffLedFromOneToFour(20, 10);
    delayPerLedLighting(270);
    OnOffLedFromOneToEight(10, 25);
    delayPerLedLighting(270);

    OnOffLedFromOneToFour(20, 10);
    delayPerLedLighting(270);
    OnOffLedFromOneToEight(10, 25);
    delayPerLedLighting(270);

    OnOffLedFromOneToFour(20, 10);
    delayPerLedLighting(270);
    OnOffLedFromOneToEight(10, 25);
    delayPerLedLighting(270);

    OnOffLedFromOneToFour(20, 10);
    delayPerLedLighting(270);
    OnOffLedFromOneToEight(10, 25);
    delayPerLedLighting(270);

    OnOffLedFromOneToFour(20, 10);
    delayPerLedLighting(270);
    OnOffLedFromOneToEight(10, 25);
    delayPerLedLighting(270);

    OnOffLedFromOneToFour(20, 10);
    delayPerLedLighting(270);
    OnOffLedFromOneToEight(10, 25);
    delayPerLedLighting(270);

    OnOffLedFromOneToFour(20, 10);
    delayPerLedLighting(270);
    OnOffLedFromOneToEight(10, 25);
    delayPerLedLighting(270);

    OnOffLedFromOneToFour(20, 10);
    delayPerLedLighting(270);
    OnOffLedFromOneToEight(10, 25);
    delayPerLedLighting(270);

    OnOffLedFromOneToFour(20, 10);
    delayPerLedLighting(270);
    OnOffLedFromOneToEight(10, 25);
    delayPerLedLighting(270);

    OnOffLedFromOneToFour(20, 10);
    delayPerLedLighting(270);
    OnOffLedFromOneToEight(10, 25);
    delayPerLedLighting(270);

    OnOffLedFromOneToFour(20, 10);
    delayPerLedLighting(270);
    OnOffLedFromOneToEight(10, 25);
    delayPerLedLighting(270);

    OnOffLedFromOneToFour(20, 10);
    delayPerLedLighting(270);
    OnOffLedFromOneToEight(10, 25);
    delayPerLedLighting(270);

    OnOffLedFromOneToFour(20, 10);
    delayPerLedLighting(270);
    OnOffLedFromOneToEight(10, 25);
    delayPerLedLighting(270);

    OnOffLedFromOneToFour(20, 10);
    delayPerLedLighting(270);
    OnOffLedFromOneToEight(10, 25);
    delayPerLedLighting(270);

    OnOffLedFromOneToFour(20, 10);
    delayPerLedLighting(270);
    OnOffLedFromOneToEight(10, 25);
    delayPerLedLighting(270);

    OnOffLedFromOneToFour(20, 10);
    delayPerLedLighting(270);
    OnOffLedFromOneToEight(10, 25);
    delayPerLedLighting(270);

    OnOffLedFromOneToFour(20, 10);
    delayPerLedLighting(270);
    OnOffLedFromOneToEight(10, 25);
    delayPerLedLighting(270);

    OnOffLedFromOneToFour(20, 10);
    delayPerLedLighting(270);
    OnOffLedFromOneToEight(10, 25);
    delayPerLedLighting(270);

    OnOffLedFromOneToFour(20, 10);
    delayPerLedLighting(270);
    OnOffLedFromOneToEight(10, 25);
    delayPerLedLighting(270);

    OnOffLedFromOneToFour(20, 10);
    delayPerLedLighting(270);
    OnOffLedFromOneToEight(10, 25);
    delayPerLedLighting(270);

    OnOffLedFromOneToFour(20, 10);
    delayPerLedLighting(270);
    OnOffLedFromOneToEight(10, 25);
    delayPerLedLighting(270);

    OnOffLedFromOneToFour(20, 10);
    delayPerLedLighting(270);
    OnOffLedFromOneToEight(10, 25);
    delayPerLedLighting(270);

    OnOffLedFromOneToFour(20, 10);
    delayPerLedLighting(270);
    OnOffLedFromOneToEight(10, 25);
    delayPerLedLighting(270);

    OnOffLedFromOneToFour(20, 10);
    delayPerLedLighting(270);
    OnOffLedFromOneToEight(10, 25);
    delayPerLedLighting(270);

    OnOffLedFromOneToFour(20, 10);
    delayPerLedLighting(270);
    OnOffLedFromOneToEight(10, 25);
    delayPerLedLighting(270);

    OnOffLedFromOneToFour(20, 10);
    delayPerLedLighting(270);
    OnOffLedFromOneToEight(10, 25);
    delayPerLedLighting(270);

    OnOffLedFromOneToFour(20, 10);
    delayPerLedLighting(270);
    OnOffLedFromOneToEight(10, 25);
    delayPerLedLighting(270);

    OnOffLedFromOneToFour(20, 10);
    delayPerLedLighting(270);
    OnOffLedFromOneToEight(10, 25);
    delayPerLedLighting(270);

    OnOffLedFromOneToFour(20, 10);
    delayPerLedLighting(270);
    OnOffLedFromOneToEight(10, 25);
    delayPerLedLighting(270);

    OnOffLedFromOneToFour(20, 10);
    delayPerLedLighting(270);
    OnOffLedFromOneToEight(10, 25);
    delayPerLedLighting(270);

    OnOffLedFromOneToFour(20, 10);
    delayPerLedLighting(270);
    OnOffLedFromOneToEight(10, 25);
    delayPerLedLighting(270);

    OnOffLedFromOneToFour(20, 10);
    delayPerLedLighting(270);
    OnOffLedFromOneToEight(10, 25);
    delayPerLedLighting(270);

    OnOffLedFromOneToFour(20, 10);
    delayPerLedLighting(270);
    OnOffLedFromOneToEight(10, 25);
    delayPerLedLighting(270);

    OnOffLedFromOneToFour(20, 10);
    delayPerLedLighting(270);
    OnOffLedFromOneToEight(10, 25);
    delayPerLedLighting(270);

    OnOffLedFromOneToFour(20, 10);
    delayPerLedLighting(270);
    OnOffLedFromOneToEight(10, 25);
    delayPerLedLighting(270);

    OnOffLedFromOneToFour(20, 10);
    delayPerLedLighting(270);
    OnOffLedFromOneToEight(10, 25);
    delayPerLedLighting(270);

    OnOffLedFromOneToFour(20, 10);
    delayPerLedLighting(270);
    OnOffLedFromOneToEight(10, 25);
    delayPerLedLighting(270);

    OnOffLedFromOneToFour(20, 10);
    delayPerLedLighting(270);
    OnOffLedFromOneToEight(10, 25);
    delayPerLedLighting(270);

    OnOffLedFromOneToFour(20, 10);
    delayPerLedLighting(270);
    OnOffLedFromOneToEight(10, 25);
    delayPerLedLighting(270);

    OnOffLedFromOneToFour(20, 10);
    delayPerLedLighting(270);
    OnOffLedFromOneToEight(10, 25);
    delayPerLedLighting(270);

    OnOffLedFromOneToFour(20, 10);
    delayPerLedLighting(270);
    OnOffLedFromOneToEight(10, 25);
    delayPerLedLighting(270);

    OnOffLedFromOneToFour(20, 10);
    delayPerLedLighting(270);
    OnOffLedFromOneToEight(10, 25);
    delayPerLedLighting(270);

    OnOffLedFromOneToFour(20, 10);
    delayPerLedLighting(270);
    OnOffLedFromOneToEight(10, 25);
    delayPerLedLighting(270);

    OnOffLedFromOneToFour(20, 10);
    delayPerLedLighting(270);
    OnOffLedFromOneToEight(10, 25);
    delayPerLedLighting(270);

    OnOffLedFromOneToFour(20, 10);
    delayPerLedLighting(270);
    OnOffLedFromOneToEight(10, 25);
    delayPerLedLighting(270);

    OnOffLedFromOneToFour(20, 10);
    delayPerLedLighting(270);
    OnOffLedFromOneToEight(10, 25);
    delayPerLedLighting(270);

    OnOffLedFromOneToFour(20, 10);
    delayPerLedLighting(270);
    OnOffLedFromOneToEight(10, 25);
    delayPerLedLighting(270);

    OnOffLedFromOneToFour(20, 10);
    delayPerLedLighting(270);
    OnOffLedFromOneToEight(10, 25);
    delayPerLedLighting(270);

    OnOffLedFromOneToFour(20, 10);
    delayPerLedLighting(270);
    OnOffLedFromOneToEight(10, 25);
    delayPerLedLighting(270);

    OnOffLedFromOneToFour(20, 10);
    delayPerLedLighting(270);
    OnOffLedFromOneToEight(10, 25);
    delayPerLedLighting(270);

    OnOffLedFromOneToFour(20, 10);
    delayPerLedLighting(270);
    OnOffLedFromOneToEight(10, 25);
    delayPerLedLighting(270);

    OnOffLedFromOneToFour(20, 10);
    delayPerLedLighting(270);
    OnOffLedFromOneToEight(10, 25);
    delayPerLedLighting(270);

    OnOffLedFromOneToFour(20, 10);
    delayPerLedLighting(270);
    OnOffLedFromOneToEight(10, 25);
    delayPerLedLighting(270);

    OnOffLedFromOneToFour(20, 10);
    delayPerLedLighting(270);
    OnOffLedFromOneToEight(10, 25);
    delayPerLedLighting(270);

    OnOffLedFromOneToFour(20, 10);
    delayPerLedLighting(270);
    OnOffLedFromOneToEight(10, 25);
    delayPerLedLighting(270);

    OnOffLedFromOneToFour(20, 10);
    delayPerLedLighting(270);
    OnOffLedFromOneToEight(10, 25);
    delayPerLedLighting(270);

    OnOffLedFromOneToFour(20, 10);
    delayPerLedLighting(270);
    OnOffLedFromOneToEight(10, 25);
    delayPerLedLighting(270);

    OnOffLedFromOneToFour(20, 10);
    delayPerLedLighting(270);
    OnOffLedFromOneToEight(10, 25);
    delayPerLedLighting(270);

    OnOffLedFromOneToFour(20, 10);
    delayPerLedLighting(270);
    OnOffLedFromOneToEight(10, 25);
    delayPerLedLighting(270);

    OnOffLedFromOneToFour(20, 10);
    delayPerLedLighting(270);
    OnOffLedFromOneToEight(10, 25);
    delayPerLedLighting(270);

    OnOffLedFromOneToFour(20, 10);
    delayPerLedLighting(270);
    OnOffLedFromOneToEight(10, 25);
    delayPerLedLighting(270);

    OnOffLedFromOneToFour(20, 10);
    delayPerLedLighting(270);
    OnOffLedFromOneToEight(10, 25);
    delayPerLedLighting(270);
  }
}

void MarriedLife()
{ // *2nd song* Married life (Up the movie) 41seconds
  OnOffLedFromOneToFive(20, 50);
  delayPerLedLighting(500);
  OnOffLedFromOneToFive(20, 50);
  delayPerLedLighting(500);
  OnOffLedFromOneToFive(20, 50);
  delayPerLedLighting(500);
  OnOffLedFromOneToFive(20, 50);
  delayPerLedLighting(500);
  OnOffLedFromOneToFive(20, 50);
  delayPerLedLighting(500);
  OnOffLedFromOneToFive(20, 50);
  delayPerLedLighting(500);
  OnOffLedFromOneToFive(20, 50);
  delayPerLedLighting(500);
  OnOffLedFromOneToFive(20, 50);
  delayPerLedLighting(500);
  OnOffLedFromOneToFive(20, 50);
  delayPerLedLighting(500);
  OnOffLedFromOneToFive(20, 50);
  delayPerLedLighting(1155);

  OnOffLedFromOneToThree(20, 30);
  delayPerLedLighting(300);
  OnOffLedFromOneToThree(20, 30);
  delayPerLedLighting(300);
  OnOffLedFromOneToThree(20, 30);
  delayPerLedLighting(330);
  OnOffLedFromOneToSeven(20, 500);
  delayPerLedLighting(50);
  OnOffLedFromOneToThree(20, 30);
  delayPerLedLighting(300); // 5
  OnOffLedFromOneToThree(20, 30);
  delayPerLedLighting(300);
  OnOffLedFromOneToThree(20, 30);
  delayPerLedLighting(300);
  OnOffLedFromOneToSeven(20, 150);
  OnOffLedFromOneToThree(20, 30);
  delayPerLedLighting(250); // 8
  OnOffLedFromOneToFive(20, 30);
  delayPerLedLighting(300);
  OnOffLedFromOneToFive(20, 30);
  delayPerLedLighting(300);
  //
  OnOffLedFromOneToSeven(20, 250);
  OnOffLedFromOneToThree(20, 30);
  delayPerLedLighting(250);
  OnOffLedFromOneToFive(20, 30);
  delayPerLedLighting(500);
  OnOffLedFromOneToFive(20, 50);
  delayPerLedLighting(900);
  OnOffLedFromOneToThree(20, 30);
  delayPerLedLighting(250);
  OnOffLedFromOneToFive(20, 30);
  delayPerLedLighting(500);
  OnOffLedFromOneToFive(20, 50);
  delayPerLedLighting(500);
  OnOffLedFromOneToFive(20, 50);
  delayPerLedLighting(500);
  OnOffLedFromOneToEight(20, 350);
  delayPerLedLighting(100);
  OnOffLedFromOneToFive(20, 50);
  delayPerLedLighting(400);
  delayPerLedLighting(350);
  //////////////////  32 seconds
  OnOffLedFromOneToThree(20, 30);
  delayPerLedLighting(300);
  OnOffLedFromOneToThree(20, 30);
  delayPerLedLighting(300);
  OnOffLedFromOneToThree(20, 30);
  delayPerLedLighting(330);
  OnOffLedFromOneToSeven(20, 500);
  delayPerLedLighting(100);
  //////////////// 36 seconds
  OnOffLedFromOneToThree(20, 30);
  delayPerLedLighting(250);
  OnOffLedFromOneToFive(20, 30);
  delayPerLedLighting(300);
  OnOffLedFromOneToFive(20, 30);
  delayPerLedLighting(200);
  OnOffLedFromOneToSeven(20, 100);
}


void allGirlsAreTheSame() // All girls are the same by juice wrld
{   
  delayPerLedLighting(9750);
  tone(pinOne, pinFive,150,50);
  delayPerLedLighting(250);
  tone(pinOne, pinFive,20,20);
  delayPerLedLighting(150);
  tone(pinThree, pinSeven,300,150);
  delayPerLedLighting(150);
  tone(pinOne, pinFive,300,150);
  delayPerLedLighting(700);
  tone(pinThree, pinSeven,300,150);
  delayPerLedLighting(600);
  tone(pinOne, pinFive,150,50);
  delayPerLedLighting(600);
  tone(pinThree, pinSeven,300,150);
  delayPerLedLighting(250);
  tone(pinOne, pinFive,150,50);
//
  delayPerLedLighting(450);
  tone(pinOne, pinFive,20,20);
  delayPerLedLighting(250);
  tone(pinThree, pinEight,300,150);
  delayPerLedLighting(300);
  tone(pinTwo, pinFive,300,150);
  delayPerLedLighting(400);
  tone(pinThree, pinEight,300,150);
  delayPerLedLighting(150);
  tone(pinOne, pinFive,300,150);
  delayPerLedLighting(700);
  tone(pinThree, pinSeven,300,150);
  delayPerLedLighting(500);
  tone(pinOne, pinFive,300,150);
  delayPerLedLighting(700);
  tone(pinThree, pinSeven,300,150);
  //21s
  delayPerLedLighting(500);
  tone(pinTwo, pinFive,300,150);
   delayPerLedLighting(600);
  tone(pinOne, pinFive,150,50);
  delayPerLedLighting(600);
  tone(pinThree, pinSeven,300,150);
  delayPerLedLighting(250);
  tone(pinOne, pinFive,150,50);
  delayPerLedLighting(450);
  tone(pinOne, pinFive,20,20);
  delayPerLedLighting(250);
  tone(pinThree, pinEight,300,150);
  delayPerLedLighting(300);
  tone(pinTwo, pinFive,300,150);
  delayPerLedLighting(400);
  tone(pinThree, pinEight,300,150);
  delayPerLedLighting(150);
  tone(pinOne, pinFive,300,150);
  delayPerLedLighting(700);
  tone(pinThree, pinSeven,300,150);
  delayPerLedLighting(500);
  tone(pinOne, pinFive,300,150);
  delayPerLedLighting(700);
  tone(pinThree, pinSeven,300,150);
   delayPerLedLighting(600);
  tone(pinOne, pinFive,150,50);
  delayPerLedLighting(600);
  tone(pinThree, pinSeven,300,150);
  delayPerLedLighting(250);
  tone(pinOne, pinFive,150,50);
  delayPerLedLighting(450);
  tone(pinOne, pinFive,20,20);
  delayPerLedLighting(250);
  tone(pinThree, pinEight,300,150);
  delayPerLedLighting(300);
  tone(pinTwo, pinFive,300,150);
  delayPerLedLighting(400);
  tone(pinThree, pinEight,300,150);
  delayPerLedLighting(150);
  tone(pinOne, pinFive,300,150);
  delayPerLedLighting(700);
  tone(pinThree, pinSeven,300,150);
  delayPerLedLighting(500);
  tone(pinOne, pinFive,300,150);
  delayPerLedLighting(700);
  tone(pinThree, pinSeven,300,150);
   delayPerLedLighting(600);
  tone(pinOne, pinFive,150,50);
  delayPerLedLighting(600);
  tone(pinThree, pinSeven,300,150);
  delayPerLedLighting(250);
  tone(pinOne, pinFive,150,50);
  delayPerLedLighting(450);
  tone(pinOne, pinFive,20,20);
  delayPerLedLighting(250);
  tone(pinThree, pinEight,300,150);
  delayPerLedLighting(300);
  tone(pinTwo, pinFive,300,150);
  delayPerLedLighting(400);
  tone(pinThree, pinEight,300,150);
  delayPerLedLighting(150);
  tone(pinOne, pinFive,300,150);
  delayPerLedLighting(700);
  tone(pinThree, pinSeven,300,150);
  delayPerLedLighting(500);
  tone(pinOne, pinFive,300,150);
  delayPerLedLighting(700);
  tone(pinThree, pinSeven,300,150);
  delayPerLedLighting(600);
  tone(pinOne, pinFive,150,50);
  delayPerLedLighting(600);
  tone(pinThree, pinSeven,300,150);
  delayPerLedLighting(250);
  tone(pinOne, pinFive,150,50);
  delayPerLedLighting(450);
  tone(pinOne, pinFive,20,20);
  delayPerLedLighting(250);
  tone(pinThree, pinEight,300,150);
  delayPerLedLighting(300);
  tone(pinTwo, pinFive,300,150);
  delayPerLedLighting(400);
  tone(pinThree, pinEight,300,150);
  delayPerLedLighting(150);
  tone(pinOne, pinFive,300,150);
  delayPerLedLighting(700);
  tone(pinThree, pinSeven,300,150);
  delayPerLedLighting(500);
  tone(pinOne, pinFive,300,150);
  delayPerLedLighting(700);
  tone(pinThree, pinSeven,300,150);
 delayPerLedLighting(600);
  tone(pinOne, pinFive,150,50);
  delayPerLedLighting(600);
  tone(pinThree, pinSeven,300,150);
  delayPerLedLighting(250);
  tone(pinOne, pinFive,150,50);
  delayPerLedLighting(450);
  tone(pinOne, pinFive,20,20);
  delayPerLedLighting(250);
  tone(pinThree, pinEight,300,150);
  delayPerLedLighting(300);
  tone(pinTwo, pinFive,300,150);
  delayPerLedLighting(400);
  tone(pinThree, pinEight,300,150);
  delayPerLedLighting(150);
  tone(pinOne, pinFive,300,150);
  delayPerLedLighting(700);
  tone(pinThree, pinSeven,300,150);
  delayPerLedLighting(500);
  tone(pinOne, pinFive,300,150);
   

  delayPerLedLighting(11750);
  tone(pinOne, pinFive,150,50);
  delayPerLedLighting(250);
  tone(pinOne, pinFive,20,20);
  delayPerLedLighting(150);
  tone(pinThree, pinSeven,300,150);
  delayPerLedLighting(150);
  tone(pinOne, pinFive,300,150);
  delayPerLedLighting(700);
  tone(pinThree, pinSeven,300,150);
  delayPerLedLighting(600);
  tone(pinOne, pinFive,150,50);
  delayPerLedLighting(600);
  tone(pinThree, pinSeven,300,150);
  delayPerLedLighting(250);
  tone(pinOne, pinFive,150,50);

  delayPerLedLighting(450);
  tone(pinOne, pinFive,20,20);
  delayPerLedLighting(250);
  tone(pinThree, pinEight,300,150);
  delayPerLedLighting(300);
  tone(pinTwo, pinFive,300,150);
  delayPerLedLighting(400);
  tone(pinThree, pinEight,300,150);
  delayPerLedLighting(150);
  tone(pinOne, pinFive,300,150);
  delayPerLedLighting(700);
  tone(pinThree, pinSeven,300,150);
  delayPerLedLighting(500);
  tone(pinOne, pinFive,300,150);
  delayPerLedLighting(700);
  tone(pinThree, pinSeven,300,150);

  delayPerLedLighting(500);
  tone(pinTwo, pinFive,300,150);
   delayPerLedLighting(600);
  tone(pinOne, pinFive,150,50);
  delayPerLedLighting(600);
  tone(pinThree, pinSeven,300,150);
  delayPerLedLighting(250);
  tone(pinOne, pinFive,150,50);
  delayPerLedLighting(450);
  tone(pinOne, pinFive,20,20);
  delayPerLedLighting(250);
  tone(pinThree, pinEight,300,150);
  delayPerLedLighting(300);
  tone(pinTwo, pinFive,300,150);
  delayPerLedLighting(400);
  tone(pinThree, pinEight,300,150);
  delayPerLedLighting(150);
  tone(pinOne, pinFive,300,150);
  delayPerLedLighting(700);
  tone(pinThree, pinSeven,300,150);
  delayPerLedLighting(500);
  tone(pinOne, pinFive,300,150);
  delayPerLedLighting(700);
  tone(pinThree, pinSeven,300,150);
   delayPerLedLighting(600);
  tone(pinOne, pinFive,150,50);
  delayPerLedLighting(600);
  tone(pinThree, pinSeven,300,150);
  delayPerLedLighting(250);
  tone(pinOne, pinFive,150,50);
  delayPerLedLighting(450);
  tone(pinOne, pinFive,20,20);
  delayPerLedLighting(250);
  tone(pinThree, pinEight,300,150);
  delayPerLedLighting(300);
  tone(pinTwo, pinFive,300,150);
  delayPerLedLighting(400);
  tone(pinThree, pinEight,300,150);
  delayPerLedLighting(150);
  tone(pinOne, pinFive,300,150);
  delayPerLedLighting(700);
  tone(pinThree, pinSeven,300,150);
  delayPerLedLighting(500);
  tone(pinOne, pinFive,300,150);
  delayPerLedLighting(700);
  tone(pinThree, pinSeven,300,150);
   delayPerLedLighting(600);
  tone(pinOne, pinFive,150,50);
  delayPerLedLighting(600);
  tone(pinThree, pinSeven,300,150);
  delayPerLedLighting(250);
  tone(pinOne, pinFive,150,50);
  delayPerLedLighting(450);
  tone(pinOne, pinFive,20,20);
  delayPerLedLighting(250);
  tone(pinThree, pinEight,300,150);
  delayPerLedLighting(300);
  tone(pinTwo, pinFive,300,150);
  delayPerLedLighting(400);
  tone(pinThree, pinEight,300,150);
  delayPerLedLighting(150);
  tone(pinOne, pinFive,300,150);
  delayPerLedLighting(700);
  tone(pinThree, pinSeven,300,150);
  delayPerLedLighting(500);
  tone(pinOne, pinFive,300,150);
  delayPerLedLighting(700);
  tone(pinThree, pinSeven,300,150);
   delayPerLedLighting(600);
  tone(pinOne, pinFive,150,50);
  delayPerLedLighting(600);
  tone(pinThree, pinSeven,300,150);
  delayPerLedLighting(250);
  tone(pinOne, pinFive,150,50);
  delayPerLedLighting(450);
  tone(pinOne, pinFive,20,20);
  delayPerLedLighting(250);
  tone(pinThree, pinEight,300,150);
  delayPerLedLighting(300);
  tone(pinTwo, pinFive,300,150);
  delayPerLedLighting(400);
  tone(pinThree, pinEight,300,150);
  delayPerLedLighting(150);
  tone(pinOne, pinFive,300,150);
  delayPerLedLighting(700);
  tone(pinThree, pinSeven,300,150);
  delayPerLedLighting(500);
  tone(pinOne, pinFive,300,150);
  delayPerLedLighting(700);
  tone(pinThree, pinSeven,300,150);
 delayPerLedLighting(600);
  tone(pinOne, pinFive,150,50);
  delayPerLedLighting(600);
  tone(pinThree, pinSeven,300,150);
  delayPerLedLighting(250);
  tone(pinOne, pinFive,150,50);
  delayPerLedLighting(450);
  tone(pinOne, pinFive,20,20);
  delayPerLedLighting(250);
  tone(pinThree, pinEight,300,150);
  delayPerLedLighting(300);
  tone(pinTwo, pinFive,300,150);
  delayPerLedLighting(400);
  tone(pinThree, pinEight,300,150);
  delayPerLedLighting(150);
  tone(pinOne, pinFive,300,150);
  delayPerLedLighting(700);
  tone(pinThree, pinSeven,300,150);
  delayPerLedLighting(500);
  tone(pinOne, pinFive,300,150);
   
  
  //
  
 
  
  
  
   
  
 
}