#include <Wire.h>
#include <LiquidCrystal.h>
#define level0 A0
#define level1 A1
#define level2 A2
#define level3 A3
#define level4 A4
#define level5 A5
#define motor 8
#define buzz 9
#define red 6
#define green 7
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int value = 0;

void setup()
{

  lcd.begin(16, 2);
  lcd.print("Water Pump");
  pinMode(level0, INPUT_PULLUP);
  pinMode(level1, INPUT_PULLUP);
  pinMode(level2, INPUT_PULLUP);
  pinMode(level3, INPUT_PULLUP);
  pinMode(level4, INPUT_PULLUP);
  pinMode(level5, INPUT_PULLUP);
  pinMode(motor, OUTPUT);
  pinMode(buzz, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  digitalWrite(green, HIGH);
}

void loop()
{
  // put your main code here, to run repeatedly:

  if (digitalRead(level5) == LOW)
  {
    //display
    lcd.setCursor(0,0);
    lcd.print("Water Pump OFF");
    lcd.setCursor(0, 1);
    lcd.print("Water Level=100%");
    digitalWrite(motor, HIGH);
    digitalWrite(green, HIGH);
    digitalWrite(red, LOW);
  }
 else 
  {  if (digitalRead(level4) == LOW)
    {
      //display
      lcd.setCursor(0, 1);
      lcd.print("Water Level= 80%");
    }
    else 
    { 
      if (digitalRead(level3) == LOW)
      {   //display
          lcd.setCursor(0, 1);
          lcd.print("Water Level= 60%");
      }
      else 
      {
         if (digitalRead(level2) == LOW)
         {
            //display
            lcd.setCursor(0, 1);
            lcd.print("Water Level= 40%");
        }

        else 
        {
          if (digitalRead(level1) == LOW)
          {
              lcd.setCursor(0, 1);
              lcd.print("Water Level= 20%");
          }
          else 
          {
            if (digitalRead(level0) == LOW)
            {
              lcd.setCursor(0, 1);
              lcd.print("Water Level= 10%");
              digitalWrite(green, LOW);
              digitalWrite(red, HIGH);
              digitalWrite(buzz, HIGH);
              delay(100);
              digitalWrite(buzz, LOW);
              delay(100);
              digitalWrite(buzz, HIGH);
              delay(100);
              digitalWrite(buzz, LOW);
              delay(100);
              digitalWrite(buzz, HIGH);
              delay(100);
              digitalWrite(buzz, LOW);
              delay(100);
              digitalWrite(buzz, HIGH);
              delay(100);
              digitalWrite(buzz, LOW);
              lcd.clear();
              lcd.setCursor(0,0);
              lcd.print("Motor Pump ON");
              digitalWrite(motor, LOW);
            }
            else 
            {
              if (digitalRead(level5) == LOW)
              {
                digitalWrite(motor, HIGH);
                digitalWrite(red, LOW);
                digitalWrite(green, HIGH);
              }
            }
          }
        }
      }
    }
  }
}
 
