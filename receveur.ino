#include <LiquidCrystal.h>
#define RS 12
#define ENABLE 11
#define D4 5
#define D5 4
#define D6 3
#define D7 2

LiquidCrystal lcd(RS, ENABLE, D4, D5, D6, D7);

const int led = 13;

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  lcd.begin(16, 2);
  lcd.clear();
}

void loop() {
  if (Serial.available()){
    int msg = Serial.parseInt();
    if (msg == 1) {
      digitalWrite(led, HIGH);
      lcd.clear();
      lcd.print("LED ON");
      Serial.println(2);
    }
    else {
      digitalWrite(led, LOW);
      Serial.println(3);
      lcd.clear();
      lcd.print("LED OFF");
    }
  }
}
