/*
 *a3f1.c
 */

#include "genlib.h"
#include "simpio.h"
#include <stdio.h>

main() {
  int syskeues, container1, container5, container20, container50;
  printf("Dwse to plhthos twn syskeuwn:");
  syskeues = GetInteger();
  container50 = syskeues / 50;
  container20 = (syskeues % 50) / 20;
  container5 = ((syskeues % 50) % 20) / 5;
  container1 = (((syskeues % 50) % 20) % 5) / 1;
  printf("50 %d\n", container50);
  printf("20 %d\n", container20);
  printf("5 %d\n", container5);
  printf("1 %d\n", container1);
  system("pause");
}
