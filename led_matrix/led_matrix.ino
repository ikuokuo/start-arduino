// https://docs.arduino.cc/tutorials/uno-r4-wifi/led-matrix/

#include "Arduino_LED_Matrix.h"

ArduinoLEDMatrix matrix;

uint8_t hi[8][12] = {
  { 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0 },
  { 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0 },
  { 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0 },
  { 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0 },
  { 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0 },
  { 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0 },
  { 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0 },
  { 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0 }
};

void setup() {
  Serial.begin(115200);
  // you can also load frames at runtime, without stopping the refresh
  matrix.loadSequence(LEDMATRIX_ANIMATION_STARTUP);
  matrix.begin();
  matrix.play(false);
}

void loop() {
  if (!matrix.sequenceDone()) return;
  delay(1000);
  matrix.renderBitmap(hi, 8, 12);
  delay(1000);
  matrix.loadFrame(LEDMATRIX_HEART_BIG);
}
