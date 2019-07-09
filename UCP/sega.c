#include "sega.h"
#include "controller.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

controller_t* create_sega_saturn_mk_80116() {
  uint32_t size = sizeof(controller_t) + SEGA_SATURN_CONTROLLER_SIZE * sizeof(controller_def_t);
  controller_t* ctrl = malloc(size);
  assert(ctrl);
  memcpy(ctrl, &sega_saturn_mk_80116, size);

  return ctrl;
}

controller_t* create_sega_dreamcast_hkt_7700() {
  uint32_t size = sizeof(controller_t) + SEGA_DREAMCAST_CONTROLLER_SIZE * sizeof(controller_def_t);
  controller_t* ctrl = malloc(size);
  assert(ctrl);
  memcpy(ctrl, &sega_dreamcast_hkt_7700, size);

  return ctrl;
}

controller_t* create_sega_master_system_model_3020() {
  uint32_t size = sizeof(controller_t) + SEGA_MASTER_SYSTEM_CONTROLLER_SIZE * sizeof(controller_def_t);
  controller_t* ctrl = malloc(size);
  assert(ctrl);
  memcpy(ctrl, &sega_master_system_model_3020, size);

  return ctrl;
}

controller_t sega_saturn_mk_80116 = {
  "mk-80116",
  SEGA_SATURN_CONTROLLER_SIZE,
  {
    BUTTON_START,
    BUTTON_PRIMARY_PAD_UP,
    BUTTON_PRIMARY_PAD_RIGHT,
    BUTTON_PRIMARY_PAD_DOWN,
    BUTTON_PRIMARY_PAD_LEFT,

    BUTTON_SHOULDER_LEFT,
    BUTTON_SHOULDER_RIGHT,


    {
      DEFINITION_ANALOG_BUTTON,
      USAGE_ACTION,
      POSITION_LEFT | POSITION_DOWN,
      'a', // A
      0
    },
    {
      DEFINITION_ANALOG_BUTTON,
      USAGE_ACTION,
      POSITION_MIDDLE | POSITION_DOWN,
      'b', // B
      0
    },
    {
      DEFINITION_ANALOG_BUTTON,
      USAGE_ACTION,
      POSITION_RIGHT | POSITION_DOWN,
      'c', // C
      0
    },

    {
      DEFINITION_ANALOG_BUTTON,
      USAGE_ACTION,
      POSITION_LEFT | POSITION_DOWN,
      'x', // X
      0
    },
    {
      DEFINITION_ANALOG_BUTTON,
      USAGE_ACTION,
      POSITION_MIDDLE | POSITION_DOWN,
      'y', // Y
      0
    },
    {
      DEFINITION_ANALOG_BUTTON,
      USAGE_ACTION,
      POSITION_RIGHT | POSITION_DOWN,
      'z', // Z
      0
    },
  }
};


controller_t sega_dreamcast_hkt_7700 = {
  "hkt-7700",
  SEGA_DREAMCAST_CONTROLLER_SIZE,
  {
    BUTTON_START,
    BUTTON_PRIMARY_PAD_UP,
    BUTTON_PRIMARY_PAD_RIGHT,
    BUTTON_PRIMARY_PAD_DOWN,
    BUTTON_PRIMARY_PAD_LEFT,

    BUTTON_SHOULDER_LEFT,
    BUTTON_SHOULDER_RIGHT,


    {
      DEFINITION_ANALOG_BUTTON,
      USAGE_ACTION,
      POSITION_LEFT | POSITION_DOWN,
      'a', // A
      0
    },
    {
      DEFINITION_ANALOG_BUTTON,
      USAGE_ACTION,
      POSITION_MIDDLE | POSITION_DOWN,
      'b', // B
      0
    },

    {
      DEFINITION_ANALOG_BUTTON,
      USAGE_ACTION,
      POSITION_LEFT | POSITION_DOWN,
      'x', // X
      0
    },
    {
      DEFINITION_ANALOG_BUTTON,
      USAGE_ACTION,
      POSITION_MIDDLE | POSITION_DOWN,
      'y', // Y
      0
    },

    PRIMARY_HORIZONTAL_STICK,
    PRIMARY_VERTICAL_STICK,
  }
};

controller_t sega_master_system_model_3020 = {
  "model-3020",
  SEGA_MASTER_SYSTEM_CONTROLLER_SIZE,
  {
    BUTTON_START,
    BUTTON_PRIMARY_PAD_UP,
    BUTTON_PRIMARY_PAD_RIGHT,
    BUTTON_PRIMARY_PAD_DOWN,
    BUTTON_PRIMARY_PAD_LEFT,

    BUTTON_SHOULDER_LEFT,
    BUTTON_SHOULDER_RIGHT,

    // 1 - START
    {
      DEFINITION_ANALOG_BUTTON,
      USAGE_ACTION,
      POSITION_LEFT | POSITION_DOWN,
      'a', // A
      0
    },
    // 2
    {
      DEFINITION_ANALOG_BUTTON,
      USAGE_ACTION,
      POSITION_RIGHT | POSITION_UP,
      'b', // B
      0
    }
  }
};
