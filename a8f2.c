#include "genlib.h"
#include "simpio.h"
#include <math.h>
#include <stdio.h>
main() {
  int problepomenos_xronos, pragmatikos_xronos, apodekth_diafora, diafora_timwn;
  printf("Dwse ton problepomeno xrono:");
  problepomenos_xronos = GetInteger();
  printf("Dwse ton pragmatiko xrono:");
  pragmatikos_xronos = GetInteger();
  if (problepomenos_xronos >= 0 && problepomenos_xronos <= 29) {
    apodekth_diafora = 1;
  } else if (problepomenos_xronos >= 30 && problepomenos_xronos <= 59) {
    apodekth_diafora = 2;
  } else if (problepomenos_xronos >= 60 && problepomenos_xronos <= 89) {
    apodekth_diafora = 3;
  } else if (problepomenos_xronos >= 90 && problepomenos_xronos <= 119) {
    apodekth_diafora = 4;
  } else if (problepomenos_xronos >= 120 && problepomenos_xronos <= 179) {
    apodekth_diafora = 6;
  } else if (problepomenos_xronos >= 180 && problepomenos_xronos <= 239) {
    apodekth_diafora = 8;
  } else if (problepomenos_xronos >= 240 && problepomenos_xronos <= 359) {
    apodekth_diafora = 13;
  } else if (problepomenos_xronos >= 360) {
    apodekth_diafora = 17;
  }
  printf("Apodekth  diafora %d\n", apodekth_diafora);
  diafora_timwn = problepomenos_xronos - pragmatikos_xronos;
  printf("Diafora eisagvmenwn timwn %d\n", diafora_timwn);
  if (abs(diafora_timwn) <= apodekth_diafora) {
    printf("GOOD\n");
  } else if (problepomenos_xronos < pragmatikos_xronos &&
             abs(diafora_timwn) > apodekth_diafora) {
    printf("SMALL\n");
  } else if (problepomenos_xronos > pragmatikos_xronos &&
             abs(diafora_timwn) > apodekth_diafora) {
    printf("BIG\n");
  }
  system("pause");
}
