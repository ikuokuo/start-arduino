// https://docs.arduino.cc/tutorials/uno-r4-wifi/eeprom

#include <EEPROM.h>

void setup() {
  Serial.begin(9600);
  while (!Serial) {}

  Serial.print("EEPROM length: ");
  Serial.println(EEPROM.length());

  int addr = 0;
  byte value;

  value = EEPROM.read(addr);
  Serial.print("Read addr 0x0: ");
  Serial.println(value);

  value += 1;
  EEPROM.write(addr, value);
  Serial.print("Write addr 0x0: ");
  Serial.println(value);
}

void loop() {
}
