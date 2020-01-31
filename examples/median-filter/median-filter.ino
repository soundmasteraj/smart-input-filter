#include "median-filter.h"

const uint8_t kInputPin = 0;
const uint8_t kLedPin = 13;
MedianFilter<uint32_t, 5> *filter;

void setup() {
  pinMode(kInputPin, INPUT_PULLUP);
  filter = new MedianFilter<uint32_t, 5>(kInputPin);
  filter->SetLogToSerial(true);

  pinMode(kLedPin, OUTPUT);
}

void loop() {
  filter->Run();
  Serial.flush();
  delay(10);
}

