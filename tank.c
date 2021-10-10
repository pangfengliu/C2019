#include <stdio.h>

int main()
{
  int tWidth, tLength, tHeight, waterHeight, bWidth, bLength, bHeight;
  scanf("%d%d%d%d%d%d%d", &tWidth, &tLength, &tHeight, &waterHeight, &bWidth, &bLength, &bHeight);
#ifdef DEBUG
  printf("%d %d %d %d %d %d %d\n", a, b, c, d, e, f, g);
#endif
  int water = tWidth * tLength * waterHeight;
  int tankArea = tWidth * tLength;
  int blockArea = bWidth * bLength;
  int depth;

  if (water == 0) {
    printf("0\n");
  } else {
    if (tankArea == blockArea) {
      if (bHeight >= tHeight)
	depth = 0;
      else
	depth = bHeight + water / tankArea;
    } else {
      int areaAround = tankArea - blockArea;
      if (water <= areaAround * bHeight)
	depth = water / areaAround;
      else
	depth = bHeight + (water - areaAround * bHeight) / tankArea;
    }
    if (depth >= tHeight)
      depth = tHeight;

    printf("%d\n", depth);
  }
}
