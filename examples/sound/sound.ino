#include <ArduinoBuzzer.h>
#include <Arduino.h>

const Note SOUND_OK[] = {
  { NOTE_G4, 65  },
  { NOTE_C5, 65  },
  { NOTE_E5, 65  },
  { NOTE_F5, 130 }
};
constexpr size_t SOUND_OK_SIZE = sizeof(SOUND_OK) / sizeof(Note);

const Note SOUND_NOK[] = {
  { NOTE_F5, 65  },
  { NOTE_E5, 65  },
  { NOTE_C5, 65  },
  { NOTE_G4, 130 }
};
constexpr size_t SOUND_NOK_SIZE = sizeof(SOUND_NOK) / sizeof(Note);

const Note SOUND_ACCEPT[] = {
  { NOTE_F3,     65 },
  { NOTE_SILENT, 50 },
  { NOTE_B4,     65 }
};
constexpr size_t SOUND_ACCEPT_SIZE = sizeof(SOUND_ACCEPT) / sizeof(Note);

const Note SOUND_REJECT[] = {
  { NOTE_B4,     65 },
  { NOTE_SILENT, 50 },
  { NOTE_F3,     65 }
};
constexpr size_t SOUND_REJECT_SIZE = sizeof(SOUND_REJECT) / sizeof(Note);

const Note SOUND_DROP[] = {
  { NOTE_F3, 50 },
  { NOTE_B4, 50 }
};
constexpr size_t SOUND_DROP_SIZE = sizeof(SOUND_DROP) / sizeof(Note);

const Note SOUND_REDROP[] = {
  { NOTE_F3, 50 },
  { NOTE_B4, 50 },
  { NOTE_F3, 50 }
};
constexpr size_t SOUND_REDROP_SIZE = sizeof(SOUND_REDROP) / sizeof(Note);

#define BUZZER 1
Buzzer buzzer(BUZZER);

unsigned long t = 0;
int count = 0;

void setup() {
  buzzer.begin();
}

void loop() {
  buzzer.pull();

  const auto now = millis();
  const auto diff = now - t;
  if (diff > 1000) {
    t = now;

    switch (count)
    {
    case 0:
      buzzer.play(SOUND_OK, SOUND_OK_SIZE);
      break;
    case 1:
      buzzer.play(SOUND_NOK, SOUND_NOK_SIZE);
      break;
    case 2:
      buzzer.play(SOUND_ACCEPT, SOUND_ACCEPT_SIZE);
      break;
    case 3:
      buzzer.play(SOUND_REJECT, SOUND_REJECT_SIZE);
      break;
    case 4:
      buzzer.play(SOUND_DROP, SOUND_DROP_SIZE);
      break;
    case 5:
      buzzer.play(SOUND_REDROP, SOUND_REDROP_SIZE);
      break;
    default:
      break;
    }

    count++;
  }
}