const int LEDwater = 2;
const int LEDlight = 4;
const int WaterSensor = A1;
const int PhotoSensor = A0;

int WaterSensorReading = 0;
int PhotoSensorReading = 0;

const long interval = 500;                                        // Interval of the blinking
unsigned long previousMillisForWater = 0;
unsigned long previousMillisForLight = 0;

void setup() {
  Serial.begin(9600);
  pinMode(LEDwater, OUTPUT);
  pinMode(LEDlight, OUTPUT);
}

void loop() {
  WaterSensorReading = analogRead(WaterSensor);
  PhotoSensorReading = analogRead(PhotoSensor);
  unsigned long currentMillis = millis();                         // Starts the counting of millis

  ///// WATER /////
  if (WaterSensorReading < 10){                                   // If water level is critical
    if (currentMillis - previousMillisForWater >= interval) {
      previousMillisForWater = currentMillis;

      if (digitalRead(LEDwater) == LOW) {                         // Blink
        digitalWrite(LEDwater, HIGH);
      } else
        digitalWrite(LEDwater, LOW);
    }
  }
  if (WaterSensorReading <= 100 && WaterSensorReading > 10)        // If plant is thirsty
    digitalWrite(LEDwater, HIGH);
  if (WaterSensorReading > 100)                                   // If plant doesn't need water
    digitalWrite(LEDwater, LOW);

  ///// LIGHT /////
  if (PhotoSensorReading < 200){                                  // If light level is critically low
    if (currentMillis - previousMillisForLight >= interval) {
      previousMillisForLight = currentMillis;

      if (digitalRead(LEDlight) == LOW) {                         // Blink
        digitalWrite(LEDlight, HIGH);
      } else
        digitalWrite(LEDlight, LOW);
    }
  }
  if (PhotoSensorReading < 400 && PhotoSensorReading >= 200)       // If light is needed
    digitalWrite(LEDlight, HIGH);
  if (PhotoSensorReading > 400)                                   // If plant doesn't need light
    digitalWrite(LEDlight, LOW);

  ///// FOR PLOTTING /////
  Serial.print(WaterSensorReading);
  Serial.print(",");
  Serial.println(PhotoSensorReading);
}
