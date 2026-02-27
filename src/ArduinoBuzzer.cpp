#include "ArduinoBuzzer.h"

Buzzer::Buzzer(uint8_t num) :
  Buzzer(num, HIGH)
{}

Buzzer::Buzzer(uint8_t num, bool activeState) :
  num(num),
  inactiveState(!activeState),
  notes(&dummy),
  size(),
  pos(),
  time(),
  dummy()
{}

void Buzzer::begin() {
  pinMode(num, OUTPUT);
  digitalWrite(num, inactiveState);
}

void Buzzer::pull() {
  if (not isPlaying())
    return;

  const auto now = millis();

  if (now - time < notes[pos].duration)
    return;

  pos++;
  if (pos >= size) {
    stop();
    return;
  }

  time = now;
  tone(num, notes[pos].frequency, notes[pos].duration);
}

void Buzzer::play(const Note* notes, size_t size) {
  this->notes = notes;
  this->size = size;
  pos = 0;

  time = millis();
  tone(num, notes[pos].frequency, notes[pos].duration);
}

void Buzzer::play(Note note) {
  dummy = note;
  play(&dummy, 1);
}

void Buzzer::stop() {
  noTone(num);
  digitalWrite(num, inactiveState);
  size = 0;
}

bool Buzzer::isPlaying() const {
  return size;
}