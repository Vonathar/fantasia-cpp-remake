#include "static_gui.h"

StaticGUI::StaticGUI(Resources &r) : resources(r)
{
  title_text.setFont(resources.get_font(ResourceName::GREAT_VIBES_FONT));
  title_text.setCharacterSize(38);
  title_text.setOutlineColor(sf::Color::White);
  title_text.setOutlineThickness(0.2f);
  title_text.setFillColor(sf::Color::White);
  title_text.setPosition(900.0f, 50.0f);
  title_text.setString("Fantasia");

  player_hp_text.setFont(resources.get_font(ResourceName::RIGHTEOUS_FONT));
  player_hp_text.setCharacterSize(16);
  player_hp_text.setFillColor(sf::Color::White);
  player_hp_text.setPosition(603.0f, 865.0f);
  player_hp_text.setString("HP");

  player_fever_text.setFont(resources.get_font(ResourceName::RIGHTEOUS_FONT));
  player_fever_text.setCharacterSize(16);
  player_fever_text.setFillColor(sf::Color::White);
  player_fever_text.setPosition(603.0f, 891.0f);
  player_fever_text.setString("FV");

  player_xp_text.setFont(resources.get_font(ResourceName::RIGHTEOUS_FONT));
  player_xp_text.setCharacterSize(16);
  player_xp_text.setFillColor(sf::Color::White);
  player_xp_text.setPosition(603.0f, 916.0f);
  player_xp_text.setString("XP");

  enemy_hp_text.setFont(resources.get_font(ResourceName::RIGHTEOUS_FONT));
  enemy_hp_text.setCharacterSize(16);
  enemy_hp_text.setFillColor(sf::Color::White);
  enemy_hp_text.setPosition(885.0f, 866.0f);
  enemy_hp_text.setString("HP");

  inventory_text.setFont(resources.get_font(ResourceName::RIGHTEOUS_FONT));
  inventory_text.setCharacterSize(20);
  inventory_text.setFillColor(sf::Color::White);
  inventory_text.setPosition(1600.0f, 210.0f);
  inventory_text.setString("Inventory");

  title_rect.set_size(sf::Vector2f(275.0f, 50.0f));
  title_rect.set_corners_radius(25);
  title_rect.set_corner_point_count(50);
  title_rect.setFillColor(sf::Color(0, 0, 0, 230));
  title_rect.setPosition(822.5f, 50.0f);

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

  sf::Texture &coin_texture =
      resources.get_texture(ResourceName::COIN_TEXTURE_1);
  coin_icon.setScale(0.68f, 0.68f);
  coin_texture.setSmooth(true);
  coin_icon.setTexture(coin_texture);
  coin_icon.setPosition(1621.0f, 255.0f);
}

void StaticGUI::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  target.draw(title_rect);
  target.draw(battle_area_rect);
  target.draw(player_info_rect);
  target.draw(enemy_info_rect);
  target.draw(player_info_rect);
  target.draw(enemy_info_rect);
  target.draw(inventory_rect);
  target.draw(title_text);
  target.draw(player_hp_text);
  target.draw(player_xp_text);
  target.draw(player_fever_text);
  target.draw(enemy_hp_text);
  target.draw(inventory_text);
  target.draw(coin_icon);
}