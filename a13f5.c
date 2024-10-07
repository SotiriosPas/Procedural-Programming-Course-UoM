#include <stdio.h>
#include "genlib.h"
#include <stdlib.h>
#include "simpio.h"

void populate_data(int board[10][10],int lines,int columns);
void print_array(int board[10][10],int lines,int columns);
void change_array(int board[10][10],int lines,int columns);

main()
{
int board[10][10];
int lines,columns;

printf("Dwse ton arithmo twn grammwn: ");
lines=GetInteger();

printf("Dwse ton arithmo twn sthlwn: ");
columns=GetInteger();

populate_data(board,lines,columns);
printf("ARXIKOS PINAKAS\n");

print_array(board,lines,columns);
printf("ALLAGMENOS PINAKAS\n");

change_array(board,lines,columns);
print_array(board,lines,columns);

system("pause");
}


void populate_data(int board[10][10],int lines,int columns)
{
    int x,z;
    for (x=0;x<lines;x++)
    {
        for (z=0;z<columns;z++)
            board[x][z]= rand() % 100;
    }
}

void print_array(int board[10][10],int lines,int columns)
{
     int x,z;
    for (x=0;x<lines;x++)
    {
        for (z=0;z<columns;z++)
       printf("%d ",board[x][z]);
printf("\n");
    }
}

void change_array(int board[10][10],int lines,int columns)
{
   int i,z,maxspot,max;
    for (i=0;i<lines;i++)
    {
    maxspot=0,max=0;

    for (z=0;z<columns;z++)
     {
     if (board[i][z]>max)
            max=board[i][z];
     maxspot=z;
     }
    for (z=0;z<maxspot;z++)
        board[i][z]=max;
    }
    }






























