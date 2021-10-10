#include <stdio.h>
#include <assert.h>

#define MAXFILENAME 128
#define MAXFILE 100
#define SKIP 255

int minNumChar(int numChar[], int n)
{
  int minIndex = 0;
  int minValue = numChar[0];

  for (int i = 1; i < n; i++) 
    if (numChar[i] < minValue) {
      minValue = numChar[i];
      minIndex = i;
    }
  return minIndex;
}

int main()
{
  int n;
  char inputFileName[MAXFILENAME];
  char outputFileNamePrefix[MAXFILENAME];
  scanf("%s%d%s", inputFileName, &n, outputFileNamePrefix);

  FILE *infp = fopen(inputFileName, "rb");
  assert(infp != NULL);
  FILE *outfp[MAXFILE];

  for (int i = 0; i < n; i++) {
    char outputFileName[MAXFILENAME];
    sprintf(outputFileName, "%s%d", outputFileNamePrefix, i + 1);
    outfp[i] = fopen(outputFileName, "wb");
    assert(outfp[i] != NULL);
  }

  int numChar[MAXFILE] = {0};
  while (!feof(infp)) {
    int index = minNumChar(numChar, n);
    int byte;
    while ((byte = fgetc(infp) != SKIP) && !feof(infp)) {
      fputc(byte, outfp[index]);
      numChar[index]++;
    }
  }

  fclose(infp);
  for (int i = 0; i < n; i++) 
    fclose(outfp[i]);
    
  return 0;
}
