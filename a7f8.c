#include "genlib.h"
#include <stdio.h>
#include "simpio.h"
#define length 20

typedef struct {

int number;
char marka[length];
int kyvika;
char onoma[length];
int days;
float priceperday;
float totalprice;

}carrental;

int getData(carrental a[]);
void calctotal(carrental a[],int en);
int findbest(carrental a[],int en);
void printall(carrental a[],int en);
void printbest(carrental a[],int bestrent);

main()
{
carrental a[length];
int i,en,bestrent;
en=getData(a);
calctotal(a,en);
bestrent=findbest(a,en);
printall(a,en);
printbest(a,bestrent);
system("pause");
}


int getData(carrental a[])
{
    int en,i;
    printf("Dose ton arithmo ton enoikiaseon\n");
    en=GetInteger();
    for (i=0;i<en;i++)
    {
        a[i].number=i;
        printf("Dose ta stoixeia tis enoikiasis %d\n",i);
        printf("Dose marka: ");
        gets(a[i].marka);
        printf("Dose kyvika: ");
        a[i].kyvika=GetInteger();
        printf("Dose onoma pelati: ");
        gets(a[i].onoma);
        printf("Dose imeres enoikiasis: ");
        a[i].days=GetInteger();
        printf("Dose timi ana imera: ");
        a[i].priceperday=GetReal();
    }
    return en;
}

void calctotal(carrental a[],int en)
{
    int i;
    for (i=0;i<en;i++)
    a[i].totalprice=a[i].days*a[i].priceperday;
}

int findbest(carrental a[],int en)
{
    int i;
    int maxnumber=0;
    float maxmoney=a[0].totalprice;
    for (i=1;i<en;i++)
        {
        if (a[i].totalprice>maxmoney)
    {
        maxnumber=i;
        maxmoney=a[i].totalprice;
    }
        }
    return maxnumber;
}

void printall(carrental a[],int en)
{
    int i;
    float counter=0;
    printf("%-7s %-20s %-10s %-5s %-6s %-8s %-8s\n",
      "Number","Name","Type","CC","Days","Price","Total\n");
      for (i=0;i<en;i++)
      {
          printf("%-7d %-20s %-10s %-5d %-6.02d %-6.02f %-6.02f\n",
              a[i].number,
              a[i].onoma,
              a[i].marka,
              a[i].kyvika,
              a[i].days,
              a[i].priceperday,
              a[i].totalprice
                 );
      counter=counter+a[i].totalprice;
      }
printf("%-52s %-s %-f\n"," ","Total",counter);
}

void printbest(carrental a[],int bestrent)
{
    printf("Best car: %s %d rented for %f Euros....\n",a[bestrent].marka,a[bestrent].kyvika,a[bestrent].totalprice);
}

