#include "game.h"

void Game::run()
{
  sf::ContextSettings settings;
  settings.antialiasingLevel = 8;
  window = std::make_unique<sf::RenderWindow>(sf::VideoMode(1920, 1080, 32),
                                              "Fantasia", sf::Style::Fullscreen,
                                              settings);
  window->setFramerateLimit(60);
  while (window->isOpen())
  {
    sf::Event event{};
    while (window->pollEvent(event))
    {
      process_event(event);
    }
    update();
    render();
  }
}

void Game::process_event(sf::Event event)
{
  if (event.type == sf::Event::Closed)
    window->close();

  if (event.type == sf::Event::MouseButtonPressed)
    process_click(event);
}

void Game::process_click(sf::Event event)
{
  sf::Vector2f click_pos(static_cast<float>(event.mouseButton.x),
                         static_cast<float>(event.mouseButton.y));

  if (enemy.is_sprite_in_bounds(click_pos))
    handle_enemy_click();

  else if (stage.is_next_level_in_bounds(click_pos))
    handle_next_level_click();

  else if (stage.is_boss_button_in_bounds(click_pos))
    handle_boss_button_click();
}

void Game::handle_next_level_click()
{
  if (stage.is_next_level_unlocked())
  {
    stage.increment_level();
    enemy.regenerate(stage.get_name(), stage.get_level(), false);
  }
}

void Game::handle_boss_button_click()
{
  if (!stage.is_boss_available())
    return;

  if (enemy.is_boss())
  {
    enemy.regenerate(stage.get_name(), stage.get_level(), false);
    stage.set_boss_fight(false);
  }

  else
  {
    player.set_hp(player.get_max_hp());
    enemy.regenerate(stage.get_name(), stage.get_level(), true);
    stage.set_boss_fight(enemy.is_boss());
  }
}

void Game::handle_enemy_click()
{
  if (enemy.is_regenerating())
    return;

  if (!enemy.is_dead())
  {
    animator.set_clicked_state(enemy.get_sprite());
    const double click_damage = player.get_click_damage();
    animator.add_damage_bubble(click_damage);
    enemy.receive_damage(click_damage);
  }
  if (enemy.is_dead())
    process_enemy_death();
}

void Game::process_enemy_death()
{
  if (!stage.is_next_level_unlocked())
    stage.record_enemy_death(enemy.is_boss());

  animator.set_dead_state(enemy.get_sprite());
  animator.add_dropped_money(enemy.get_coins_held());
  player.receive_xp(enemy.get_xp_held());
  player.set_hp(player.get_max_hp());
}

void Game::update()
{
  //////////// DEBUG ONLY ////////////
  sf::Event ev{};
  ev.mouseButton.x = static_cast<int>(enemy.get_sprite().getPosition().x);
  ev.mouseButton.y = static_cast<int>(enemy.get_sprite().getPosition().y);
  process_click(ev);
  ////////////////////////////////////

  if (clock.getElapsedTime().asMilliseconds() >= 1000)
    process_player_attacked();

  if (player.is_regenerating() || enemy.is_regenerating())
    clock.restart();
}

void Game::process_player_attacked()
{
  if (!player.is_regenerating())
    player.receive_damage(enemy.get_damage());

  if (player.is_dead() && !player.is_regenerating())
    animator.set_dead_state(player.get_sprite());

  clock.restart();
}

void Game::render()
{
  window->clear();
  window->draw(stage);
  window->draw(static_gui);
  window->draw(inventory);
  window->draw(player);
  window->draw(enemy);
  animator.animate();
  window->display();
}
