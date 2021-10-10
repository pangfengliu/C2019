#include <stdbool.h>

#define MAXLIGHTS 20 
#define MAXLOCKS 100
#define SENSORNUM 3

typedef struct locks {
  int lockSeq[MAXLOCKS][SENSORNUM];
  int num;
} Locks;
 
Locks* init(int lockSeq[][3], int n);
 
int numUnlocked(Locks *locks, bool lights[], int m);
