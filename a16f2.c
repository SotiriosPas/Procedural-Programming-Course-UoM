#include <stdio.h>
#include "simpio.h"
#include "genlib.h"

main()
{
int plhthos;
double price;
printf("Dwse to plithos sms :");
plhthos=GetInteger();
if (plhthos<=10)
{
price=plhthos*2;
}
else if (plhthos>10 && plhthos<=60)
{
price=0.02*10 + (plhthos-10)*0.15;
}
else if (plhthos>60 && plhthos<=160)
{
price=0.02*10 + 50*0.015 + (plhthos-60)*0.012;
}
else if (plhthos>160)
{
price=0.02*10 + 50*0.015+100*0.012 + (plhthos-160)*0.01;
}
printf("Synoliko poso se euro: %g\n",price);
}
