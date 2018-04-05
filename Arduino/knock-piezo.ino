const int knockSensor1 = A0; // the piezo is connected to analog pin 0
const int knockSensor2 = A2;
const int threshold = 4;  // threshold value to decide when the detected sound is a knock or not

int sensorReading1 = 0;      // variable to store the value read from the sensor pin
int sensorReading2 = 0;

void setup() {
  Serial.begin(9600);       // use the serial port
}

void loop() {
  sensorReading1 = analogRead(knockSensor1);
  sensorReading2 = analogRead(knockSensor2);

  if (sensorReading1 >= threshold) {
    Serial.println(1);
    delay(200);  // delay to avoid overloading the serial port buffer
  }

  if (sensorReading2 >= threshold) {
    Serial.println(2);
    delay(200);  // delay to avoid overloading the serial port buffer
  }
}
