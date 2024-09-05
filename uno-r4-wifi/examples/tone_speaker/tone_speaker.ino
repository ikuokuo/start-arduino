/*
  Tone on speaker.

  tone(): https://www.arduino.cc/reference/en/language/functions/advanced-io/tone

  Schematic: tone_speaker.png
*/

const int speakerPin = 8;

void setup() {
}

void loop() {
  for (int i = 200; i <= 800; i++) {
    pinMode(speakerPin, OUTPUT);
    tone(speakerPin, i);
    delay(5);
  }

  delay(4000);

  for (int i = 800; i >= 200; i--) {
    pinMode(speakerPin, OUTPUT);
    tone(speakerPin, i);
    delay(5);
  }
}
