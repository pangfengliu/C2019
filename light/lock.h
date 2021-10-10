#define MAXLOCKS 100
#define SENSOR 3

typedef struct locks {
  int lockSeq[MAXLOCKS][SENSOR];
  int num;
} Locks;
 
Locks* init(int lockSeq[][SENSOR], int numLocks);
 
int numUnlocked(Locks *locks, bool lights[], int numLights);
