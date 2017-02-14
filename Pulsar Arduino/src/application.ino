/**
  * Pulsar Arduino
  */
//_________________________________________________________________
#include <LiquidCrystal.h>
// initialize the library with the numbers of the interface pins for the LCD
# define rs  15
# define rw  0
# define en  14
# define d4  4
# define d5  5
# define d6  6
# define d7  7
LiquidCrystal lcd(rs, rw, en, d4, d5, d6, d7);

# define BUTTON1 8
# define BUTTON2 9
# define POTENTIOMETER_PIN 3

int value;
float reading;
int delayBetweenValue;


//_________________________________________________________________

void clearLCD() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("value : ");
  lcd.setCursor(0, 1);
  lcd.print("delay : ");
}


void readPotentiometerValue(int delayBetweenValue){
  reading = analogRead(POTENTIOMETER_PIN);
  value = reading*700/1024 ;  //analogRead(PIN)*RANGE/1024.0
  Serial.println(value);

  clearLCD();
  lcd.setCursor(8, 0);
  lcd.print(value);
  lcd.setCursor(8, 1);
  lcd.print(delayBetweenValue);

  delay(delayBetweenValue);
}


int changeDelayBetweenValue(int delay) {
  if (digitalRead(BUTTON1)==LOW){
    delay += 50;
  }
  if ((digitalRead(BUTTON2)==LOW) && (delay > 50)){
    delay -= 50;
  }
  return delay;
}


void setup() {
  lcd.begin(16, 2);
  lcd.clear();
  pinMode(BUTTON1, INPUT);
  pinMode(BUTTON2, INPUT);

  delayBetweenValue = 500;
  pinMode(POTENTIOMETER_PIN, INPUT);
  Serial.begin(9600);
}


void loop() {
  delayBetweenValue = changeDelayBetweenValue(delayBetweenValue);
  readPotentiometerValue(delayBetweenValue);
}
