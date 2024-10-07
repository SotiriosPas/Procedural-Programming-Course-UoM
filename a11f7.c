#include "genlib.h"
#include "simpio.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define max 30

main()

{

  char email[max], newmail[max];

  int i;
  int y = 0;
  int n = 0;
  int k = 0;
  int l = 0;

  printf("Dose to email sou: ");

  gets(email);

  for (i = 0; email[i] == ' '; i++) {
    y++;
  }
  n = strlen(email);

  for (i = n; email[i] == ' '; i++) {
    n--;
  }

  for (i = y; i <= n; i++) {
    newmail[k] = email[i];
    k++;
  }

  printf("To onoma mesa sti diefthinsi einai to ");
  for (i = 0; newmail[i] != '@'; i++) {
    printf("%c", newmail[i]);
    l++;
  }
  printf("\n");
  printf("Mikos onomatos: %d\n", l);

  system("pause");
}
