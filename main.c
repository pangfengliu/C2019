#include <stdio.h>
#include "10259.h"

#define ROW 9
#define COL 10

int main()
{
  int array[ROW][COL] ={{0}};
#ifdef DEBUGNEG
  fill_rectangle_neg(&(array[1][2]), &(array[5][7]), ROW, COL, 1);
  fill_rectangle_neg(&(array[1][2]), &(array[5][2]), 9, 10, 3);
  fill_rectangle_neg(&(array[1][2]), &(array[1][7]), 9, 10, 4);
#endif

  fill_rectangle_pos(&(array[1][7]), &(array[5][2]), 9, 10, 1);
  for (int i = 0; i < ROW; i++)
    for (int j = 0; j < COL; j++)
      printf("%d%c", array[i][j], j == COL - 1 ? '\n' : ' ');


#ifdef DEBUG
  fill_rectangle_pos(&(array[5][7]), &(array[5][2]), 9, 10, 1);
  fill_rectangle_pos(&(array[2][7]), &(array[5][7]), 9, 10, 1);
#endif
}
