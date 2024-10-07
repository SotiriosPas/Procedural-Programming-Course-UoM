#include "genlib.h"
#include "simpio.h"
#include <stdio.h>
#define N 50

typedef struct {

  char epwnimo[20];
  char onoma[15];
  char address[30];
  int price;

} profile;

void getData(profile patient[], int pl);
void printall(profile patient[], int pl, char name[]);
int findhighestprice(profile patient[], int pl);
int calctotal(profile patient[], int pl);
void printone(profile patient[], int asthenis);
void search(profile patient[], int pl);

main() {
  int plithos1, plithos2, high1, high2, total1, total2;
  char clinic1[N] = {"Galinos"};
  char clinic2[N] = {"Elpis"};

  profile Galinos[N], Elpis[N];

  printf("Dwse plithos asthenwn tis klinikis Galinos\n");

  plithos1 = GetInteger();

  getData(Galinos, plithos1);

  printf("Dwse plithos asthenwn tis klinikis Elpis\n");

  plithos2 = GetInteger();

  getData(Elpis, plithos2);

  printall(Galinos, plithos1, clinic1);
  printf("\n");
  printall(Elpis, plithos2, clinic2);
  printf("\n");

  high1 = findhighestprice(Galinos, plithos1);
  high2 = findhighestprice(Elpis, plithos2);

  total1 = calctotal(Galinos, plithos1);
  total2 = calctotal(Elpis, plithos2);

  printone(Galinos, high1);
  printf("\n");
  printone(Elpis, high2);

  if (total1 > total2) {
    printf("Max Income %s %d\n", clinic1, total1);
  } else {
    printf("Max Income %s %d\n", clinic2, total2);
  }

  search(Galinos, plithos1);
  search(Elpis, plithos2);

  system("pause");
}

void getData(profile patient[], int pl) {
  int i;
  for (i = 0; i < pl; i++) {
    printf("Dwse ta stoixeia tou astheni %d\n", i + 1);
    printf("Epwnimo:");
    gets(patient[i].epwnimo);
    printf("Onoma:");
    gets(patient[i].onoma);
    printf("Dief8insi:");
    gets(patient[i].address);
    printf("Poso pliromis:");
    patient[i].price = GetInteger();
  }
}

void printall(profile patient[], int pl, char name[]) {
  int i;
  printf("---------%s---------\n", name);
  printf("%-20s %-15s %-30s %-s\n", "EPWNYMO", "ONOMA", "DIEFTHYNSH", "POSO");
  printf("---------------------------------------------------------------------"
         "---\n");
  for (i = 0; i < pl; i++)
    printf("%-20s %-15s %-30s %-d\n", patient[i].epwnimo, patient[i].onoma,
           patient[i].address, patient[i].price);
}

int findhighestprice(profile patient[], int pl) {
  int i, maxprice = patient[0].price, maxpatient = 0;
  for (i = 1; i < pl; i++) {
    if (maxprice < patient[i].price) {
      maxprice = patient[i].price;
      maxpatient = i;
    }
  }
  return maxpatient;
}

int calctotal(profile patient[], int pl) {
  int total = 0, i;
  for (i = 0; i < pl; i++)
    total = total + patient[i].price;

  return total;
}

void printone(profile patient[], int asthenis) {
  printf("%-20s %-15s %-30s %-s\n", "EPWNYMO", "ONOMA", "DIEFTHYNSH", "POSO");
  printf("---------------------------------------------------------------------"
         "---\n");
  printf("%-20s %-15s %-30s %-d\n", patient[asthenis].epwnimo,
         patient[asthenis].onoma, patient[asthenis].address,
         patient[asthenis].price);
}

void search(profile patient[], int pl) {
  int i;
  bool found = FALSE;
  char givenlastname[20], givenfirstname[15];
  printf("Give patient's last name: ");
  gets(givenlastname);
  printf("Give patient's first name: ");
  gets(givenfirstname);
  for (i = 0; i < pl; i++) {
    if ((strcmp(patient[i].epwnimo, givenlastname) == 0) &&
        (strcmp(patient[i].onoma, givenfirstname)) == 0) {
      found = TRUE;
      printone(patient, i);
      break;
    }
  }
  if (found == FALSE)
    printf("Not Found!");
}
