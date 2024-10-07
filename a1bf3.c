#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
main()
{
    long Arithmo_Aytok,Orio,xronia=0;
    double Rythmos;
    printf("Dwse ton arxiko arithmo autokinhtwn: ");
    Arithmo_Aytok=GetLong();
    printf("Dwse ton ethsio rythmo ayxhshs: ");
    Rythmos=GetReal();
    printf("Dwse to orio: ");
    Orio=GetLong();
    while(Arithmo_Aytok<=Orio)
    {
        Arithmo_Aytok=ceil(Arithmo_Aytok+Arithmo_Aytok*Rythmos);
        xronia++;
    }
    printf("%ld \n",xronia);
    printf("%ld \n",Arithmo_Aytok);
}
