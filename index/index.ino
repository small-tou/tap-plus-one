#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);   
volatile int nowNum = 0;
volatile bool showPlusOne = false;
void setup() {
  // uno 为 pin2
  attachInterrupt(0, plusOne, RISING);

  lcd.init();                  // 初始化LCD  
  lcd.backlight();             //设置LCD背景等亮  
  lcd.setCursor(0, 1);
  lcd.print("PD COUNTER");
  delay(2000);
  
  Serial.begin(9600);
}

void loop() {
  if(showPlusOne){
    nowNum = nowNum+1;
    showPlusOne = false;
    lcd.setCursor(0, 1);
    lcd.print("ADD A PD");
  }
  delay(500);
  lcd.setCursor(0, 1);
  lcd.clear();
  delay(500);
  lcd.setCursor(0, 1);
  lcd.print(String(nowNum));
}

void plusOne() {
  showPlusOne = true;
}

