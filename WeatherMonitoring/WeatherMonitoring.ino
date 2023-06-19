#include <LiquidCrystal_I2C.h>
#include <SimpleDHT.h>



int hSensor = A0; // humidity sensor pin
SimpleDHT11 dht11(hSensor);
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2);


byte temperature = 0;
byte humidity = 0;
int data;

void setup() {
Serial.begin(9600);
  
int read = dht11.read(&temperature, &humidity,NULL);

  lcd.init();
  lcd.backlight();
  pinMode(hSensor, INPUT);  
  lcd.print("Temperature:");
  lcd.print((int)temperature); lcd.print("*C, "); 
  lcd.setCursor(0, 1);
  lcd.print("Humidity: ");
  lcd.print((int)humidity);

}

void loop() {

  int read = dht11.read(&temperature, &humidity,NULL);

 Serial.println("Temperature:");
    Serial.println((int)temperature); Serial.print("*C, ");

 if(read != data){
    lcd.clear();   
    lcd.print("Temperature:");
    lcd.print((int)temperature); lcd.print("*C, ");
    lcd.setCursor(0, 1);
    lcd.print("Humidity: ");
    lcd.print((int)humidity);

 }
  data = read; 
}





