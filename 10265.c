#include <stdio.h>
#include <stdbool.h>

#define MAXN 10

typedef struct path {
  int city[MAXN];
  int num;
} Path;

void printPath(Path *path)
{
  for (int i = 1; i < path->num; i++)
    printf("%d ", path->city[i]);
  printf("\n");
}

void search(Path *path, Path *best, bool visited[], 
	    bool road[MAXN][MAXN], int N)
{
  if (path->num > 2 && road[0][path->city[path->num - 1]] && 
      path->num > best->num) {
    *best = *path;
  }

  for (int i = 0; i < N; i++) {
    if (!visited[i] && road[i][path->city[path->num - 1]]) {
      visited[i] = true;
      path->city[path->num] = i;
      path->num++;
      search(path, best, visited, road, N);
      visited[i] = false;
      path->num--;
    }
  }
}
      
int main()
{
  int N;
  scanf("%d", &N);
  bool road[MAXN][MAXN];
  int value;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++) {
      scanf("%d", &value);
      road[i][j] = (value == 1);
    }

  Path path;
  path.city[0] = 0;
  path.num = 1;

  bool visited[MAXN];
  visited[0] = true;
  for (int i = 1; i < N; i++)
    visited[i] = false;

  Path best;
  best.num = 0;

  search(&path, &best, visited, road, N);
  printPath(&best);
  return 0;
}
