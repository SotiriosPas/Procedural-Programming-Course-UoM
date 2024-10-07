#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

main()
{
    int num;
    for (num=1;num<=100;num++)
      {
       if (num%10==0)
        printf("%4.d\n",num);
       else
       printf("%4.d",num);
      }
}
