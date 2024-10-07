/*
 *a4f1.c
 */

#include "genlib.h"
#include "simpio.h"
#include <stdio.h>

main()

{

  long purchaseAmount;
  int rate;
  double saleAmount, profit;
  printf("Dwse thn katharh axia: ");
  purchaseAmount = GetLong();
  printf("Dwse to pososto kerdous: ");
  rate = GetInteger();
  profit = (purchaseAmount * rate) / 100.0;
  saleAmount = purchaseAmount + profit;
  printf("To kerdos einai %g\n", profit);
  printf("To synoliko poso einai %g\n", saleAmount);
  system("pause");
}
