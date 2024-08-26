// https://docs.arduino.cc/tutorials/uno-r4-wifi/usb-hid

#include <Keyboard.h>
#include <Mouse.h>

void setup() {
  Serial.begin(9600);

  Keyboard.begin();
  Mouse.begin();
  delay(1000);
}

void loop() {
  Serial.println("Keyboard press w");
  Keyboard.press('w');
  delay(100);
  Keyboard.releaseAll();
  delay(1000);

  Serial.println("Mouse move (10, 10)");
  Mouse.move(10, 10);
  delay(1000);

  Serial.println("Mouse move (-10, -10)");
  Mouse.move(-10, -10);
  delay(1000);
}
