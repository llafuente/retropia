#include "controller.h"

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

void delete_controller(controller_t** controller) {
  free(*controller);
  *controller = 0;
}

void debug_controller_def(controller_def_t* controller_def) {
  printf("name %c whatis: (%u) ", controller_def->name, controller_def->definition);


  if ((controller_def->definition & DEFINITION_ANALOG_BUTTON) == DEFINITION_ANALOG_BUTTON) {
    printf("ANALOG_BUTTON, ");
  }
  if ((controller_def->definition & DEFINITION_ANALOG_SHOULDER_BUTTON) == DEFINITION_ANALOG_SHOULDER_BUTTON) {
    printf("ANALOG_SHOULDER_BUTTON, ");
  }
  if ((controller_def->definition & DEFINITION_ANALOG_PAD) == DEFINITION_ANALOG_PAD) {
    printf("ANALOG_PAD, ");
  }
  if ((controller_def->definition & DEFINITION_RUMBLE) == DEFINITION_RUMBLE) {
    printf("RUMBLE, ");
  }
  if ((controller_def->definition & DEFINITION_TRIGGER) == DEFINITION_TRIGGER) {
    printf("TRIGGER, ");
  }
  if ((controller_def->definition & DEFINITION_DIGITAL_STICK) == DEFINITION_DIGITAL_STICK) {
    printf("DIGITAL_STICK, ");
  }

  printf("usage: (%u) ", controller_def->usage);

  if ((controller_def->usage & USAGE_ACTION) == USAGE_ACTION) {
    printf("ACTION, ");
  }
  if ((controller_def->usage & USAGE_START) == USAGE_START) {
    printf("START, ");
  }
  if ((controller_def->usage & USAGE_SELECT) == USAGE_SELECT) {
    printf("SELECT, ");
  }
  if ((controller_def->usage & USAGE_HOME) == USAGE_HOME) {
    printf("HOME, ");
  }
  if ((controller_def->usage & USAGE_OPTIONS ) == USAGE_OPTIONS) {
    printf("OPTIONS, ");
  }
  if ((controller_def->usage & USAGE_PRIMARY_PAD ) == USAGE_PRIMARY_PAD) {
    printf("PRIMARY_PAD, ");
  }
  if ((controller_def->usage & USAGE_SECONDARY_PAD ) == USAGE_SECONDARY_PAD) {
    printf("SECONDARY_PAD, ");
  }
  if ((controller_def->usage & USAGE_MOVEMENT) == USAGE_MOVEMENT) {
    printf("MOVEMENT, ");
  }
  if ((controller_def->usage & USAGE_HORIZONTAL) == USAGE_HORIZONTAL) {
    printf("HORIZONTAL, ");
  }
  if ((controller_def->usage & USAGE_VERTICAL) == USAGE_VERTICAL) {
    printf("VERTICAL, ");
  }

  printf("position: (%u) ", controller_def->position);


    if ((controller_def->position & POSITION_LEFT) == POSITION_LEFT) {
      printf("LEFT, ");
    }
    if ((controller_def->position & POSITION_CENTER) == POSITION_CENTER) {
      printf("CENTER, ");
    }
    if ((controller_def->position & POSITION_RIGHT) == POSITION_RIGHT) {
      printf("RIGHT, ");
    }
    if ((controller_def->position & POSITION_DOWN) == POSITION_DOWN) {
      printf("DOWN, ");
    }
    if ((controller_def->position & POSITION_UP) == POSITION_UP) {
      printf("UP, ");
    }
    if ((controller_def->position & POSITION_MIDDLE) == POSITION_MIDDLE) {
      printf("MIDDLE, ");
    }
    if ((controller_def->position & POSITION_CONTROL) == POSITION_CONTROL) {
      printf("CONTROL, ");
    }
    if ((controller_def->position & POSITION_SHOULDER) == POSITION_SHOULDER) {
      printf("SHOULDER, ");
    }


  printf("\n");
}
