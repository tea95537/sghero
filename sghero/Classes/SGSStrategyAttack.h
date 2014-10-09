#ifndef SG_SKIRMISH_STRATEGY_ATTACK_H
#define SG_SKIRMISH_STRATEGY_ATTACK_H

#include "SGSStrategy.h"

class SGSStrategyAttack : public SGSStrategy 
{
public:
  SGSStrategyAttack(SGSTerrain* terrain) : SGSStrategy(terrain) {}
  bool oneMove(SGSHero* hero);
private:
  SGSHeroList* findAssaultableEnemyHeroes(SGSHero* hero);
  SGSPoint&    findBestAttackPoint(SGSHero* attack_hero, SGSHero* defend_hero);
  SGSHero*     getBestAssaultHero(SGSHero* hero);


};

#endif