#include "window_manager.h"
#include <iostream>
#include <vector>

WindowManager::WindowManager(ResourceManager *resource_manager, Player *player,
                             Enemy *enemy, Stage *stage)
{
  this->resource_manager_ = resource_manager;
  this->player_ = player;
  this->enemy_ = enemy;
  this->stage_ = stage;
  sf::ContextSettings settings;
  settings.antialiasingLevel = 8;
  window_ = new sf::RenderWindow(sf::VideoMode(1920, 1080, 32), "Fantasia",
                                 sf::Style::Default, settings);
}

void WindowManager::draw_all()
{
  for (auto drawable : resource_manager_->get_drawables())
  {
    window_->draw(*drawable);
  }
  window_->display();
}

void WindowManager::start_window()
{
  resource_manager_->initialise_window();
  while (window_->isOpen())
  {
    sf::Event event{};
    while (window_->pollEvent(event))
    {
      switch (event.type)
      {
      case sf::Event::Closed:
      {
        window_->close();
      }
      case sf::Event::MouseButtonPressed:
      {
      }
        handle_click(event);
      }
    }
    draw_all();
  }
}

void WindowManager::handle_click(sf::Event e)
{
  sf::Vector2f click_pos(static_cast<float>(e.mouseButton.x),
                         static_cast<float>(e.mouseButton.y));
  for (auto bound_pair : get_bound_pairs())
  {
    if (bound_pair.first.contains(click_pos))
    {
      bound_pair.second->click();
    }
  }
}

std::vector<std::pair<sf::FloatRect, sf::Clickable *>>
WindowManager::get_bound_pairs()
{
  std::vector<std::pair<sf::FloatRect, sf::Clickable *>> bound_pairs{};
  bound_pairs.emplace_back(
      resource_manager_->get_enemy_sprite().getGlobalBounds(), enemy_);
  bound_pairs.emplace_back(
      resource_manager_->get_player_sprite().getGlobalBounds(), player_);
  return bound_pairs;
}