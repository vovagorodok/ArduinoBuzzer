#include <ArduinoBuzzer.h>
#include <Arduino.h>

#define BUZZER 1
Buzzer buzzer(BUZZER);

void setup() {
  buzzer.begin();
  buzzer.play({NOTE_G4, 1000});
}

void loop() {
  buzzer.pull();
}