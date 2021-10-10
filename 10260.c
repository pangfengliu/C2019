#include <stdio.h>

void sumOfIntegers(const int *ptrArray[], int answer[], int *numOfBlocks)
{
  int index = 0;
  while (ptrArray[index] != NULL) {
    answer[*numOfBlocks] = 0;
    while (ptrArray[index] != NULL) {
      int test = index - 1;
      while (test >=0 && ptrArray[test] != NULL && 
	     ptrArray[test] != ptrArray[index])
	test--;
      
      if (test < 0 || ptrArray[test] == NULL)
	answer[*numOfBlocks] += *(ptrArray[index]);

      index++;
    }
    (*numOfBlocks)++;
    index++;
  }
}
