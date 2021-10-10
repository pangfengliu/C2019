#include <stdio.h>

void fill_rectangle_neg(int *upperLeft, int *bottomRight, 
			int nRow, int nCol, int fill)
{
  int width = (bottomRight - upperLeft) % nCol + 1;
  int height = (bottomRight - upperLeft) / nCol + 1;
  for (int i = 0; i < height; i++) {
    int *ptr = upperLeft + i * nCol;
    for (int j = 0; j < width; j++, ptr++)
      *ptr = fill;
  }
}
void fill_rectangle_pos(int *upperRight, int *bottomLeft, 
			int nRow, int nCol, int fill)
{
  /* do not midify this */
  int width = (nCol - ((nCol + bottomLeft - upperRight) % nCol)) % nCol + 1;
  fill_rectangle_neg(upperRight - (width - 1), bottomLeft + (width - 1),
		     nRow, nCol, fill);
}
