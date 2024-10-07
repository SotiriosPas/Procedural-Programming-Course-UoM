#include "genlib.h"
#include "simpio.h"
#include <stdio.h>
#include <stdlib.h>

#define max 100

int fillarray(int m, int arr[m], int count);
void getnums(int *a, int *b);
void compare(int *pl1, int *pl2, int *pl3, int a, int b, int count, int m,
             int arr[m], int pin1[m], int pin2[m], int pin3[m]);
void printeverything(int a, int b, int count, int m, int pl1, int pl2, int pl3,
                     int arr[m], int pin1[m], int pin2[m], int pin3[m]);

main() {
  int counter = 0, array[max], A, B, plithos1 = 0, plithos2 = 0, plithos3 = 0;
  int pinakas1[max], pinakas2[max], pinakas3[max];
  counter = fillarray(max, array, counter);
  getnums(&A, &B);
  compare(&plithos1, &plithos2, &plithos3, A, B, counter, max, array, pinakas1,
          pinakas2, pinakas3);
  printeverything(A, B, counter, max, plithos1, plithos2, plithos3, array,
                  pinakas1, pinakas2, pinakas3);

  system("pause");
}

int fillarray(int m, int arr[m], int count) {
  char x = 'y';
  int i = 0;
  while (count < m && x == 'y') {
    printf("Dose akeraio: ");
    arr[i] = GetInteger();
    i += 1;
    count += 1;
    printf("tha dosete allo arithmo? (max 100) y or n\n");
    x = getchar();
  }
  return (count);
}

void getnums(int *a, int *b) {
  *a = GetInteger();
  *b = GetInteger();
}

void compare(int *pl1, int *pl2, int *pl3, int a, int b, int count, int m,
             int arr[m], int pin1[m], int pin2[m], int pin3[m]) {
  int i;
  for (i = 0; i < count; i++) {
    if (arr[i] <= a) {
      pin1[*pl1] = arr[i];
      *pl1 += 1;
    } else if (arr[i] >= b) {
      pin2[*pl2] = arr[i];
      *pl2 += 1;
    } else {
      pin3[*pl3] = arr[i];
      *pl3 += 1;
    }
  }
}

void printeverything(int a, int b, int count, int m, int pl1, int pl2, int pl3,
                     int arr[m], int pin1[m], int pin2[m], int pin3[m]) {
  int i;
  printf("oi arithmoi A kai B einai oi %d kai %d\n", a, b);
  printf("Ta stoixeia N tou pinaka einai ta eksis:\n");
  for (i = 0; i < count; i++) {
    printf("%d \n", arr[i]);
  }
  printf("Oi arithmoi pou einai mikroteroi kai isoi me to A einai %d kai einai "
         "oi parakato:\n",
         pl1);
  for (i = 0; i < pl1; i++) {
    printf("%d \n", pin1[i]);
  }
  printf("Oi arithmoi pou einai megaliteroi kai isoi me to B einai %d kai "
         "einai oi parakato:\n",
         pl2);
  for (i = 0; i < pl2; i++) {
    printf("%d \n", pin2[i]);
  }
  printf("Oi arithmoi pou einai megaliteroi tou A kai mikroteroi tou B einai "
         "%d kai einai oi parakato:\n",
         pl3);
  for (i = 0; i < pl3; i++) {
    printf("%d \n", pin3[i]);
  }
}
