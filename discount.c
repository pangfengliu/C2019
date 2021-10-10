#include <stdio.h>

int main()
{
  int a, b, v, w, x, y, z;
  scanf("%d%d%d%d%d%d%d", &a, &b, &v, &w, &x, &y, &z);

  int pBest = 1;
  int dBest = 0;
  int p, d;

  p = a;
  d = (p % 2 == 0)? w : v;
  if (d * pBest > p * dBest) {
    pBest = p;
    dBest = d;
  }

  p = a + 1;
  d = (p % 2 == 0)? w : v;
  if (d * pBest > p * dBest) {
    pBest = p;
    dBest = d;
  }

  p = b;
  d = (p % 3 == 0)? x : ((p % 3 == 1)? y : z);
  if (d * pBest > p * dBest) {
    pBest = p;
    dBest = d;
  }

  p = b + 1;
  d = (p % 3 == 0)? x : ((p % 3 == 1)? y : z);
  if (d * pBest > p * dBest) {
    pBest = p;
    dBest = d;
  }

  p = b + 2;
  d = (p % 3 == 0)? x : ((p % 3 == 1)? y : z);
  if (d * pBest > p * dBest) {
    pBest = p;
    dBest = d;
  }

  printf("%d\n", pBest);
}
