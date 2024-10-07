/*
 *a12f1.c
 */

#include "genlib.h"
#include "simpio.h"
#include <stdio.h>

main() {
  double ka8ara_tm, mikta_tm, DF, DT;
  printf("Dwse ta ka8ara tm tou spitiou? ");
  ka8ara_tm = GetReal();
  printf("Dwse ta mikta tm tou spitiou? ");
  mikta_tm = GetReal();
  DT = ka8ara_tm * 1.33 * 61 / 365;
  DF = mikta_tm * 0.13 * 61 / 365;
  printf("Ta DT einai : %g\n", DT);
  printf("O DF einai : %g\n", DF);
  system("pause");
}
