/*
  Blink 6 leds sequentially connected to digital pin 2-7.

  Schematic: blink_leds.png
*/

void setup() {
  // sets the digital pin 2-7 as output
  for (int i = 2; i < 8; i++)
    pinMode(i, OUTPUT);
}

void loop() {
  // sets the digital pin 2-6 from on to off
  for (int i = 2; i < 7; i++) {
    digitalWrite(i, HIGH);
    delay(1000);
    digitalWrite(i, LOW);
  }

  // sets the digital pin 7-3 from on to off
  for (int i = 7; i > 2; i--) {
    digitalWrite(i, HIGH);
    delay(1000);
    digitalWrite(i, LOW);
  }
}
