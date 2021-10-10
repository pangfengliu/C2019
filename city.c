#include <stdio.h>
#include <stdbool.h>

#define MAXN 10

typedef struct path {
  int city[MAXN];
  int num;
} Path;

void printPath(Path *path, int N)
{
  for (int i = 1; i < path->num; i++)
    printf("%d ", path->city[i]);
  printf("\n");
}

void search(int level, Path *path, Path *best, bool road[MAXN][MAXN], 
	    bool visited[], int N)
{
  if (level > 2 && road[path->city[level - 1]][0] && (path->num > best->num)) {
    *best = *path;
  }

  for (int i = 1; i < N; i++) {
    if (!visited[i] && road[path->city[level - 1]][i]) {
      visited[i] = true;
      path->city[level] = i;
      path->num++;
      search(level + 1, path, best, road, visited, N);
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

  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++) {
      int hasRoad;
      scanf("%d", &hasRoad);
      road[i][j] = (hasRoad == 1);
    }

  Path path;
  path.num = 1;
  path.city[0] = 0;

  bool visited[MAXN];
  visited[0] = true;
  for (int i = 1; i < N; i++)
    visited[i] = false;

  Path best;
  best.num = 0;
  search(1, &path, &best, road, visited, N);

  printPath(&best, N);
  return 0;
}
