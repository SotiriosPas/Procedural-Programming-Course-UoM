#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

int leap(int y);

main()
{
int a,b,i,x;
printf("Apo etos:");
a=GetInteger();
printf("Eos etos:");
b=GetInteger();
for (i=a;i<b;i++)
{
x=leap(i);
    if (x==1)
 {
        printf("%d Disekto\n",i);
}
}
system("pause");
}

int leap(int y)
{
    if (((y%4==0) && (y%100!=0)) || (y%400==0))
        return 1;
    else return 0;

}
