#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include "genlib.h"

# define max 15

void randomizeword(char word[]);


main()
{
char word[max]={"Apple"};
printf("Word to shuffle: Apple\n");
randomizeword(word);
printf("Initial Word: Apple, New Word: %s\n",word);
system("pause");
}

void randomizeword(char word[])
{
int i;
char temp;
int a=rand() % strlen(word);
int b=rand() % strlen(word);
for (i=0;i<100;i++)
{
temp=word[a];
word[a]=word[b];
word[b]=temp;
a=rand() % strlen(word);
b=rand() % strlen(word);
}

}















