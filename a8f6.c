#include "genlib.h"
#include "simpio.h"
#include <stdio.h>
#include <stdlib.h>

#define stud 30
#define column 2
#define maxgr 20

void getgrades(int st, int vathm[st]);
int FindUnique(int st, int vathm[st], int mgr, int un[mgr], int count);
void calcfreq(int st, int vathm[st], int mgr, int count, int un[mgr],
              int freq[mgr]);
void findmaxfreq(int count, int mgr, int freq[mgr], int un[mgr], int *maxvath,
                 int *maxfr);

main() {

  int vathmoi[stud], frequency[maxgr];
  int unique[maxgr], counter = 0;
  int i;
  int maxvathmos, maxfreq;

  for (i = 0; i < maxgr; i++) {
    frequency[i] = 0;
  }

  getgrades(stud, vathmoi);
  counter = FindUnique(stud, vathmoi, maxgr, unique, counter);
  calcfreq(stud, vathmoi, maxgr, counter, unique, frequency);
  findmaxfreq(counter, maxgr, frequency, unique, &maxvathmos, &maxfreq);

  printf("Vathmoi    Sixnotita\n");
  for (i = 0; i < counter; i++) {
    printf("%d          %d\n", unique[i], frequency[i]);
  }
  printf("O vathmos pou paratirithike tis perissoteres fores einai o %d kai "
         "paratirithike %d fores\n",
         maxvathmos, maxfreq);

  system("pause");
}

void getgrades(int st, int vathm[st]) {
  int i;
  for (i = 0; i < st; i++) {
    printf("Dwse vathmo: ");
    vathm[i] = GetInteger();
  }
}

void calcfreq(int st, int vathm[st], int mgr, int count, int un[mgr],
              int freq[mgr]) {
  int i, y;
  for (i = 0; i < count; i++)
    for (y = 0; y < st; y++) {
      if (vathm[y] == un[i])
        freq[i] += 1;
    }
}

int FindUnique(int st, int vathm[st], int mgr, int un[mgr], int count) {

  int i, j;
  for (i = 0; i < st; i++) {
    for (j = 0; j < i; j++) {
      if (vathm[i] == vathm[j])
        break;
    }

    if (i == j) {
      un[count] = vathm[i];
      count += 1;
    }
  }
  return (count);
}

void findmaxfreq(int count, int mgr, int freq[mgr], int un[mgr], int *maxvath,
                 int *maxfr) {
  int i;
  *maxvath = un[0];
  *maxfr = freq[0];
  for (i = 1; i < count; i++) {
    if (freq[i] > *maxfr) {
      *maxfr = freq[i];
      *maxvath = un[i];
    }
  }
}
