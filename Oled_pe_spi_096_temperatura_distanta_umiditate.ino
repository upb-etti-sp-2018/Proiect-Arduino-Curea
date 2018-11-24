#include <SPI.h>
#include <Wire.h>
#include <SimpleDHT.h>//senzor de umiditate si distanta
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>//biblioteca display-ului

#define OLED_MOSI  9   
#define OLED_CLK   10   
#define OLED_DC    12
#define OLED_CS    11
#define OLED_RESET 13
int pinsenz = 4;
SimpleDHT11 senz;
const int trigger = 2;
const int ecou = 3;
long durata;
int distanta;
int x=10000,y=10000;
int i=0;

Adafruit_SSD1306 display(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);

void setup()   {                
//  Serial.begin(9600);
  pinMode(trigger, OUTPUT);
  pinMode(ecou, INPUT);
  display.begin(SSD1306_SWITCHCAPVCC);
  display.display();
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
}

void loop()
{
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
  durata = pulseIn(ecou, HIGH);
  distanta= durata*0.034/2;

  if(i==150)
    i=0;
  
  byte temperatura = 0;
  byte umiditate = 0;
  
  display.clearDisplay();
  display.setCursor(0,0);
  display.print("Dist. este: ");
  display.print(distanta);
  display.println(" cm");
  
  if(i==0)
    { 
     
     senz.read(pinsenz, &temperatura, &umiditate, NULL);
     x = (int)temperatura;
     y = (int)umiditate;
     
    }
    
   if(x != 10000 && y != 10000){
    
  display.print("Temperatura: ");
  display.print(x);
  display.println(" ^C");
  
  display.print("Umiditate: ");
  display.print(y);
  display.println(" %");
  
}

  display.display();
  i++;
  delay(10);

}

