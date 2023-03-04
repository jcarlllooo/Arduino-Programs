const int pin1 = 1; // LED pin 
const int pin2 = 2; // LED pin 
const int pin3 = 3; // LED pin 
const int pin4 = 4; // LED pin 
const int pin5 = 5; // LED pin 
const int pin6 = 6; // LED pin 
const int pin7 = A0; // LED pin 
const int pin8 = A1; // LED pin 
const int button1 = A5; //button pin
const int button2 = A4; //button pin
const int button3 = A3; //button pin
const int button4 = A2; //button pin
const int a = 7; // 7 segment display pin 
const int b = 8; // 7 segment display pin 
const int c = 9; // 7 segment display pin 
const int d = 10; // 7 segment display pin 
const int e = 11; // 7 segment display pin 
const int f = 12; // 7 segment display pin 
const int g = 13; // 7 segment display pin 

int Bit1 = 0; // setting bit1 to 0 for calculation purpose 
int Bit2 = 0; // setting bit2 to 0 for calculation purpose 
int Bit3 = 0; // setting bit3 to 0 for calculation purpose 
int Bit4 = 0; // setting bit4 to 0 for calculation purpose 

int binaryBit; // declaring binaryBit 
int Total;  // declaring Total for storing value


void setup()
{
    pinMode(button1, INPUT); // setting pinMode of buttons as input
    pinMode(button2, INPUT); // setting pinMode of buttons as input
    pinMode(button3, INPUT); // setting pinMode of buttons as input
    pinMode(button4, INPUT); // setting pinMode of buttons as input
    pinMode(a, OUTPUT); // Setting 7 segment a as an output
    pinMode(b, OUTPUT);// Setting 7 segment b as an output
    pinMode(c, OUTPUT);// Setting 7 segment c as an output
    pinMode(d, OUTPUT);// Setting 7 segment d as an output
    pinMode(e, OUTPUT);// Setting 7 segment e as an output
    pinMode(f, OUTPUT);// Setting 7 segment f as an output
    pinMode(g, OUTPUT);// Setting 7 segment g as an output
    pinMode(pin1, OUTPUT); //Setting LED 1 pin as an output
    pinMode(pin2, OUTPUT); //Setting LED 2 pin as an output
    pinMode(pin3, OUTPUT); //Setting LED 3 pin as an output
    pinMode(pin4, OUTPUT); //Setting LED 4 pin as an output
    pinMode(pin5, OUTPUT); //Setting LED 5 pin as an output
    pinMode(pin6, OUTPUT); //Setting LED 6 pin as an output
    pinMode(pin7, OUTPUT); //Setting LED 7 pin as an output
    pinMode(pin8, OUTPUT); //Setting LED 8 pin as an output

}

void loop()
{

    int Bit1 = digitalRead(button1); // reading button state
    int Bit2 = digitalRead(button2); // reading button state
    int Bit3 = digitalRead(button3); // reading button state
    int Bit4 = digitalRead(button4); // reading button state

    
    binaryBit=(Bit4*8)+(Bit3*4)+(Bit2*2)+(Bit1*1); // Bit calculation 
    byte Total=binaryBit; //  this is where you store the value
    delay(500);

    if(Total == 1){ //creating "if" function for value stored in "Total"
      digitalWrite(pin1,HIGH);
      number1();
      digitalWrite(pin1,LOW);
    }
    if(Total == 2){//creating "if" function for value stored in "Total"
      digitalWrite(pin2,HIGH);
      number2();
      digitalWrite(pin2,LOW);
    }
    if(Total == 3){//creating "if" function for value stored in "Total"
      digitalWrite(pin2,HIGH);digitalWrite(pin1,HIGH);
      number3();
      digitalWrite(pin2,LOW);digitalWrite(pin1,LOW);
    }
    if(Total == 4){//creating "if" function for value stored in "Total"
      digitalWrite(pin3,HIGH);
      number4();
      digitalWrite(pin3,LOW);
    }
    if(Total == 5){//creating "if" function for value stored in "Total"
      digitalWrite(pin3,HIGH);digitalWrite(pin1,HIGH);
      number5();
      digitalWrite(pin3,LOW);digitalWrite(pin1,LOW);
    }
    if(Total == 6){//creating "if" function for value stored in "Total"
      digitalWrite(pin3,HIGH);digitalWrite(pin2,HIGH);
      number6();
      digitalWrite(pin3,LOW);digitalWrite(pin2,LOW);
    }
    if(Total == 7){//creating "if" function for value stored in "Total"
      digitalWrite(pin3,HIGH);digitalWrite(pin2,HIGH);digitalWrite(pin1,HIGH);
      number7();
      digitalWrite(pin3,LOW);digitalWrite(pin2,LOW);digitalWrite(pin1,LOW);
    }
    if(Total == 8){//creating "if" function for value stored in "Total"
      digitalWrite(pin4,HIGH);
      number8();
      digitalWrite(pin4,LOW);
    }
    if(Total == 9){//creating "if" function for value stored in "Total"
      digitalWrite(pin4,HIGH);digitalWrite(pin1,HIGH);
      number9();
      digitalWrite(pin4,LOW);digitalWrite(pin1,LOW);
    }
    if(Total >= 9){/* creating an "If" function where if the value detected is greater than 9, display number0.... 
    note that if this is set as an "else" function, the 7 segment will just continue to blink if the data stored is equal 0  */
      number0();
    }

}

