#include <stdio.h>
#include "simpio.h"
#include "genlib.h"

main()
{
long code;
double yearsalary,weekreward,hourreward;
int workhours;
printf("Dwse ton kwdiko:");
code = GetLong();
if (code>=1000)
{
printf("Dwse ton ethsio mistho:");
yearsalary = GetReal();
weekreward = yearsalary / 52;
}
 else {
printf("Dwse tis wres ebdomadiaias ergasias:");
workhours = GetInteger();
printf("Dwse thn amoibh ana wra:");
hourreward = GetReal();
if (workhours>40)
{
weekreward = 40*hourreward + (workhours-40)*(hourreward+hourreward*50/100);
}
else
{
weekreward = hourreward*workhours;
}
}
printf("H ebdomadiaia amoibh einai %g\n",weekreward);
system("pause");
}

