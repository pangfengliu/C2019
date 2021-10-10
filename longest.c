#include <stdio.h>

int main()
{
  int n;
  int count = 0;
  int maxLength = 0;
  int currentLength = 0;
  int currentSum = 0;
  int maxSum = 0;

  while (scanf("%d", &n) != EOF) {
    if (n > 0) {
      currentLength++;
      currentSum += n;

      if (currentLength > maxLength)
	maxLength = currentLength;
      if (currentSum > maxSum)
	maxSum = currentSum;

    } else {
      currentLength = 0;
      currentSum = 0;
    }
    printf("currentLength = %d\n", currentLength);
    count++;
  }
  printf("%d\n", maxLength);
  return 0;
}
