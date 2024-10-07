#include "genlib.h"
#include "simpio.h"
#include <stdio.h>

main() {
  int N, counter, a = 0, b = 1, c;
  printf("Dwse ton arithmo twn orwn ths akolouthias Fibonnaci pou theleis na "
         "emfanistoun: ");
  N = GetInteger();
  while (N < 0) {
    printf("Dwse thetiko arithmo: ");
    N = GetInteger();
  }
  if (N == 0)
    system("pause");
  else {
    for (counter = 0; counter < N; counter++) {
      if (counter <= 1)
        c = counter;
      else {
        c = a + b;
        a = b;
        b = c;
      }
      printf("%d\n", c);
    }
    system("pause");
  }
}
