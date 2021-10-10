#include <stdio.h>
#include <string.h>

#define STRLEN 31

enum Direction {HORIZONTAL, VERTICAL};

void printStar(int num)
{
  for (int i = 0; i < num; i++)
    printf("*");
}

/* Both printVertical and printHorizontal assume that the previous
   action did NOT change line */

void printVertical(char *string, int length, char last)
{
  int stringLength = strlen(string);
  printf("\n");
  for (int i = ((*string == last)? 1 : 0); i < stringLength; i++) {
    printStar(length - 1);
    if (i == stringLength - 1) 
      printf("%c", string[i]);
    else
      printf("%c\n", string[i]);
  }
}

void printHorizontal(char *string, int length, char last)
{
  if (*string == last) {	/* my first is the same as last */
    printf("%s", string + 1);
  } else {
    printf("\n");
    printStar(length - 1);
    printf("%s", string);
  }
}

int main()
{
  char string[STRLEN];
  scanf("%s", string);
  printf("%s", string);
  int direction = VERTICAL;
  int length = strlen(string);
  char last = string[length - 1];
  
  while (scanf("%s", string) != EOF) {
    switch (direction) {
    case VERTICAL:
      printVertical(string, length, last);
      direction = HORIZONTAL;
      break;
    case HORIZONTAL:
      printHorizontal(string, length, last);
      length += strlen(string) - 1;
      direction = VERTICAL;
      break;
    default:
      return(-1);
    }
    last = string[strlen(string) - 1];
  }
  printf("\n");
  return 0;
}
