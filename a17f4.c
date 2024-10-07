#include <stdio.h>
#include "genlib.h"

int total(int num);

main()
{
int athr1,athr2,x=100,y=1000;
athr1=total(x);
athr2=total(y);
printf("Athr 1 ... 100  = %d\n",athr1);
printf("Athr 1 ... 1000 = %d\n",athr2);
system("pause");
}


int total(int num)
{
int sum=0,i;
for (i=1;i<=num;i++)
sum+=i;
return (sum);
}
