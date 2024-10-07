#include "genlib.h"
#include <stdio.h>
main() {
  long years = 0, cars = 80000;
  while (cars <= 160000) {
    cars = ceil(cars + cars * 0.07);
    years++;
  }
  printf("%ld \n", years);
  printf("%ld \n", cars);
}
