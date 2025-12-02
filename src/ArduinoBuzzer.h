#pragma once
#include <Arduino.h>
#include "BuzzerNote.h"

class Buzzer
{
public:
  Buzzer(uint8_t num);

  void begin();
  void pull();
  void play(const Note* notes, size_t size);
  void play(Note note);
  void stop();
  bool isPlaying() const;

private:
  const uint8_t num;
  const Note* notes;
  size_t size;
  size_t pos;
  unsigned long time;
  Note dummy;
};