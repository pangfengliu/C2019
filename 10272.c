#include <stdio.h>
#include <assert.h>
#include "calArea.h"

typedef struct point 
{
  NODE *ptr;
  int level;
} Point;

Point goDown(NODE *ptr, int level)
{
  assert(ptr != NULL);
  while (ptr->downPtr != NULL) {
    ptr = ptr->downPtr;
    level++;
  }
  Point down;
  down.ptr = ptr;
  down.level = level;
  return down;
}

int area(Point up, Point down)
{
  int area = 0;
  while (up.level < down.level) {
    area += (down.level - up.level);
    up = goDown(up.ptr->rightPtr, up.level);
    down = goDown(down.ptr->rightPtr, down.level);
  }
  return area;
}

int calArea(NODE* head)
{
  Point up = {head, 0};
  Point down = goDown(head, 0);
  return area(up, down);
}

