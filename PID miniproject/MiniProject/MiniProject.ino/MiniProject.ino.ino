const int LEDgreen = 4;
const int LEDyellow = 2;
const int WaterSensor = A1;
const int PhotoSensor = A0;

int WaterSensorReading = 0;
int PhotoSensorReading = 0;

unsigned long previousMillis = 0;
const long interval = 500;

void setup() {
  Serial.begin(9600);
  pinMode(LEDgreen, OUTPUT);
  pinMode(LEDyellow, OUTPUT);
}

void loop() {
  WaterSensorReading = analogRead(WaterSensor);
  PhotoSensorReading = analogRead(PhotoSensor);
  
  unsigned long currentMillis = millis();

  if (WaterSensorReading < 10)   // If water level is critical
    if (currentMillis - previousMillis >= interval) {
      previousMillis = currentMillis;

      if (digitalRead(LEDgreen) == LOW) { // Blink
        digitalWrite(LEDgreen, HIGH);
      } else
        digitalWrite(LEDgreen, LOW);
    }
  if (WaterSensorReading < 200 && WaterSensorReading > 10) {   // If plant is thirsty
    digitalWrite(LEDgreen, HIGH);
  }
  if (WaterSensorReading > 200)
    digitalWrite(LEDgreen, LOW);

  if (PhotoSensorReading < 200) {   // If plant needs light
    digitalWrite(LEDyellow, HIGH);
  }
  else
    digitalWrite(LEDyellow, LOW);   // If plant doesn't need light
  
  Serial.print(PhotoSensorReading);
  Serial.print(",");
  Serial.println(WaterSensorReading);
}
