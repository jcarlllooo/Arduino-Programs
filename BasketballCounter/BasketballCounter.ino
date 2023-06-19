const int button1 = A0; //button pin
const int button2 = A1; //button pin
const int button3 = A2; 
const int button4 = A3; 
const int button5 = A4; 

const int DP = 13; // 7 segment display pin 
const int D1 = 2; // 7 segment display pin 
const int D2 = 3; // 7 segment display pin 
const int D3 = 4; // 7 segment display pin 
const int D4 = 5; // 7 segment display pin 
const int a = 6; // 7 segment display pin 
const int b = 7; // 7 segment display pin 
const int c = 8; // 7 segment display pin 
const int d = 9; // 7 segment display pin 
const int e = 10; // 7 segment display pin 
const int f = 11; // 7 segment display pin 
const int g = 12; // 7 segment display pin 

int TeamAD1 = 0;
int TeamAD2 = 0;
int TeamBD1 = 0;
int TeamBD2 = 0;
int lastButtonState = 1;

void setup() {
    pinMode(button1, INPUT); // setting pinMode of buttons as input
    pinMode(button2, INPUT); // setting pinMode of buttons as input
    pinMode(a, OUTPUT); // Setting 7 segment a as an output
    pinMode(b, OUTPUT);// Setting 7 segment b as an output
    pinMode(c, OUTPUT);// Setting 7 segment c as an output
    pinMode(d, OUTPUT);// Setting 7 segment d as an output
    pinMode(e, OUTPUT);// Setting 7 segment e as an output
    pinMode(f, OUTPUT);// Setting 7 segment f as an output
    pinMode(g, OUTPUT);// Setting 7 segment g as an output
    pinMode(D1, OUTPUT);// Setting 7 segment d as an output
    pinMode(D2, OUTPUT);// Setting 7 segment e as an output
    pinMode(D3, OUTPUT);// Setting 7 segment f as an output
    pinMode(D4, OUTPUT);// Setting 7 segment g as an output
    pinMode(DP, OUTPUT);// Setting 7 segment g as an output
    digitalWrite(D1, HIGH);
    digitalWrite(D2, HIGH);
    digitalWrite(D3, HIGH);
    digitalWrite(D4, HIGH);


}
 

void loop() {
  int switchState1 = digitalRead(button1);
  int switchState2 = digitalRead(button2);
  int switchState3 = digitalRead(button3);
  int switchState4 = digitalRead(button4);
  int switchState5 = digitalRead(button5);


  getDigit(1);
  getNumber(HIGH, TeamAD1);
  delay(1);
  allLedOff();
  
  getDigit(2);
  getNumber(HIGH, TeamAD2);
  delay(1);
  allLedOff();
  
  getDigit(3);
  getNumber(HIGH, TeamBD1);
  delay(1);
  allLedOff();

  getDigit(4);
  getNumber(HIGH, TeamBD2);
  delay(1);
  allLedOff();


if(switchState3 == HIGH){
    lastButtonState = !lastButtonState;
    delay(500);
}


if(lastButtonState == HIGH){
  if( switchState1 == HIGH){
    TeamBD1 = TeamBD1 + 1;

    if (TeamBD1 > 9){
      TeamBD2++;
      TeamBD1 = 0;
      if(TeamBD2 > 9){
      TeamBD1 = 0;
      TeamBD2 = 0;    
      }  
    }
    delay(500);
  }
  if( switchState2 == HIGH){
    TeamBD1 = TeamBD1 + 2;
    if (TeamBD1 > 9){
      TeamBD2++;
      TeamBD1 = 0;
      if(TeamBD2 > 9){
      TeamBD1 = 0;
      TeamBD2 = 0;    
      }  
    }
    delay(500);
  }

  if( switchState4 == HIGH){
    TeamAD1 = TeamAD1 + 1;
    if (TeamAD1 > 9){
      TeamAD2++;
      TeamAD1 = 0;
      if(TeamAD2 > 9){
      TeamAD1 = 0;
      TeamAD2 = 0;    
      }  
    }
    delay(500);
  }
 if( switchState5 == HIGH){
    TeamAD1 = TeamAD1 + 2;
    if (TeamAD1 > 9){
      TeamAD2++;
      TeamAD1 = 0;
      if(TeamAD2 > 9){
      TeamAD1 = 0;
      TeamAD2 = 0;    
      }  
    }
    delay(500);
  }
}
else{
  if( switchState1 == HIGH){
    TeamBD1 = TeamBD1 - 1;

    if (TeamBD1 < 0){
      TeamBD2--;
      TeamBD1 = 9;
    }
    delay(500);
  }


  if( switchState4 == HIGH){
    TeamAD1 = TeamAD1 - 1;
    if (TeamAD1 < 0){
      TeamAD2--;
      TeamAD1 = 9;
    }
    delay(500);
  }
 
}





}


