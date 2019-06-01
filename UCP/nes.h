#include "controller.h"

#ifndef YUPI_NES_H
#define YUPI_NES_H

#define NES_CONTROLLER_SELECT 0
#define NES_CONTROLLER_START 1

#define NES_CONTROLLER_UP 2
#define NES_CONTROLLER_RIGHT 3
#define NES_CONTROLLER_DOWN 4
#define NES_CONTROLLER_LEFT 5

#define NES_CONTROLLER_A 6
#define NES_CONTROLLER_B 7

struct declaration_t nes_controller[8] = {
  {
    DEFINITION_ANALOG_BUTTON,
    's', // select
    POSITION_SELECT,
    0,
    0
  },
  {
    DEFINITION_ANALOG_BUTTON,
    'h', // start/home
    POSITION_START,
    0,
    0
  },
  {
    DEFINITION_ANALOG_PAD,
    'u', // up
    POSITION_UP,
    0,
    0
  },
  {
    DEFINITION_ANALOG_PAD,
    'r', // right
    POSITION_RIGHT,
    0,
    0
  },
  {
    DEFINITION_ANALOG_PAD,
    'd', // down
    POSITION_DOWN,
    0,
    0
  },
  {
    DEFINITION_ANALOG_PAD,
    'l', // left
    POSITION_LEFT,
    0,
    0
  },


  {
    DEFINITION_ANALOG_BUTTON,
    'a', // a
    POSITION_LEFT,
    0,
    0
  },
  {
    DEFINITION_ANALOG_BUTTON,
    'b', // B
    POSITION_RIGHT,
    0,
    0
  },
};


#endif
