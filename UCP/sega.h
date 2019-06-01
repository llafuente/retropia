#ifndef YUPI_SS_H
#define YUPI_SS_H

#include "controller.h"

#define SS_CONTROLLER_SIZE 13
#define DREAMCAST_CONTROLLER_SIZE 13
/*
#define SS_CONTROLLER_START 0

#define SS_CONTROLLER_UP 1
#define SS_CONTROLLER_RIGHT 2
#define SS_CONTROLLER_DOWN 3
#define SS_CONTROLLER_LEFT 4

#define SS_CONTROLLER_L 5
#define SS_CONTROLLER_R 6

#define SS_CONTROLLER_A 7
#define SS_CONTROLLER_B 8
#define SS_CONTROLLER_C 9

#define SS_CONTROLLER_X 10
#define SS_CONTROLLER_Y 11
#define SS_CONTROLLER_Z 12
*/
controller_t* create_sega_saturn_mk_80116();
controller_t* create_dreamcast_hkt_7700();

controller_t sega_saturn_mk_80116;
controller_t sega_dreamcast_hkt_7700;


#endif