/* this is the 7 seven segment pin configuration for displaying the output value*/
void number0(){ // in this function number0, is set to blink the 7 segment display and display nothing on the LEDs
digitalWrite(a, HIGH);digitalWrite(b, HIGH);digitalWrite(c, HIGH);digitalWrite(d, HIGH);digitalWrite(e, HIGH);digitalWrite(f, HIGH);
delayPerLedLighting(50);
digitalWrite(a, LOW);digitalWrite(b, LOW);digitalWrite(c, LOW);digitalWrite(d, LOW);digitalWrite(e, LOW);digitalWrite(f, LOW);
delayPerLedLighting(50);
digitalWrite(a, HIGH);digitalWrite(b, HIGH);digitalWrite(c, HIGH);digitalWrite(d, HIGH);digitalWrite(e, HIGH);digitalWrite(f, HIGH);
delayPerLedLighting(50);
digitalWrite(a, LOW);digitalWrite(b, LOW);digitalWrite(c, LOW);digitalWrite(d, LOW);digitalWrite(e, LOW);digitalWrite(f, LOW);
delayPerLedLighting(50);
digitalWrite(a, HIGH);digitalWrite(b, HIGH);digitalWrite(c, HIGH);digitalWrite(d, HIGH);digitalWrite(e, HIGH);digitalWrite(f, HIGH);
delayPerLedLighting(50);
digitalWrite(a, LOW);digitalWrite(b, LOW);digitalWrite(c, LOW);digitalWrite(d, LOW);digitalWrite(e, LOW);digitalWrite(f, LOW);
}
void number1(){
digitalWrite(b, HIGH);digitalWrite(c, HIGH);// Setting bcd to decimal
conversion(-5, -5, -5, pin8, HIGH);  // setting data conversion binary to 2421 and led state, through "conversion function"..... note that "-5" is an impedence and this is set in the function to display nothing 
delayPerLedLighting(5000);
conversion(-5, -5, -5, pin8, LOW);  // setting data conversion binary to 2421 and led state, through "conversion function"..... note that "-5" is an impedence and this is set in the function to display nothing 
}
void number2(){
digitalWrite(a, HIGH);digitalWrite(b, HIGH);digitalWrite(g, HIGH);digitalWrite(e, HIGH);digitalWrite(d, HIGH);// Setting bcd to decimal
conversion(-5, -5, pin7, -5, HIGH);  // setting data conversion binary to 2421 and led state, through "conversion function"..... note that "-5" is an impedence and this is set in the function to display nothing 
delayPerLedLighting(5000);
conversion(-5, -5, pin7, -5, LOW);  // setting data conversion binary to 2421 and led state, through "conversion function"..... note that "-5" is an impedence and this is set in the function to display nothing 
}
void number3(){
digitalWrite(a, HIGH);digitalWrite(b, HIGH);digitalWrite(c, HIGH);digitalWrite(d, HIGH);digitalWrite(g, HIGH);// Setting bcd to decimal
conversion(-5, -5, pin7, pin8, HIGH);  // setting data conversion binary to 2421 and led state, through "conversion function"..... note that "-5" is an impedence and this is set in the function to display nothing 
delayPerLedLighting(5000);
conversion(-5, -5, pin7, pin8, LOW);  // setting data conversion binary to 2421 and led state, through "conversion function"..... note that "-5" is an impedence and this is set in the function to display nothing 
}
void number4(){
digitalWrite(b, HIGH);digitalWrite(c, HIGH);digitalWrite(g, HIGH);digitalWrite(f, HIGH);// Setting bcd to decimal
conversion(-5, pin6, -5, -5, HIGH);  // setting data conversion binary to 2421 and led state, through "conversion function"..... note that "-5" is an impedence and this is set in the function to display nothing 
delayPerLedLighting(5000);
conversion(-5, pin6, -5, -5, LOW);  // setting data conversion binary to 2421 and led state, through "conversion function"..... note that "-5" is an impedence and this is set in the function to display nothing 
}
void number5(){
digitalWrite(a, HIGH);digitalWrite(f, HIGH);digitalWrite(g, HIGH);digitalWrite(c, HIGH);digitalWrite(d, HIGH);// Setting bcd to decimal
conversion(pin5, -5, pin7, pin8, HIGH);  // setting data conversion binary to 2421 and led state, through "conversion function"..... note that "-5" is an impedence and this is set in the function to display nothing 
delayPerLedLighting(5000);
conversion(pin5, -5, pin7, pin8, LOW);  // setting data conversion binary to 2421 and led state, through "conversion function"..... note that "-5" is an impedence and this is set in the function to display nothing 
} 
void number6(){
digitalWrite(a, HIGH);digitalWrite(c, HIGH);digitalWrite(d, HIGH);digitalWrite(e, HIGH);digitalWrite(f, HIGH);digitalWrite(g, HIGH);// Setting bcd to decimal
conversion(pin5, pin6, -5, -5, HIGH);  // setting data conversion binary to 2421 and led state, through "conversion function"..... note that "-5" is an impedence and this is set in the function to display nothing 
delayPerLedLighting(5000);
conversion(pin5, pin6, -5, -5, LOW);  // setting data conversion binary to 2421 and led state, through "conversion function"..... note that "-5" is an impedence and this is set in the function to display nothing 
}
void number7(){
digitalWrite(a, HIGH);digitalWrite(b, HIGH);digitalWrite(c, HIGH);// Setting bcd to decimal
conversion(pin5, pin6, -5, pin8, HIGH);  // setting data conversion binary to 2421 and led state, through "conversion function"..... note that "-5" is an impedence and this is set in the function to display nothing 
delayPerLedLighting(5000);
conversion(pin5, pin6, -5, pin8, LOW);  // setting data conversion binary to 2421 and led state, through "conversion function"..... note that "-5" is an impedence and this is set in the function to display nothing  
}
void number8(){
digitalWrite(a, HIGH);digitalWrite(b, HIGH);digitalWrite(c, HIGH);digitalWrite(d, HIGH);digitalWrite(e, HIGH);digitalWrite(f, HIGH);digitalWrite(g, HIGH);// Setting bcd to decimal
conversion(pin5, pin6, pin7, -5, HIGH);  // setting data conversion binary to 2421 and led state, through "conversion function"..... note that "-5" is an impedence and this is set in the function to display nothing 
delayPerLedLighting(5000);
conversion(pin5, pin6, pin7, -5, LOW);  // setting data conversion binary to 2421 and led state, through "conversion function"..... note that "-5" is an impedence and this is set in the function to display nothing 
}
void number9(){
digitalWrite(a, HIGH);digitalWrite(b, HIGH);digitalWrite(c, HIGH);digitalWrite(d, HIGH);digitalWrite(f, HIGH);digitalWrite(g, HIGH);// Setting bcd to decimal
conversion(pin5, pin6, pin7, pin8, HIGH);  // setting data conversion binary to 2421 and led state, through "conversion function"..... note that "-5" is an impedence and this is set in the function to display nothing 
delayPerLedLighting(5000);
conversion(pin5, pin6, pin7, pin8, LOW);  // setting data conversion binary to 2421 and led state, through "conversion function"..... note that "-5" is an impedence and this is set in the function to display nothing 
}


void delayPerLedLighting(int Delay)
{ // creating delay parameters with setting off all 7 segment display for code lessening 
 
  delay(Delay);
  
    digitalWrite(a, LOW);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW);
    digitalWrite(d, LOW);
    digitalWrite(e, LOW);
    digitalWrite(f, LOW);
    digitalWrite(g, LOW);
    return;
}
void conversion(int LED1, int LED2, int LED3, int LED4, int State){ // creating Led pin and state function for data conversion 
  digitalWrite(LED1, State);
  digitalWrite(LED2, State);
  digitalWrite(LED3, State);
  digitalWrite(LED4, State);
}

 // setting data conversion binary to 2421 and led state, through "conversion function"..... note that "-5" is an impedence and this is set in the function to display nothing 
