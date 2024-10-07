#include "genlib.h"
#include "simpio.h"
#include <stdio.h>
#include <stdlib.h>

#define maxel 50

int elements(void);
void fillarray(int n, long arr[n]);
void printarray(int n, long arr[n]);
int FindMaxsPos(int size, long a[], int index[]);

main() {
  int N;
  long *array = (long *)malloc(maxel * sizeof(long));
  long max;
  int length, i;
  int *ind;
  N = elements();
  fillarray(N, array);
  printarray(N, array);
  printf("\n");
  max = FindMaxsPos(N, array, ind);
  length = sizeof(ind) / sizeof(int);
  printf("maximum %ld\n", max);
  printf("Plithos maximum %d\n", length);
  printf("Positions of maximum ");
  for (i = 0; i < length; i++)
    printf("%d ", ind[i]);

  system("pause");
}

int elements(void) {
  int N;
  printf("Dwse to plhthos twn stoixeiwn: ");
  N = GetInteger();
  while (N > maxel) {
    printf("O arithmos twn stoixeiwn de borei na ipervainei to 50.\n");
    printf("Dwse to plhthos twn stoixeiwn: ");
    N = GetInteger();
  }
  return N;
}

void fillarray(int n, long arr[n]) {
  int i;
  for (i = 0; i < n; i++)
    arr[i] = GetLong();
}

void printarray(int n, long arr[n]) {
  int i;
  for (i = 0; i < n; i++)
    printf("%ld ", arr[i]);
}

int FindMaxsPos(int size, long a[], int index[]) {
  int i, counter = 0;
  long max = a[0];
  int *localindex = (int *)malloc(maxel * sizeof(int));
  for (i = 0; i < size; i++) {
    if (max < a[i]) {
      counter = 0;
      max = a[i];
      localindex[counter] = i;
      counter = counter + 1;
    } else if (a[i] == max) {
      localindex[counter] = i;
      counter = counter + 1;
    }
  }
  index = (int *)malloc(counter * sizeof(int));

  for (i = 0; i < counter; i++)
    index[i] = localindex[i];

  return (max);
}
