// https://docs.arduino.cc/learn/programming/eeprom-guide

#include <EEPROM.h>

void setup() {
  Serial.begin(9600);
  while (!Serial) {}

  Serial.print("EEPROM length: ");
  Serial.println(EEPROM.length());

  floatTest();

  objectTest();
}

void loop() {
}

void floatTest() {
  int eeAddress = 0x400;
  float f = 123.456f;

  if ((eeAddress + sizeof(float)) > EEPROM.length()) {
    Serial.println("EEPROM not enough!");
    return;
  }

  // Write any data type or object to the EEPROM.
  EEPROM.put(eeAddress, f);
  // N/A! Write a byte to the EEPROM, only if differs from the one already saved at the same address.
  // EEPROM.update(eeAddress, f);

  Serial.print("Write addr 0x" + String(eeAddress, 16) + ", float: ");
  Serial.println(f, 3);

  // Read any data type or object from the EEPROM
  EEPROM.get(eeAddress, f);

  Serial.print("Read addr 0x" + String(eeAddress, 16) + ", float: ");
  Serial.println(f, 3);
}

void objectTest() {
  int eeAddress = 0x800;

  struct MyObject {
    float field1;
    byte field2;
    char name[10];
  };

  if ((eeAddress + sizeof(MyObject)) > EEPROM.length()) {
    Serial.println("EEPROM not enough!");
    return;
  }

  {
    MyObject obj = {
      3.14f,
      65,
      "Working!"
    };

    EEPROM.put(eeAddress, obj);
    // EEPROM.update(eeAddress, obj);
    Serial.println("Write custom object 0x" + String(eeAddress, 16) + "!");
  }

  {
    MyObject obj;

    EEPROM.get(eeAddress, obj);
    Serial.println("Read custom object 0" + String(eeAddress, 16) + ": ");
    Serial.println(obj.field1);
    Serial.println(obj.field2);
    Serial.println(obj.name);
  }
}
