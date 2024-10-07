#include <stdlib.h>
#include "genlib.h"
#include "simpio.h"

main()
{
long syskeues;
long x1,x2,x3,x4;
printf("Dwse ton arithmo twn syskeuwn: ");
syskeues=GetLong();
x1=(syskeues/50);
syskeues=(syskeues-(50*x1));
x2=(syskeues/20);
syskeues=(syskeues-(20*x2));
x3=(syskeues/5);
syskeues=(syskeues-(5*x3));
x4=syskeues;
printf("%ld\n",x1);
printf("%ld\n",x2);
printf("%ld\n",x3);
printf("%ld\n",x4);
system("pause");
}
