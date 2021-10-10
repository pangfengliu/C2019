#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

#include "lights.h"

#ifndef MAXN
#define MAXN 4
#endif

typedef struct _toggle {
  bool toggle[MAXN * MAXN];
  int num;
} Toggles;

void printToggles(Toggles *toggles, int N)
{
  for (int i = 0; i < N * N; i++)
    if (toggles->toggle[i])
      printf("%d ", i);
  printf("\n");
}

void search(Toggles *toggles, Toggles *best, int level, int N, Lights *lights)
{
  if (level == N * N) {
    if (numOfLights(lights, N) == 0 && toggles->num < best->num) 
      *best = *toggles;
    return;
  }

  toggles->num++;
  toggles->toggle[level] = true;
  flip(lights, level, N);
  search(toggles, best, level + 1, N, lights);
  toggles->num--;
  toggles->toggle[level] = false;
  flip(lights, level, N);

  search(toggles, best, level + 1, N, lights);
}

int main()
{
  Lights lights;
  init(&lights);

  int N;
  scanf("%d", &N);

  int index;
  while(scanf("%d", &index)!=EOF)
    flip(&lights, index, N);

  Toggles toggles;
  toggles.num = 0;
  for (int i = 0; i < N * N; i++)
    toggles.toggle[i] = false;

  Toggles best;
  best.num = N * N + 1;

  search(&toggles, &best, 0, N, &lights);
  printToggles(&best, N);

  return 0;
}
