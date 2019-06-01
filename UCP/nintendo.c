#include "controller.h"
#include "nintendo.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

controller_t* create_nintendo_nes_004() {
  uint32_t size = sizeof(controller_t) + NINTENDO_NES_004_SIZE * sizeof(controller_def_t);
  controller_t* ctrl = malloc(size);
  assert(ctrl);
  memcpy(ctrl, &nintendo_nes_004, size);

  return ctrl;
}

controller_t* create_nintendo_snes_005() {
  uint32_t size = sizeof(controller_t) + NINTENDO_SNES_005_SIZE * sizeof(controller_def_t);
  controller_t* ctrl = malloc(size);
  assert(ctrl);
  memcpy(ctrl, &nintendo_snes_005, size);

  return ctrl;
}

controller_t* create_nintendo_nus_005() {
  uint32_t size = sizeof(controller_t) + NINTENDO_NUS_005_SIZE * sizeof(controller_def_t);
  controller_t* ctrl = malloc(size);
  assert(ctrl);
  memcpy(ctrl, &nintendo_nus_005, size);

  return ctrl;
}


controller_t nintendo_nes_004 = {
  "nes-004",
  NINTENDO_NES_004_SIZE,
  {
    BUTTON_START,
    BUTTON_SELECT,

    BUTTON_PRIMARY_PAD_UP,
    BUTTON_PRIMARY_PAD_RIGHT,
    BUTTON_PRIMARY_PAD_DOWN,
    BUTTON_PRIMARY_PAD_LEFT,

    {
      DEFINITION_ANALOG_BUTTON,
      USAGE_ACTION,
      POSITION_LEFT,
      'a', // A
      0
    },
    {
      DEFINITION_ANALOG_BUTTON,
      USAGE_ACTION,
      POSITION_RIGHT,
      'b', // B
      0
    },
  }
};


controller_t nintendo_snes_005 = {
  "snes-005",
  NINTENDO_SNES_005_SIZE,
  {
    BUTTON_START,
    BUTTON_SELECT,

    BUTTON_PRIMARY_PAD_UP,
    BUTTON_PRIMARY_PAD_RIGHT,
    BUTTON_PRIMARY_PAD_DOWN,
    BUTTON_PRIMARY_PAD_LEFT,

    BUTTON_SHOULDER_LEFT,
    BUTTON_SHOULDER_RIGHT,

    {
      DEFINITION_ANALOG_BUTTON,
      USAGE_ACTION,
      POSITION_UP,
      'x', // X
      0
    },
    {
      DEFINITION_ANALOG_BUTTON,
      USAGE_ACTION,
      POSITION_RIGHT,
      'a', // A
      0
    },
    {
      DEFINITION_ANALOG_BUTTON,
      USAGE_ACTION,
      POSITION_DOWN,
      'b', // B
      0
    },
    {
      DEFINITION_ANALOG_BUTTON,
      USAGE_ACTION,
      POSITION_LEFT,
      'y', // Y
      0
    },
  }
};


controller_t nintendo_nus_005 = {
  "nus-005",
  NINTENDO_NUS_005_SIZE,
  {
    BUTTON_START,
    BUTTON_PRIMARY_PAD_UP,
    BUTTON_PRIMARY_PAD_RIGHT,
    BUTTON_PRIMARY_PAD_DOWN,
    BUTTON_PRIMARY_PAD_LEFT,

    BUTTON_SHOULDER_LEFT,
    BUTTON_SHOULDER_RIGHT,

    {
      DEFINITION_ANALOG_SHOULDER_BUTTON,
      USAGE_ACTION,
      POSITION_CENTER,
      'z', // z-trigger
      0
    },


    {
      DEFINITION_ANALOG_BUTTON,
      USAGE_ACTION,
      POSITION_LEFT | POSITION_DOWN,
      'a', // A
      0
    },
    {
      DEFINITION_ANALOG_BUTTON,
      USAGE_ACTION | USAGE_SECONDARY_PAD,
      POSITION_CENTER | POSITION_DOWN,
      'j', // C-DOWN
      0
    },
    {
      DEFINITION_ANALOG_BUTTON,
      USAGE_ACTION | USAGE_SECONDARY_PAD,
      POSITION_RIGHT | POSITION_DOWN,
      'k', // C-RIGHT
      0
    },

    {
      DEFINITION_ANALOG_BUTTON,
      USAGE_ACTION,
      POSITION_LEFT | POSITION_UP,
      'b', // A
      0
    },
    {
      DEFINITION_ANALOG_BUTTON,
      USAGE_ACTION | USAGE_SECONDARY_PAD,
      POSITION_CENTER | POSITION_UP,
      'u', // C-LEFT
      0
    },
    {
      DEFINITION_ANALOG_BUTTON,
      USAGE_ACTION | USAGE_SECONDARY_PAD,
      POSITION_RIGHT | POSITION_UP,
      'i', // C-UP
      0
    },

    PRIMARY_HORIZONTAL_STICK,
    PRIMARY_VERTICAL_STICK,
  }
};
