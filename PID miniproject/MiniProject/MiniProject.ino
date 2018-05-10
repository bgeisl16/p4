const int LEDgreen = 4;
const int LEDyellow = 2;
const int WaterSensor = A1;
const int PhotoSensor = A0;

int WaterSensorReading = 0;
int PhotoSensorReading = 0;

void setup() {
  Serial.begin(9600);
  pinMode(LEDgreen, OUTPUT);
  pinMode(LEDyellow, OUTPUT);
}

void loop() {
  WaterSensorReading = analogRead(WaterSensor);
  PhotoSensorReading = analogRead(PhotoSensor);

  if (WaterSensorReading < 200) {   // If plant is thirsty
    digitalWrite(LEDgreen, HIGH);
  }
  else
    digitalWrite(LEDgreen, LOW);

  if (PhotoSensorReading < 200) {   // If plant needs light
    digitalWrite(LEDyellow, HIGH);
  }
  else
    digitalWrite(LEDyellow, LOW);
}
