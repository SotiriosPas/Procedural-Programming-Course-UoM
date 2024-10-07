#include <stdio.h>
#include "simpio.h"
#include "genlib.h"

main()
{
float milia,litra,kat;
printf("Dwse milia:");
milia=GetReal();
printf("Dwse litra:");
litra=GetReal();
kat=litra/milia;
if (kat>=0 && kat<=0.9)
printf("Poli xamili\n");
else if (kat>0.9 && kat<=1.2)
printf("Xamili\n");
else if (kat>1.2 && kat<=1.8)
printf("Kanoniki\n");
else if (kat>1.8)
printf("Ypsili\n");
system("pause");
}
