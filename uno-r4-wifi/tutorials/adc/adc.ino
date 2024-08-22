// https://docs.arduino.cc/tutorials/uno-r4-wifi/adc-resolution
// https://docs.arduino.cc/tutorials/uno-r4-wifi/cheat-sheet/#analog-pins

// The standard resolution on Arduino boards is set to 10-bit (0-1023).
// The UNO R4 WiFi supports up to 14-bit resolutions, which can provide a more precise value from analog signals.

void setup() {
  analogReadResolution(14);  // change to 14-bit resolution
}

void loop() {
  int reading = analogRead(A3);  // returns a value between 0-16383
}
