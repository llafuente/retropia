#include "controller.h"
#include "sega.h"
#include "nintendo.h"
#include "functions.h"

#include <assert.h>
#include <stdio.h>

int main() {
  controller_t* mk_801116 = create_sega_saturn_mk_80116();
  controller_t* hkt_7700 = create_sega_dreamcast_hkt_7700();
  controller_t* model_3020 = create_sega_master_system_model_3020();

  controller_t* nes_004 = create_nintendo_nes_004();
  controller_t* snes_005 = create_nintendo_snes_005();
  controller_t* nus_005 = create_nintendo_nus_005();

  controller_t** list = malloc(sizeof(controller_t*) * 6);
  list[0] = mk_801116;
  list[1] = hkt_7700;
  list[2] = model_3020;
  list[3] = nes_004;
  list[4] = snes_005;
  list[5] = nus_005;

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
  // result == 0, means perfect match!!
  //
  ss_start->u_value = 1;


  controller_match_t results[6][6] = {
    {{0}, {2}, {7}, {6}, {2}, {3}},
    {{0}, {0}, {7}, {6}, {2}, {2}},
    {{0}, {0}, {0}, {1}, {0}, {0}},
    {{0}, {0}, {0}, {0}, {0}, {1}},
    {{0}, {0}, {0}, {0}, {0}, {3}},
    {{0}, {0}, {0}, {0}, {0}, {0}}
  };

  for (int i = 0; i < 6; ++i) {
    for (int j = i; j < 6; ++j) {
      controller_match_t result = ctrl_match(list[i], list[j]);
      printf("TEST: %s vs %s: ",list[i]->name, list[j]->name);
      printf("results[%d][%d] = {%u}\n", i, j, result.unmapped);
      assert(results[i][j].unmapped == result.unmapped);
    }
  }



  return 0;
}
