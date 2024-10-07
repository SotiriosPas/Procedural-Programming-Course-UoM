#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

#define salesmen 4
#define product 5


void calculatesales(int s, int p, int sales[s][p],int price[p], int sp[s]);
void calculateProductSales(int s, int p,int sales[s][p], int ps[p]);
void printArray(int size,int array[]);
void maxArray(int size, int array[], int *max, int *pos);


main()
{
    int sales[salesmen][product]={{10, 4, 5, 6, 7},
                                {7, 0, 12 ,1, 3},
                                {4, 19, 5 ,0, 8},
                                {3, 2 , 1 ,5 ,6}
                                };

    int  price[product]= {250, 150, 320, 210, 920};
    int salesperson[salesmen];
    int productsales[product];
    int MaxProduct, item, MaxMan, MaxIn;

    calculatesales(salesmen, product, sales, price, salesperson);

    calculateProductSales(salesmen, product, sales, productsales);

    printf("Salesman - Sales\n");

    printArray(salesmen, salesperson);

    maxArray(salesmen, salesperson, &MaxMan , &MaxIn);

    printf("Best Salesman was %d with %d sales\n",MaxIn ,MaxMan );

    printf("Product -  Items\n");

    printArray(product, productsales);

    maxArray(product, productsales, &MaxProduct, &item );

    printf("Best product was %d with %d items\n",  item, MaxProduct);

    system("pause");

}






void calculatesales(int s, int p, int sales[s][p],int price[p], int sp[s])
{
        int i,j;

        for(i=0; i<s; i++)
           {sp[i]=0;
                for(j=0; j<p; j++)
                    sp[i]+= sales[i][j]*price[j];
           }

}

void calculateProductSales(int s, int p,int sales[][p], int ps[])
{
    int i,j;

    for(i=0; i<p; i++)
    {ps[i]=0;
        for (j=0; j<s; j++)
            ps[i]+=sales[j][i];
    }

}

void printArray(int size,int array[])
{
    int i;
    for(i=0; i<size; i++)
        printf("%d          %d\n", i, array[i]);
}

void maxArray(int size, int array[], int *max, int *pos)
{
    int i;
    *max=array[0];
    *pos=i;

    for(i=1; i<size; i++)
       {if (array[i]>*max)
          {*max=array[i];
            *pos=i;
          }
       }
}


