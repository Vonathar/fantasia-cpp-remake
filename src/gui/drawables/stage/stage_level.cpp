#include "stage_level.h"
#include "spdlog/spdlog.h"

StageLevel::StageLevel(Resources &r, int level, float x, float y)
    : value(level), resources(r), posX(x), posY(y)
{
  rect.setPosition(x, y);
  rect.set_size(sf::Vector2f(30.0f, 30.0f));
  rect.set_corners_radius(4);
  rect.set_corner_point_count(10);
  rect.setFillColor(sf::Color(0, 0, 0, 230));
  rect.setOutlineColor(sf::Color(255, 255, 255, 230));
  rect.setOutlineThickness(1);

  text.setFont(resources.get_font(ResourceName::RIGHTEOUS_FONT));
  text.setCharacterSize(14);
  text.setFillColor(sf::Color(255, 255, 255, 230));
  set_text(std::to_string(level));
};

void StageLevel::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  target.draw(rect);
  target.draw(text);
}

void StageLevel::set_status(StageLevelStatus s)
{
  status = s;
  switch (s)
  {
  case StageLevelStatus::LOCKED:
    rect.setFillColor(sf::Color(0, 0, 0, 255));
    rect.setOutlineColor(sf::Color(255, 255, 255, 30));
    rect.set_corners_radius(15);
    text.setFillColor(sf::Color(255, 255, 255, 50));
    break;
  case StageLevelStatus::UNLOCKED:
    rect.setFillColor(sf::Color(0, 120, 0, 200));
    rect.setOutlineColor(sf::Color(0, 170, 0, 170));
    rect.set_corners_radius(15);
    text.setFillColor(sf::Color(255, 255, 255, 250));
    break;
  case StageLevelStatus::ACTIVE:
    rect.setFillColor(sf::Color(0, 0, 0, 255));
    rect.setOutlineColor(sf::Color(255, 255, 255, 230));
    rect.set_corners_radius(4);
    text.setFillColor(sf::Color(255, 255, 255, 250));
    break;
  case StageLevelStatus::COMPLETED:
    rect.setFillColor(sf::Color(0, 30, 0, 250));
    rect.setOutlineColor(sf::Color(0, 50, 0, 250));
    rect.set_corners_radius(15);
    text.setFillColor(sf::Color(255, 255, 255, 100));
    break;
  }
}

void StageLevel::increment_value()
{
  ++value;
  set_text(std::to_string(value));
}

void StageLevel::set_text(std::string t)
{
  text.setString(t);
  sf::FloatRect rect_bounds = text.getLocalBounds();
  float text_pos_x = posX + 15 - std::floor(rect_bounds.width / 2);
  float text_pos_y = posY + 7;
  text.setPosition(text_pos_x, text_pos_y);
}

int StageLevel::get_value() const
{
  return value;
}

StageLevelStatus StageLevel::get_status()
{
  return status;
}
sf::FloatRect StageLevel::get_bounds()
{
  return rect.getGlobalBounds();
}
