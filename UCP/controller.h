#ifndef YUPI_CONTROLLER_H
#define YUPI_CONTROLLER_H

#include <stdint.h>
#include <stdlib.h>

#define DEFINITION_ANALOG_BUTTON 1
#define DEFINITION_ANALOG_SHOULDER_BUTTON 2
#define DEFINITION_ANALOG_PAD 4
#define DEFINITION_RUMBLE 8
#define DEFINITION_TRIGGER 16
#define DEFINITION_DIGITAL_STICK 32

#define USAGE_ACTION 1
#define USAGE_START 2
#define USAGE_SELECT 4
#define USAGE_HOME 8
#define USAGE_OPTIONS 16
#define USAGE_PRIMARY_PAD 32
#define USAGE_SECONDARY_PAD 64
#define USAGE_MOVEMENT 128
#define USAGE_HORIZONTAL 256
#define USAGE_VERTICAL 512


#define POSITION_LEFT 1
#define POSITION_CENTER 2
#define POSITION_RIGHT 4

#define POSITION_DOWN 8
#define POSITION_UP 16
#define POSITION_MIDDLE 32

#define POSITION_CONTROL 64
#define POSITION_SHOULDER 128

//
// COMMON BUTTON DEFINITION
//

#define BUTTON_PRIMARY_PAD_UP { \
  DEFINITION_ANALOG_PAD, \
  USAGE_PRIMARY_PAD, \
  POSITION_UP, \
  'u', \
  0 \
}

#define BUTTON_PRIMARY_PAD_RIGHT { \
  DEFINITION_ANALOG_PAD, \
  USAGE_PRIMARY_PAD, \
  POSITION_RIGHT, \
  'r', \
  0 \
}

#define BUTTON_PRIMARY_PAD_DOWN { \
  DEFINITION_ANALOG_PAD, \
  USAGE_PRIMARY_PAD, \
  POSITION_DOWN, \
  'd', \
  0 \
}
#define BUTTON_PRIMARY_PAD_LEFT { \
  DEFINITION_ANALOG_PAD, \
  USAGE_PRIMARY_PAD, \
  POSITION_LEFT, \
  'l', \
  0 \
}

#define BUTTON_START { \
  DEFINITION_ANALOG_BUTTON, \
  USAGE_START, \
  POSITION_CONTROL, \
  'h', \
  0 \
}

#define BUTTON_SELECT { \
  DEFINITION_ANALOG_BUTTON, \
  USAGE_SELECT, \
  POSITION_CONTROL, \
  's', \
  0 \
}

#define BUTTON_SHOULDER_LEFT { \
  DEFINITION_ANALOG_SHOULDER_BUTTON, \
  USAGE_ACTION, \
  POSITION_LEFT | POSITION_SHOULDER, \
  'L', \
  0 \
}

#define BUTTON_SHOULDER_RIGHT { \
  DEFINITION_ANALOG_SHOULDER_BUTTON, \
  USAGE_ACTION, \
  POSITION_RIGHT | POSITION_SHOULDER, \
  'R', \
  0 \
}

#define PRIMARY_HORIZONTAL_STICK { \
  DEFINITION_DIGITAL_STICK, \
  USAGE_MOVEMENT | USAGE_HORIZONTAL, \
  POSITION_CENTER, \
  '>', \
  0 \
}

#define PRIMARY_VERTICAL_STICK { \
  DEFINITION_DIGITAL_STICK, \
  USAGE_MOVEMENT | USAGE_VERTICAL, \
  POSITION_CENTER, \
  '^', \
  0 \
}


struct controller_def {
  int definition;
  int usage;
  int position;
  char name;

  // this value need to be casted depending of the definition
  // could be signed, unsigned or float, all 32 bits
  union {
    uint32_t u_value;
    int32_t i_value;
    float f_value;
  };
};

typedef struct controller_def controller_def_t;

struct controller {
  char name[16];
  uint32_t size;
  controller_def_t definitions[];
};

typedef struct controller controller_t;

void delete_controller(controller_t** controller);
void debug_controller_def(controller_def_t* controller_def);

#endif
