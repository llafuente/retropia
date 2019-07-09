#include "controller.h"
#include "functions.h"

#include <stdbool.h>
#include <stdio.h>

uint32_t ctrl_sizeof(controller_t* ctrl) {
  return sizeof(controller_t) + ctrl->size * sizeof(controller_def_t);
}

controller_def_t* ctrl_get_by_name(controller_t* ctrl, char name) {
  for (uint32_t i = 0; i < ctrl->size; ++i) {
    if(ctrl->definitions[i].name == name) {
      return &ctrl->definitions[i];
    }
  }

  return 0;
}

uint32_t ctrl_getidx_by_name(controller_t* ctrl, char name) {
  for (uint32_t i = 0; i < ctrl->size; ++i) {
    if(ctrl->definitions[i].name == name) {
      return i;
    }
  }

  return -1;
}


controller_match_t ctrl_match(controller_t* actrl, controller_t* bctrl) {
  bool matches[actrl->size];
  bool used[bctrl->size];

  for (uint32_t i = 0; i < actrl->size; ++i) {
    matches[i] = false; // extra init


    uint32_t idx = ctrl_getidx_by_name(bctrl, actrl->definitions[i].name);
    if (idx == -1) {
      continue;
    }

    //printf("%s %c %p\n",actrl->name, actrl->definitions[i].name, def);

    controller_def_t* def = &(bctrl->definitions[idx]);
    actrl->definitions[i].u_value = def->u_value;
    matches[i] = true;
    used[idx] = true;


  }

  for (uint32_t i = 0; i < bctrl->size; ++i) {
    if (!used[i]) {

    }
  }


  // manual matches
  //strcmp(actrl->name, "")

  int kos = 0;
  //printf("%u\n", kos);

  for (uint32_t i = 0; i < actrl->size; ++i) {
    if (!matches[i]) {
      printf("UNMAPPED: ");
      debug_controller_def(&actrl->definitions[i]);
      kos++;
    }
    //printf("%s -> %s: %u %d %d\n", actrl->name, bctrl->name, i, matches[i], kos);
  }


  for (uint32_t i = 0; i < bctrl->size; ++i) {
    if (!used[i]) {
      printf("UNSUSED:  ");
      debug_controller_def(&bctrl->definitions[i]);
    }
  }

  controller_match_t m;
  m.unmapped = kos;

  return m;
}
