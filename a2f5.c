#include "genlib.h"
#include "simpio.h"
#include <stdlib.h>

main() {
  long money, tax1, tax2;
  printf("Dwse to katharo eisodima: ");
  money = GetLong();

  if (money >= 1 && money <= 10000) {
    tax1 = tax2 = 0;
  } else if (money >= 10001 && money <= 39000) {
    tax1 = 0;
    tax2 = 0.18 * money;
  } else if (money >= 39001 && money <= 49000) {
    tax1 = 5220;
    tax2 = 0.21 * (money - 39000);
  } else if (money >= 49001 && money <= 59000) {
    tax1 = 7320;
    tax2 = 0.24 * (money - 49000);
  } else if (money >= 59001 && money <= 85000) {
    tax1 = 9720;
    tax2 = 0.28 * (money - 59000);
  } else if (money >= 85001 && money <= 100000) {
    tax1 = 17000;
    tax2 = 0.33 * (money - 85000);
  } else if (money >= 100001 && money <= 120000) {
    tax1 = 21950;
    tax2 = 0.38 * (money - 100000);
  } else if (money >= 120001 && money <= 150000) {
    tax1 = 29550;
    tax2 = 0.43 * (money - 120000);
  } else if (money >= 150001 && money <= 170000) {
    tax1 = 42450;
    tax2 = 0.49 * (money - 150000);
  } else {
    tax1 = 52250;
    tax2 = 0.50 * (money - 170000);
  }

  printf("%ld Euro\n", money);
  printf("%ld Euro\n", tax1);
  printf("%ld Euro\n", tax2);
  printf("%ld Euro\n", tax1 + tax2);

  system("pause");
}
