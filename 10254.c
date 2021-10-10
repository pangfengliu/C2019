#include <stdio.h>
#include <stdbool.h>

#define MAXR 1000
#define MAXC 1000

#define WIDTH 4
#define POINT 6

int countUpperLower(int matrix[MAXR][MAXC], int row, int col, bool appeared[])
{
  int count = 0;
  for (int i = 0; i < WIDTH; i++) {
    for (int j = 0; j < WIDTH; j++) {
      int upper = matrix[row - 1][col + i];
      int lower = matrix[row + 1][col + j];
      if (!appeared[upper] && !appeared[lower] && 
	  ((upper + lower) == POINT + 1))
	count++;
    }
  }
  return count;
}

int numDice(int matrix[MAXR][MAXC], int row, int col)
{
  bool appeared[POINT + 1] = {false};

  for (int i = 0; i < WIDTH; i++)
    if (appeared[matrix[row][col + i]])
      return 0;
    else
      appeared[matrix[row][col + i]] = true;
  
  if (!(matrix[row][col] + matrix[row][col + 2] == POINT + 1 && 
	matrix[row][col + 1] + matrix[row][col + 3] == POINT + 1)) 
    return 0;
  else 
    return countUpperLower(matrix, row, col, appeared);
}

int main()
{
  int R, C;
  int matrix[MAXR][MAXC];
  scanf("%d%d", &R, &C);
  for (int r = 0; r < R; r++)
    for (int c = 0; c < C; c++)
      scanf("%d", &matrix[r][c]);

  int count = 0;
  for (int r = 1; r + 1 < R; r++)
    for (int c = 0; c + WIDTH <= C; c++)
      count += numDice(matrix, r, c);
  
  printf("%d\n", count);
  return 0;
}
