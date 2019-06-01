#include "controller.h"
#include "sega.h"
#include "nintendo.h"
#include "functions.h"

#include <assert.h>
#include <stdio.h>

int main() {
  controller_t* mk_801116 = create_sega_saturn_mk_80116();
  controller_t* hkt_7700 = create_dreamcast_hkt_7700();

  controller_t* nes_004 = create_nintendo_nes_004();
  controller_t* snes_005 = create_nintendo_snes_005();
  controller_t* nus_005 = create_nintendo_nus_005();

  printf("sizeof: %llu\n", sizeof(mk_801116));
  printf("sizeof: %llu\n", sizeof(mk_801116->name));
  printf("sizeof: %llu\n", sizeof(mk_801116->definitions[0]));
  printf("sizeof: %llu\n", sizeof(controller_def_t));

  printf("TEST: search button by name: a -> ok\n");
  controller_def_t* a = ctrl_get_by_name(mk_801116, 'a');
  assert(a != 0);
  assert(a->name == 'a');

  uint32_t aidx = ctrl_getidx_by_name(mk_801116, 'a');
  assert(aidx == 7);

  printf("TEST: search button by name: j -> not found\n");
  controller_def_t* not_found = ctrl_get_by_name(mk_801116, 'j');
  assert(not_found == 0);

  uint32_t not_found_idx = ctrl_getidx_by_name(mk_801116, 'j');
  assert(not_found_idx == -1);

  printf("TEST: structure sizes\n");

  assert(ctrl_sizeof(mk_801116) == 280);
  assert(ctrl_sizeof(snes_005) == 260);


  controller_def_t* ss_left = ctrl_get_by_name(mk_801116, 'l');
  ss_left->u_value = 1;

  controller_def_t* ss_start = ctrl_get_by_name(mk_801116, 'h');

  //
  // nomatches == 0, means perfect match!!
  //
  ss_start->u_value = 1;

  printf("TEST: copy|match controller\n");

  printf("TEST: snes_005 vs mk_801116\n");
  uint32_t nomatches = ctrl_match(snes_005, mk_801116);
  printf("KO = %u\n", nomatches);
  assert(nomatches == 1);


  printf("TEST: mk_801116 vs snes_005\n");
  nomatches = ctrl_match(mk_801116, snes_005);
  printf("KO = %u\n", nomatches);
  assert(nomatches == 2);


  printf("TEST: mk_801116 vs nus_005\n");
  nomatches = ctrl_match(mk_801116, nus_005);
  printf("KO = %u\n", nomatches);
  assert(nomatches == 3);

  printf("TEST: mk_801116 vs nus_005\n");
  nomatches = ctrl_match(nus_005, mk_801116);
  printf("KO = %u\n", nomatches);
  assert(nomatches == 5);

  // inter-brand

  // nintendo compat

  printf("\n\nNINTENDO\n\n");

  printf("TEST: nus_005 vs snes_005\n");
  nomatches = ctrl_match(nus_005, snes_005);
  printf("KO = %u\n", nomatches);
  assert(nomatches == 6);


  printf("TEST: snes_005 vs nus_005\n");
  nomatches = ctrl_match(snes_005, nus_005);
  printf("KO = %u\n", nomatches);
  //ssert(nomatches == 5);


  printf("TEST: nes_004 vs snes_005\n");
  nomatches = ctrl_match(nes_004, snes_005);
  printf("KO = %u\n", nomatches);
  assert(nomatches == 0);

  printf("TEST: snes_005 vs nes_004\n");
  nomatches = ctrl_match(snes_005, nes_004);
  printf("KO = %u\n", nomatches);
  assert(nomatches == 4);



  printf("TEST: nes_004 vs nus_005\n");
  nomatches = ctrl_match(nes_004, nus_005);
  printf("KO = %u\n", nomatches);
  //ssert(nomatches == 5);

  printf("TEST: nus_005 vs nes_004\n");
  nomatches = ctrl_match(nus_005, nes_004);
  printf("KO = %u\n", nomatches);
  //ssert(nomatches == 5);


  // sega compat

  printf("\n\nSEGA\n\n");

  printf("TEST: mk_801116 vs hkt_7700\n");
  nomatches = ctrl_match(mk_801116, hkt_7700);
  printf("KO = %u\n", nomatches);
  //assert(nomatches == 5);

  printf("TEST: hkt_7700 vs mk_801116\n");
  nomatches = ctrl_match(hkt_7700, mk_801116);
  printf("KO = %u\n", nomatches);
  //assert(nomatches == 5);




  return 0;
}
