#include <stdbool.h>

#define MAXN 4

typedef struct _lights{
  bool on[MAXN * MAXN];
  int num;
} Lights;
 
void init(Lights *lights);
int numOfLights(Lights *lights, int N);
void flip(Lights *lights, int i, int N);
void printLights(Lights *lights, int N);
