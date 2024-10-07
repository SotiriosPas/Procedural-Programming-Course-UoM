#include "genlib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void newtext(FILE *infile, FILE *outfile);

int main() {
  FILE *infile, *outfile;
  while (TRUE) {
    infile = fopen("i6f9.dat", "r");
    if (infile != NULL)
      break;
    printf("FILE NOT FOUND");
    return (0);
  }
  outfile = fopen("o6f9.dat", "w");
  newtext(infile, outfile);
  fclose(infile);
  fclose(outfile);
  system("pause");
}

void newtext(FILE *infile, FILE *outfile) {
  int x;
  bool flag = FALSE;
  while (x != EOF) {
    x = getc(infile);
    if (x != 32) {
      putc(x, outfile);
      flag = TRUE;
    }
    if (flag == TRUE && x == 32) {
      fprintf(outfile, "\n");
      flag = FALSE;
    }
  }
}
