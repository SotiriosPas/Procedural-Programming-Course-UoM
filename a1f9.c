#include <stdio.h>
#include "genlib.h"
#include <string.h>
#include <stdlib.h>

void fixtext(FILE *infile,FILE *outfile);

main()
{
FILE *infile,*outfile;
    while (TRUE)
    {
        infile = fopen("i1f9.dat","r");
        if (infile!=NULL) break;
        printf("FILE NOT FOUND");
    }
outfile = fopen("o1f9.dat","w");
fixtext(infile,outfile);
fclose(infile);
fclose(outfile);
system("pause");
}

void fixtext(FILE *infile,FILE *outfile)
{
    int a,b;
    while (a!=EOF)
    {
        a=getc(infile);

        if (!(a==32 && b==32))
        putc (a,outfile);

        b=a;
    putc (32,outfile);
    }
}










































