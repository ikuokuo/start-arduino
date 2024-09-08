/*
  Tone on speaker.

  tone(): https://www.arduino.cc/reference/en/language/functions/advanced-io/tone

  Schematic: tone_speaker2.png
*/

const int potPin = A0;
const int spkPin = 8;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(potPin);

  // map(value, fromLow, fromHigh, toLow, toHigh)
  int outputValue = map(sensorValue, 0, 1023, 120, 1500);

  Serial.print("sensor = ");
  Serial.print(sensorValue);
  Serial.print("\t output = ");
  Serial.println(outputValue);

  // tone(pin, frequency, duration)
  tone(spkPin, outputValue, 10);

  delay(2);
}
