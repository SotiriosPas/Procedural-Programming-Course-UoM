#include "genlib.h"
#include "simpio.h"
#include <stdio.h>

float ipologismos_fpa(int katigoria_fpa, int Plithos, float timi_monadas);

main() {
  int i, plithos, fpa;
  float timi_monadas, sum1 = 0, fpa_proion, sum2 = 0.0;
  for (i = 1; i <= 10; i++) {
    printf("Dose plithos proionton ");
    plithos = GetInteger();
    printf("Dose timi gia to proion ");
    timi_monadas = GetReal();
    printf("Dose katigoria FPA gia to proion ");
    fpa = GetInteger();
    while ((fpa < 1) || (fpa > 4)) {
      printf("Lathos katigoria FPA\n");
      printf("Dose plithos proionton ");
      plithos = GetInteger();
      printf("Dose timi gia to proion ");
      timi_monadas = GetReal();
      printf("Dose katigoria FPA gia to proion ");
      fpa = GetInteger();
    }
    sum1 = sum1 + (plithos * timi_monadas);
    fpa_proion = ipologismos_fpa(fpa, plithos, timi_monadas);
    sum2 = sum2 + fpa_proion;
  }
  printf("Synoliko kostos: %g\n", sum1);
  printf("Synoliko fpa: %g\n", sum2);
  system("pause");
}

float ipologismos_fpa(int katigoria_fpa, int Plithos, float timi_monadas) {
  float sum = 0.0;
  int i;
  for (i = 1; i <= Plithos; i++) {
    if (katigoria_fpa == 1)
      return 0;
    else if (katigoria_fpa == 2)
      sum += timi_monadas * 0.06;
    else if (katigoria_fpa == 3)
      sum += timi_monadas * 0.13;
    else if (katigoria_fpa == 4)
      sum += timi_monadas * 0.19;
  }
  return (sum);
}
