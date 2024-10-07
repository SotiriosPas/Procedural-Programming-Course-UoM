#include "genlib.h"
#include "simpio.h"
#include <stdio.h>

main() {
  int age, max = 0, min = 0;
  while (TRUE) {
    printf("Dese ilikia: ");
    age = GetInteger();
    if (age == -1)
      break;
    if (age > max)
      max = age;
    min = age;
    if (age < min)
      min = age;
  }
  printf("H megalyteri ilikia einai %d\n", max);
  printf("H mikroteri ilikia einai %d\n", min);
  system("pause");
}
