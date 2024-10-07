#include "genlib.h"
#include "simpio.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define max 26

int countduplicates(char arr[], char un);

main() {
  char array[max], unique[max];
  int i, j, k = 0, plithos = 0;
  ;

  printf("Dose ena alfarithmitiko to poli 25 xaraktiron: ");
  gets(array);

  for (i = 0; i < strlen(array); i++) {
    for (j = 0; j < i; j++)
      if (array[i] == array[j])
        break;

    if ((i == j) && (isupper(array[i]))) {
      unique[k] = array[i];
      k++;
    }
  }
  unique[k] = '\0';
  for (i = 0; i < strlen(unique); i++) {
    plithos = countduplicates(array, unique[i]);
    printf("%c------>%d\n", unique[i], plithos);
  }

  system("pause");
}

int countduplicates(char arr[], char un) {
  int i, counter = 0;
  for (i = 0; i <= strlen(arr); i++)
    if (un == arr[i])
      counter++;

  return counter;
}
