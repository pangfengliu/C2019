#include <stdio.h>
#include "lights.h"

int main()
{
  Lights lights;
  init(&lights);

  int N;
  scanf("%d", &N);

  int index;
  while(scanf("%d", &index) != EOF) {
    flip(&lights, index, N);
#ifdef DEBUG
    printLights(&lights, N);
#endif
  }

  printLights(&lights, N);
  return 0;
}
