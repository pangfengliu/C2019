#include <stdio.h>
#include <stdbool.h>
#include "lock.h"

#define MAXLIGHTS 20 
#define MAXLOCKS 100
#define SENSORNUM 3
 
typedef struct lightstatus {
  bool on[MAXLIGHTS];
  int numLights;
  int numOn;
} LightStatus;

void printLightStatus(LightStatus *status)
{
  for (int i = 0; i < status->numLights; i++)
    printf("%d ", status->on[i]);
  printf("\n");
}

void search(Locks *locks, int lightIndex, LightStatus *current, LightStatus *best)
{
  if (lightIndex == current->numLights && 
      numUnlocked(locks, current->on, current->numLights) > best->numUnlocked {
    
    printLightStatus(current);
    return;
  }

  current->on[lightIndex] = true;
  current->numOn++;
  search(locks, lightIndex + 1, current, best);
  current->on[lightIndex] = false;
  current->numOn--;
  search(locks, lightIndex + 1, current, best);
} 

int main() 
{
  int numLights, numLocks;
  scanf("%d%d", &numLights, &numLocks);

  int lockSeq[MAXLOCKS][SENSORNUM];
  for(int i = 0; i < numLocks; i++) 
    for(int j = 0; j < SENSORNUM; j++)
      scanf("%d", &lockSeq[i][j]);
  
  Locks *locks = init(lockSeq, numLocks);

  LightStatus allOff;
  for(int i = 0; i < numLights; i++) 
    allOff.on[i] = false;
  allOff.numOn = 0; 
  allOff.numLights = numLights; 
  LightStatus best;
  best.numOn = numLights + 1;

  search(locks, 0, &allOff, &best);
  return 0;
}

