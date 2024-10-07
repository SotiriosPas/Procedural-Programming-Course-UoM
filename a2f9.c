#include <stdio.h>
#include "genlib.h"
#include <string.h>
#include <stdlib.h>

 typedef struct
 {
     char name[30];
     int apousies;
 } studentT;

 void Write_Output(studentT students[],FILE *outfile,int size, int apontes)
 {
     int i;
     fprintf(outfile," %-30s%-11s\n", "ONOMATEPWNYMO", "APOUSIES");
    for(i=0; i<39; i++)
    fputc('-', outfile);

    fputc('\n',outfile);
    for(i=0; i<apontes; i++)
    fprintf(outfile, "%-30s %9d \n", students[i].name, students[i].apousies);

    for(i=0; i<39; i++)
    fputc('-', outfile);

    fputc('\n',outfile);
    fprintf(outfile, "%-30s%9d\n", "SYNOLO MATHITWN", size);
    fprintf(outfile, "%-30s%9d\n", "SYNOLO APONTWN",apontes);

 }

void read_Input(FILE *infile, studentT students[], int *P_students, int *P_apousies)
{
    int nscan;
char name[30];
char comments[68];
char termchar;
int apous,studs,apont;
studs=0;
apont=0;
while (TRUE)
{
nscan = fscanf(infile, "%30[^,], %d, %68[^\n]%c",name,&apous,comments,&termchar);

if (nscan==EOF) break;

if (nscan!=4 || termchar != '\n')
  {
  printf("Error in infile");
  }

if (apous>100)
{
    strcpy(students[apont].name,name);
 students[apont].apousies=apous;
  apont++;
}
studs++;
}
*P_students=studs;
*P_apousies=apont;
}
int main()
 {
    studentT students[8];
     FILE *infile , *outfile;
     int P_students,P_apousies;
     while (TRUE)
    {
        infile = fopen("i2f9.dat","r");
        if (infile!=NULL) break;
        printf("FILE NOT FOUND");
    return (0);
    }
     outfile = fopen("o2f9.dat","w");
     read_Input(infile,students,&P_students,&P_apousies);
     Write_Output(students,outfile,P_students,P_apousies);
fclose(outfile);
fclose(infile);
system("pause");
 }
