#ifndef YUPI_FUNCTIONS_H
#define YUPI_FUNCTIONS_H

#include "controller.h"
#include <stdint.h>

uint32_t ctrl_sizeof(controller_t* ctrl);

controller_def_t* ctrl_get_by_name(controller_t* ctrl, char name);

uint32_t ctrl_getidx_by_name(controller_t* ctrl, char name);

controller_def_t* ctrl_get_by_position(controller_t* ctrl);

/**
 * @returns how many buttons do not match
 */
uint32_t ctrl_match(controller_t* actrl, controller_t* bctrl);


#endif
