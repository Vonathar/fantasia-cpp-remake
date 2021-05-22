#ifndef _ENEMY_GENERATOR_H_
#define _ENEMY_GENERATOR_H_

#include "enemy_name.h"
#include "stage_name.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <map>
#include <vector>

class EnemyGenerator
{
  public:
  EnemyGenerator();
  const EnemyName &get_random_enemy(const StageName &stage_name);
  const EnemyName &get_random_boss(const StageName &stage_name);

  private:
  std::map<StageName, std::vector<EnemyName>> stage_enemies;
  std::map<StageName, std::vector<EnemyName>> stage_bosses;
};

#endif //_ENEMY_GENERATOR_H_
