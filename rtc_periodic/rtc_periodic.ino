// https://docs.arduino.cc/tutorials/uno-r4-wifi/rtc/#periodic-interrupt

#include "RTC.h"

volatile bool irqFlag = false;
volatile bool ledState = false;

const int led = LED_BUILTIN;

void setup() {
  pinMode(led, OUTPUT);

  Serial.begin(9600);

  // Initialize the RTC
  RTC.begin();

  // RTC.setTime() must be called for RTC.setPeriodicCallback to work, but it doesn't matter
  // what date and time it's set to
  RTCTime mytime(30, Month::JUNE, 2023, 13, 37, 00, DayOfWeek::WEDNESDAY, SaveLight::SAVING_TIME_ACTIVE);
  RTC.setTime(mytime);

  if (!RTC.setPeriodicCallback(periodicCallback, Period::ONCE_EVERY_2_SEC)) {
    Serial.println("ERROR: periodic callback not set");
  }
}

void loop() {
  if (irqFlag) {
    Serial.println("Timed CallBack");
    ledState = !ledState;
    digitalWrite(LED_BUILTIN, ledState);
    irqFlag = false;
  }
}

void periodicCallback() {
  irqFlag = true;
}
