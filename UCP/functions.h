#ifndef YUPI_FUNCTIONS_H
#define YUPI_FUNCTIONS_H

#include "controller.h"
#include <stdint.h>


struct controller_match {
  uint32_t unmapped;
};

typedef struct controller_match controller_match_t;

uint32_t ctrl_sizeof(controller_t* ctrl);

controller_def_t* ctrl_get_by_name(controller_t* ctrl, char name);

uint32_t ctrl_getidx_by_name(controller_t* ctrl, char name);

controller_def_t* ctrl_get_by_position(controller_t* ctrl);

/**
 * returns how many buttons do not match
 */
controller_match_t ctrl_match(controller_t* actrl, controller_t* bctrl);


#endif
