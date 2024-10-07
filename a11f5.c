#include "genlib.h"
#include "simpio.h"
#include <stdio.h>

main() {
  double max, national_aver;
  double temper[10][3];
  double aver[10];
  double typ_diver[10][3];
  double max_diver[10];
  int i, j, sum = 0, city_sum = 0;
  for (i = 0; i < 10; i++) {
    city_sum = 0;
    for (j = 0; j < 3; j++) {
      printf("Dwse thermokrasia: ");
      temper[i][j] = GetReal();
      sum = temper[i][j] + sum;
      city_sum = temper[i][j] + city_sum;
    }
    aver[i] = city_sum / 3.0;
  }
  national_aver = sum / 30.0;
  for (i = 0; i < 10; i++)
    for (j = 0; j < 3; j++) {
      typ_diver[i][j] = abs(temper[i][j] - national_aver);
    }
  for (i = 0; i < 10; i++) {
    max = 0.0;
    for (j = 0; j < 3; j++) {
      if (typ_diver[i][j] > max)
        max = typ_diver[i][j];
    }
    max_diver[i] = max;
  }
  printf("%g\n", national_aver);
  for (i = 0; i < 10; i++)
    printf("%g-%g\n", aver[i], max_diver[i]);
  system("pause");
}