/*
  if(switchState3 == HIGH && switchState5 == HIGH){
    TeamAD1--;
    if (TeamAD1 < 0){
      TeamAD2--;
      TeamAD1 = 9;
       
    }
    */



void getDigit(int digit)
{
  switch (digit){
    case 1:
    digitalWrite(D1, LOW); 
    digitalWrite(D2, HIGH); 
    digitalWrite(D3, HIGH); 
    digitalWrite(D4, HIGH);
    digitalWrite(DP, LOW);  
    break;

    case 2:
    digitalWrite(D1, HIGH); 
    digitalWrite(D2, LOW); 
    digitalWrite(D3, HIGH); 
    digitalWrite(D4, HIGH);
    digitalWrite(DP, LOW);   
    break;

    case 3:
    digitalWrite(D1, HIGH); 
    digitalWrite(D2, HIGH); 
    digitalWrite(D3, LOW); 
    digitalWrite(D4, HIGH); 
    digitalWrite(DP, HIGH);  
    break;

    case 4:
    digitalWrite(D1, HIGH); 
    digitalWrite(D2, HIGH); 
    digitalWrite(D3, HIGH); 
    digitalWrite(D4, LOW); 
    digitalWrite(DP, LOW);  
    break;
  }
}



void getNumber(int x, byte number){
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

    case 10: 
    number0(x);
    break;

    case 11: 
    number1(x);
    break;

    case 12: 
    number2(x);
    break; 
    
    case 13: 
    number3(x);
    break;

    case 14: 
    number4(x);
    break;
  }
}


void number0(int state){ 
digitalWrite(a, state);digitalWrite(b, state);digitalWrite(c, state);digitalWrite(d, state);digitalWrite(e, state);digitalWrite(f, state);
}
void number1(int state){
digitalWrite(b, state);digitalWrite(c, state);
}
void number2(int state){
digitalWrite(a, state);digitalWrite(b, state);digitalWrite(g, state);digitalWrite(e, state);digitalWrite(d, state);
}
void number3(int state){
digitalWrite(a, state);digitalWrite(b, state);digitalWrite(c, state);digitalWrite(d, state);digitalWrite(g, state);
}
void number4(int state){
digitalWrite(b, state);digitalWrite(c, state);digitalWrite(g, state);digitalWrite(f, state);
}
void number5(int state){
digitalWrite(a, state);digitalWrite(f, state);digitalWrite(g, state);digitalWrite(c, state);digitalWrite(d,state);
} 
void number6(int state){
digitalWrite(a, state);digitalWrite(c, state);digitalWrite(d, state);digitalWrite(e, state);digitalWrite(f,state);digitalWrite(g, state);
}
void number7(int state){
digitalWrite(a, state);digitalWrite(b, state);digitalWrite(c, state);
}
void number8(int state){
digitalWrite(a, state);digitalWrite(b,state);digitalWrite(c, state);digitalWrite(d, state);digitalWrite(e, state);digitalWrite(f, state);digitalWrite(g, state);
}
void number9(int state){
digitalWrite(a, state);digitalWrite(b,state);digitalWrite(c, state);digitalWrite(d, state);digitalWrite(f, state);digitalWrite(g, state);
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
  digitalWrite(DP, LOW);
}
