#include "genlib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char onoma[40];
  int ypol;
  double epit;
  int imer;
} trl;

int rin(FILE *f1, trl kat[], int *synyp, int *mka);
int con(trl kat1[], trl kat2[], int kat[], int a, int b);
void fin(trl kat1[], trl kat2[], FILE *f2, int a, int b);

main() {
  FILE *infile1, *infile2, *outfile;
  trl obk[20];
  trl nbk[20];
  int kkat[20];
  int a, b, n, i;
  int synyp1, synyp2, mk1, mk2;

  infile1 = fopen("bank_new.dat", "r");

  infile2 = fopen("bank_old.dat", "r");

  outfile = fopen("mztfgm.dat", "w");

  b = rin(infile2, obk, &synyp2, &mk1);

  a = rin(infile1, nbk, &synyp1, &mk2);

  n = con(nbk, obk, kkat, a, b);

  printf("Mh koinoi katathetes: \n");
  for (i = 0; i < n; i++) {
    printf(" %s  %d %lf%d \n", nbk[kkat[i]].onoma, nbk[kkat[i]].ypol,
           nbk[kkat[i]].epit, nbk[kkat[i]].imer);
  }
  printf("\n");

  printf("To 40 %%  einai : %d\n", (40 * synyp1) / 100);

  printf("To 40 %%  einai : %d\n", (40 * synyp2) / 100);

  printf("\n");

  fin(nbk, obk, outfile, a, b);

  printf("Katathetis stin new_bank me megalyteri katathesi : \n");

  printf("%s  %d \n", nbk[mk1].onoma, nbk[mk1].imer);

  printf("\n");

  printf("Katathetis stin old_bank me megalyteri katathesi : \n");

  printf(" %s %d \n", obk[mk2].onoma, obk[mk2].imer);

  fclose(infile1);

  fclose(infile2);

  fclose(outfile);
}

int con(trl kat1[], trl kat2[], int kat[], int a, int b) {
  int i, j, m, n, o;
  n = 0;

  for (i = 0; i < a; i++) {
    o = 0;
    for (j = 0; j < b; j++) {
      m = strcmp(kat1[i].onoma, kat2[j].onoma);

      if (m != 0)
        o++;
    }
    if (o == 8) {
      kat[n] = i;
      n++;
    }
  }
  return (n);
}

int rin(FILE *f1, trl kat[], int *synyp, int *mka) {
  char name[40];
  int ypoloipo;
  double epitokio;
  int imerominia;
  char termch;
  int nscan, i, a, synolo, max, pm;

  a = 0;
  synolo = 0;
  i = 0;

  while (TRUE) {
    nscan = fscanf(f1, "%40[^,], %d, %lf, %d%c", name, &ypoloipo, &epitokio,
                   &imerominia, &termch);

    if (nscan == EOF)
      break;

    if (nscan != 5 || termch != '\n')
      printf("Error in infile \n");
    else {
      strcpy(kat[i].onoma, name);
      kat[i].ypol = ypoloipo;
      kat[i].epit = epitokio;
      kat[i].imer = imerominia;
      i++;
      a++;
      synolo += ypoloipo;
    }
  }

  max = kat[0].ypol;
  pm = 0;

  for (i = 0; i > a; i++) {
    if (kat[i].ypol > max) {
      max = kat[i].ypol;
      pm = i;
    }
  }

  *synyp = synolo;
  *mka = pm;
  return (a);
}

void fillIn(trl kat1[], trl kat2[], FILE *f2, int a, int b) {
  int i;

  fprintf(f2, "%-23s \n", "Katathetes meta to 2000 :");

  fputc('\n', f2);

  for (i = 0; i < a; i++) {
    if (kat1[i].imer > 2000)
      fprintf(f2, " %d  %lf %d \n", kat1[i].onoma, kat1[i].ypol, kat1[i].epit,
              kat1[i].imer);
  }
  for (i = 0; i < b; i++) {
    if (kat2[i].imer > 2000)
      fprintf(f2, " %s  %lf %d \n", kat2[i].onoma, kat2[i].ypol, kat2[i].epit,
              kat2[i].imer);
  }

  fputc('\n', f2);

  for (i = 0; i < 39; i++)
    fputc('-', f2);
  fputc('\n', f2);

  fprintf(f2, "%-30s \n", "Katathetes meta to 2000, stin new_bank : ");

  fputc('\n', f2);

  for (i = 0; i < a; i++) {
    if (kat1[i].imer > 2000)
      fprintf(f2, "%s %d  %lf %d \n", kat1[i].onoma, kat1[i].ypol, kat1[i].epit,
              kat1[i].imer);
  }
}
