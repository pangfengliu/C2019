#include <stdio.h>

#define A 0
#define B 1
#define C 2
#define N 3

#define SKILL 3

int main()
{
  int R;
  scanf("%d", &R);
  int maxH, H, reg;
  scanf("%d%d", &maxH, &reg);
  H = maxH;
  
  int base[SKILL], extra[SKILL], cooldown[SKILL], count[SKILL] = {0}, 
    last[SKILL];
  for (int i = 0; i < SKILL; i++)
    scanf("%d%d%d", &base[i], &extra[i], &cooldown[i]);

  int baseN;
  scanf("%d", &baseN);

  int maxSkill;
  for (int r = 0; r < R; r++) {
    int maxDamage = 0;
    int damage;
    
    for (int skill = 0; skill < SKILL; skill++) {
      if (count[skill] == 0 || (r - last[skill] >= cooldown[skill])) {
	damage = 
	  (count[skill] > 0? 
	   base[skill] + (r - last[skill] - cooldown[skill]) * extra[skill] : 
	   (r >= cooldown[skill]? 
	    base[skill] + (r - cooldown[skill]) * extra[skill] : base[skill]));
	if (damage > maxDamage) {
	  maxDamage = damage;
	  maxSkill = skill;
	}
      }
    }
    damage = baseN;
    if (damage > maxDamage) {
      maxDamage = damage;
      maxSkill = N;
    }

    if (maxSkill != N) {
      count[maxSkill]++;
      last[maxSkill] = r;
    }
    
    H -= maxDamage;
    printf("%d ", H);
    
    if (H <= 0) {
      break;
    } else {
      H += reg;
      if (H > maxH)
	H = maxH;
    }
  }
    
  return 0;
}
