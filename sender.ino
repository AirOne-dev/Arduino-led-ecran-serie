#include <LiquidCrystal.h>
#define RS 12
#define ENABLE 11
#define D4 5
#define D5 4
#define D6 3
#define D7 2

LiquidCrystal lcd(RS, ENABLE, D4, D5, D6, D7);

const int button = 10;
int etat_button = 0;
const int led = 13;
int etat_msg = 0;

void setup() {
  Serial.begin(9600);
  pinMode(button, INPUT);
  pinMode(led, OUTPUT);
  lcd.begin(16, 2);
  lcd.clear();
  lcd.print("LED OFF");
}

void loop() {
  etat_button = digitalRead(button); //------------------------
  if (etat_button == HIGH) {         //
    Serial.println(1);               // Partie qui envoie '1'
  }                                  // sur le port serie quand
  else {                             // on appuie sur le boutton
    Serial.println(0);               //  
  }                                  //------------------------

  if (Serial.available()) {
    int rep = Serial.parseInt();
    if (rep == 2) {
      if (etat_msg == 1) {
      }
      else {
        etat_msg = 1;
        lcd.clear();
        lcd.print("LED ON");
      }
      digitalWrite(led, HIGH);       // Partie qui allume la
    }                                // LED quand on reçoit
    else {                           // '2' sur le port série
      digitalWrite(led, LOW);        //
      if (etat_msg == 0) {
      }
      else {
        etat_msg = 0;
        lcd.clear();
        lcd.print("LED OFF");
      }
    }
  }
  delay(50);
}
