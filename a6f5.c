#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

void fill(long a,long b,long board[4][4]);

main()
{
bool flag;
int x,y;
long a,b,sumx[4]={0,0,0,0},sumy[4]={0,0,0,0},diag1=0,diag2=0;
long board[4][4];

printf("Dwse thn timh tou a:");
a=GetLong();
printf("Dwse thn timh tou b:");
b=GetLong();

fill(a,b,board);

for (x=0;x<4;x++)
{
    for (y=0;y<4;y++)
        sumx[x]+=board[x][y];
}

for (y=0;y<4;y++)
{
    for (x=0;x<4;x++)
        sumy[y]+=board[x][y];
}

    y=0;
    for (x=0;x<4;x++)
    {
        diag1+=board[x][y];
    y++;
    }

    y=3;
    for (x=3;x>=0;x--)
    {
        diag2+=board[x][y];
        y--;
    }

    for (x=0;x<4;x++)
        printf("%ld %ld %ld %ld | %ld\n",board[x][0],board[x][1],board[x][2],board[x][3],sumx[x]);
        printf("---------------\n");
        printf("%ld %ld %ld %ld\n",sumy[0],sumy[1],sumy[2],sumy[3]);
        printf("%ld, %ld\n",diag1,diag2);

flag=TRUE;
if (diag1!=diag2)
    flag=FALSE;

x=0;
while (flag==TRUE && x<4)
{
if (diag1!=sumx[x])
flag=FALSE;
x++;
}

x=0;
while (flag==TRUE && x<4)
{
if (diag1!=sumy[x])
flag=FALSE;
x++;
}

if (flag==TRUE)
printf("MAGIC\n");
else if (flag==FALSE)
printf("NOT MAGIC\n");

system("pause");
}

void fill(long a,long b,long board[4][4])
{
    long array[4][4]= {
{a,a+14,b,a+3},
{b-2,a+5,a+6,a+8},
{a+7,b-4,a+10,a+4},
{a+12,a+2,a+1,b+2}
};
   int i,z;
    for (i=0;i<4;i++)
    {
        for (z=0;z<4;z++)
            board[i][z]=array[i][z];
    }
}

