#include "genlib.h"
#include "simpio.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define rows 7
#define columns 21

void RegularPluralForm(int c, char word[c]);
bool isVowel(char letter);

main() {
  int i, y;
  char word[rows][columns] = {"kiss",    "crucifix", "beach", "ash",
                              "apology", "toy",      "light"};
  char temp[columns];

  for (i = 0; i < 7; i++) {
    for (y = 0; word[i][y] != '\0'; y++) {
      printf("%c", word[i][y]);
    }
    printf("\n");
  }

  for (i = 0; i < 7; i++) {
    for (y = 0; y < 21; y++) {
      temp[y] = word[i][y];
    }
    RegularPluralForm(columns, temp);
    for (y = 0; y < 21; y++) {
      word[i][y] = temp[y];
    }
  }

  for (i = 0; i < 7; i++) {
    for (y = 0; word[i][y] != '\0'; y++) {
      printf("%c", word[i][y]);
    }
    printf("\n");
  }
  system("pause");
}

void RegularPluralForm(int c, char word[c]) {
  int i;
  int finalletter;
  finalletter = strlen(word) - 1;
  if (word[finalletter] == 's' || word[finalletter] == 'x' ||
      (word[finalletter - 1] == 'c' && word[finalletter] == 'h') ||
      (word[finalletter - 1] == 's' && word[finalletter] == 'h')) {
    word[finalletter + 1] = 'e';
    word[finalletter + 2] = 's';
    word[finalletter + 3] = '\0';
  } else if ((word[finalletter] == 'y') &&
             (!(isVowel(word[finalletter - 1])))) {
    word[finalletter] = 'i';
    word[finalletter + 1] = 'e';
    word[finalletter + 2] = 's';
    word[finalletter + 3] = '\0';
  } else {
    word[finalletter + 1] = 's';
    word[finalletter + 2] = '\0';
  }
}

bool isVowel(char letter) {
  char lowerCh;
  lowerCh = tolower(letter);
  switch (lowerCh) {
  case 'a':
  case 'e':
  case 'i':
  case 'o':
  case 'u':
    return (TRUE);
  default:
    return FALSE;
  }
}
