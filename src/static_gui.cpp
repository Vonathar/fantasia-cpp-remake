#include "static_gui.h"

StaticGUI::StaticGUI(Resources &r) : resources(r)
{
  player_hp_text.setFont(resources.get_font(ResourceName::RIGHTEOUS_FONT));
  player_hp_text.setCharacterSize(13);
  player_hp_text.setFillColor(sf::Color::White);
  player_hp_text.setLetterSpacing(0.5f);
  player_hp_text.setPosition(603.0f, 868.0f);
  player_hp_text.setString("HP");

  player_fever_text.setFont(resources.get_font(ResourceName::RIGHTEOUS_FONT));
  player_fever_text.setCharacterSize(13);
  player_fever_text.setFillColor(sf::Color::White);
  player_fever_text.setLetterSpacing(0.5f);
  player_fever_text.setPosition(603.0f, 893.0f);
  player_fever_text.setString("FV");

  player_xp_text.setFont(resources.get_font(ResourceName::RIGHTEOUS_FONT));
  player_xp_text.setCharacterSize(13);
  player_xp_text.setFillColor(sf::Color::White);
  player_xp_text.setLetterSpacing(0.5f);
  player_xp_text.setPosition(603.0f, 918.0f);
  player_xp_text.setString("XP");

  enemy_hp_text.setFont(resources.get_font(ResourceName::RIGHTEOUS_FONT));
  enemy_hp_text.setCharacterSize(13);
  enemy_hp_text.setFillColor(sf::Color::White);
  enemy_hp_text.setLetterSpacing(0.5f);
  enemy_hp_text.setPosition(882.0f, 868.0f);
  enemy_hp_text.setString("HP");

  inventory_text.setFont(resources.get_font(ResourceName::RIGHTEOUS_FONT));
  inventory_text.setCharacterSize(18);
  inventory_text.setFillColor(sf::Color::White);
  inventory_text.setLetterSpacing(0.2f);
  inventory_text.setPosition(1594.0f, 210.0f);
  inventory_text.setString("Inventory");
  inventory_text.setStyle(sf::Text::Style::Bold);

  battle_area_rect.set_size(sf::Vector2f(746.0f, 464.0f));
  battle_area_rect.set_corners_radius(25);
  battle_area_rect.set_corner_point_count(50);
  battle_area_rect.setFillColor(sf::Color(0, 0, 0, 230));
  battle_area_rect.setPosition(585.0f, 500.0f);

  player_info_rect.set_size(sf::Vector2f(192, 25));
  player_info_rect.set_corners_radius(12);
  player_info_rect.set_corner_point_count(20);
  player_info_rect.setFillColor(sf::Color(0, 0, 0, 230));
  player_info_rect.setPosition(603.0f, 831.0f);

  enemy_info_rect.set_size(sf::Vector2f(435, 25));
  enemy_info_rect.set_corners_radius(12);
  enemy_info_rect.set_corner_point_count(20);
  enemy_info_rect.setFillColor(sf::Color(0, 0, 0, 230));
  enemy_info_rect.setPosition(880.0f, 831.0f);

  inventory_rect.set_size(sf::Vector2f(480, 432));
  inventory_rect.set_corners_radius(12);
  inventory_rect.set_corner_point_count(20);
  inventory_rect.setFillColor(sf::Color(0, 0, 0, 230));
  inventory_rect.setPosition(1392.0f, 190.0f);
}

void StaticGUI::render(sf::RenderTarget &t)
{
  t.draw(battle_area_rect);
  t.draw(player_info_rect);
  t.draw(enemy_info_rect);
  t.draw(player_info_rect);
  t.draw(enemy_info_rect);
  t.draw(inventory_rect);
  t.draw(player_hp_text);
  t.draw(player_xp_text);
  t.draw(player_fever_text);
  t.draw(enemy_hp_text);
  t.draw(inventory_text);
}