#include <stdio.h>
#include "lights.h"
 
void init(Lights *lights)
{
  for (int i = 0; i < MAXN * MAXN; i++)
    lights->on[i] = false;
  lights->num = 0;
}

int numOfLights(Lights *lights, int N)
{
  return lights->num;
}

void flipOne(Lights *lights, int i)
{
  lights->on[i] = !lights->on[i];
  if (lights->on[i])
    lights->num++;
  else
    lights->num--;
}

void flip(Lights *lights, int i, int N)
{
  flipOne(lights, i);
  if (i % N != 0)
    flipOne(lights, i - 1);
  if (i % N != N - 1)
    flipOne(lights, i + 1);
  if (i / N != 0)
    flipOne(lights, i - N);
  if (i / N != N - 1)
    flipOne(lights, i + N);
}

void printLights(Lights *lights, int N)
{
  int index = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++, index++)
      printf("%d ", lights->on[index]);
    printf("\n");
  }
}
