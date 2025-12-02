#include <ArduinoBuzzer.h>
#include <Arduino.h>

const Note SOUND_OK[] {
  { NOTE_G4, 65  },
  { NOTE_C5, 65  },
  { NOTE_E5, 65  },
  { NOTE_F5, 130 }
};
const Note SOUND_NOK[] {
  { NOTE_F5, 65  },
  { NOTE_E5, 65  },
  { NOTE_C5, 65  },
  { NOTE_G4, 130 }
};
const Note SOUND_ACCEPT[] {
  { NOTE_F3,     65 },
  { NOTE_SILENT, 50 },
  { NOTE_B4,     65 }
};
const Note SOUND_REJECT[] {
  { NOTE_B4,     65 },
  { NOTE_SILENT, 50 },
  { NOTE_F3,     65 }
};
const Note SOUND_DROP[] {
  { NOTE_F3, 50 },
  { NOTE_B4, 50 }
};
const Note SOUND_REDROP[] {
  { NOTE_F3, 50 },
  { NOTE_B4, 50 },
  { NOTE_F3, 50 }
};

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
      buzzer.play(SOUND_OK);
      break;
    case 1:
      buzzer.play(SOUND_NOK);
      break;
    case 2:
      buzzer.play(SOUND_ACCEPT);
      break;
    case 3:
      buzzer.play(SOUND_REJECT);
      break;
    case 4:
      buzzer.play(SOUND_DROP);
      break;
    case 5:
      buzzer.play(SOUND_REDROP);
      break;
    default:
      break;
    }

    count++;
  }
}