#include "game.h"

void Game::start()
{
  this->stage.name = StageName::GREEN_FOREST;

  this->player.name = "Rogue TEST";
  this->player.level = 7357;
  this->player.required_xp = 100;
  this->player.xp = 75;

  this->enemy.name = "Fairy Filia";
  this->enemy.level = 7357;
  this->enemy.max_hp = 100;
  this->enemy.hp = 92;

  resource_manager.set_enemy(stage, enemy);
  resource_manager.set_player(player);
  resource_manager.set_background(StageName::GREEN_FOREST);

  window_manager.start_window();
}