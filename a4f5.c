#include <stdlib.h>
#include "genlib.h"

main()
{

int board[4][5] = {
{10,4,5,6,7},
{7,0,12,1,3},
{4,9,5,0,8},
{3,2,1,5,6}
};

long sum[4]={0,0,0,0};
long quant[5]={0,0,0,0,0};
int x,y;
long tempsum;

    for (x=0;x<4;x++)
        sum[x]+=board[x][0]*25000;
    for (x=0;x<4;x++)
        sum[x]+=board[x][1]*15000;
    for (x=0;x<4;x++)
        sum[x]+=board[x][2]*32000;
    for (x=0;x<4;x++)
        sum[x]+=board[x][3]*21000;
    for (x=0;x<4;x++)
        sum[x]+=board[x][4]*9200;

    for (x=0;x<5;x++)
        {
        tempsum=0;
        for (y=0;y<4;y++)
        tempsum+=board[y][x];
    quant[x]=tempsum;
        }

    for (x=0;x<4;x++)
        printf("%ld ",sum[x]);

    printf("\n");

    for (x=0;x<4;x++)
        printf("%ld ",sum[x]*10/100);

    printf("\n");

    for (x=0;x<5;x++)
        printf("%ld ",quant[x]);

system("pause");
}

