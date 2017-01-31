/**
  * Pulsar Arduino
  */
//_________________________________________________________________

# define POTENTIOMETER_PIN 3

int value;
float reading;


//_________________________________________________________________

void readPotentiometerValue(int delayBetweenValue){
  reading = analogRead(POTENTIOMETER_PIN);
  // Serial.print("\t reading : \t");
  // Serial.println(reading);
  value = reading*401/1024 ;  //analogRead(PIN)*RANGE/1024.0
  //Serial.print("\t value : \t");
  Serial.println(value);
  delay(delayBetweenValue);
}

void setup() {
  pinMode(POTENTIOMETER_PIN,INPUT);
  Serial.begin(9600);
}

void loop() {
  readPotentiometerValue(500);
}
