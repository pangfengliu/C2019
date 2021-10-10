#include <stdio.h>
#include <stdint.h>
#include <assert.h>

#define MAXN 64
#define MAXL 64

void read32Matrix(int32_t matrix[MAXN][MAXN], int N, char name[])
{
  for (int i = 0; i < N; i++) {
    char fileName[MAXL];
    sprintf(fileName, "%s%d", name, i + 1);
    FILE *fp = fopen(fileName, "rb");
    assert(fp != NULL);
    fread(matrix[i], sizeof(int32_t), N, fp);
    fclose(fp);
  }
}

void print32Matrix(int32_t matrix[MAXN][MAXN], int N)
{
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) 
      printf("%d ", matrix[i][j]);
    printf("\n");
  }
  printf("\n");
}

void print64Matrix(int64_t matrix[MAXN][MAXN], int N)
{
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) 
      printf("%lld ", matrix[i][j]);
    printf("\n");
  }
  printf("\n");
}

void write64Matrix(int64_t matrix[MAXN][MAXN], int N, char name[])
{
  for (int i = 0; i < N; i++) {
    char fileName[MAXL];
    sprintf(fileName, "%s%d", name, i + 1);
    FILE *fp = fopen(fileName, "wb");
    assert(fp != NULL);
    fwrite(matrix[i], sizeof(int64_t), N, fp);
    fclose(fp);
  }
}

void multiply(int32_t A[MAXN][MAXN], int32_t B[MAXN][MAXN],
	      int64_t C[MAXN][MAXN], int N)
{
  for (int i = 0; i < N; i++) 
    for (int j = 0; j < N; j++) {
      C[i][j] = 0;
      for (int k = 0; k < N; k++) 
	C[i][j] += (int64_t)A[i][k] * (int64_t)B[k][j];
    }
}

int main()
{
  int32_t A[MAXN][MAXN], B[MAXN][MAXN];
  int64_t C[MAXN][MAXN];
  int N;
  scanf("%d", &N);
  char Aname[MAXL];
  char Bname[MAXL];
  char Cname[MAXL];
  scanf("%s%s%s", Aname, Bname, Cname);

  read32Matrix(A, N, Aname);
  read32Matrix(B, N, Bname);
  multiply(A, B, C, N);
  write64Matrix(C, N, Cname);
  return 0;
}
