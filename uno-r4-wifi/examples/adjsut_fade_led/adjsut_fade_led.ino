/*
  Adjust frequency of fading an LED.
*/

int ledPin = 9;   // LED connected to digital pin 9
int potPin = A0;  // Analog input pin that the potentiometer is attached to

void setup() {
  // nothing happens in setup
}

void loop() {
  // fade in from min to max in increments of 5 points:
  for (int fadeValue = 0; fadeValue <= 255; fadeValue += 5) {
    // sets the value (range from 0 to 255):
    analogWrite(ledPin, fadeValue);
    // wait time by pot value
    int time = analogRead(potPin) / 5;
    delay(time);
  }

  // fade out from max to min in increments of 5 points:
  for (int fadeValue = 255; fadeValue >= 0; fadeValue -= 5) {
    // sets the value (range from 0 to 255):
    analogWrite(ledPin, fadeValue);
    // wait time by pot value
    int time = analogRead(potPin) / 5;
    delay(time);
  }
}
