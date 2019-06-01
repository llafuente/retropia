#include "controller.h"

#ifndef YUPI_SNES_H
#define YUPI_SNES_H

#define NINTENDO_SNES_005_SIZE 12
#define NINTENDO_NUS_005_SIZE 16
#define NINTENDO_NES_004_SIZE 8

/*
#define SNES_CONTROLLER_SELECT 0
#define SNES_CONTROLLER_START 1

#define SNES_CONTROLLER_UP 2
#define SNES_CONTROLLER_RIGHT 3
#define SNES_CONTROLLER_DOWN 4
#define SNES_CONTROLLER_LEFT 5

#define SNES_CONTROLLER_L 6
#define SNES_CONTROLLER_R 7

#define SNES_CONTROLLER_X 8
#define SNES_CONTROLLER_A 9
#define SNES_CONTROLLER_B 10
#define SNES_CONTROLLER_Y 11
*/

//
// NINTENDO ENTERTAIMENT SYSTEM
//

controller_t* create_nintendo_nes_004();
controller_t nintendo_nes_004;


//
// SUPER NINTENDO
//
// SNS-005 has the same layout: SNS-102, SHVC-005, SNSP-005
controller_t* create_nintendo_snes_005();
controller_t nintendo_snes_005;
//
// NINTENDO64
//
controller_t* create_nintendo_nus_005();
controller_t nintendo_nus_005;

#endif
