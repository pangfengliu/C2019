#include <stdbool.h>
#include <stdlib.h>
#include "lock.h"

Locks* init(int lockSeq[][SENSOR], int numLocks)
{
  Locks *locks = malloc(sizeof(Locks));
  for (int lock = 0; lock < numLocks; lock++)
    for (int seq = 0; seq < SENSOR; seq++)
      locks->lockSeq[lock][seq] = lockSeq[lock][seq];
  locks->num = numLocks;
  return locks;
}
 
int numUnlocked(Locks *locks, bool lights[], int numLights)
{
  int unlocked = 0;
  for (int lock = 0; lock < locks->num; lock++) {
    bool unlockthis = false;
    for (int seq = 0; seq < SENSOR; seq++) {
      if (locks->lockSeq[lock][seq] > 0) {
	if (lights[locks->lockSeq[lock][seq] - 1]) 
	  unlockthis = true;
      } else {
	if (!lights[-locks->lockSeq[lock][seq] - 1]) 
	  unlockthis = true;
      }
    }
    if (unlockthis)
      unlocked++;
  }
  return unlocked;   
}
