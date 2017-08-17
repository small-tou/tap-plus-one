
int nowNum = 0;

// LCD 接脚: rs, enable, d4, d5, d6, d7 
// 对应到Arduino 接脚: 12, 11, 6, 5, 4, 3 
LiquidCrystal lcd(12, 11, 6, 5, 4, 3);

void setup() {
  // uno 为 pin2
  attachInterrupt(0, plusOne, CHANGE);
  // uno 为 pin3
  attachInterrupt(1, clear, CHANGE);

  lcd.begin(16, 2);
  lcd.print("PD Counter");

  Serial.begin(9600);
  
}

void loop() {
  lcd.setCursor(0, 1);
  lcd.print(String(nowNum));
  delay(300);
  lcd.setCursor(0, 1);
  lcd.print("");
  delay(300);
}

void plusOne() {
  nowNum += 1;
}

void clear() {
  nowNum = 0;
}