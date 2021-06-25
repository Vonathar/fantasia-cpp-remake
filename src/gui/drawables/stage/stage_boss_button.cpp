#include "stage_boss_button.h"

StageBossButton::StageBossButton(Resources &r) : resources(r)
{
  text.setFont(resources.get_font(ResourceName::RIGHTEOUS_FONT));
  text.setCharacterSize(14);
  text.setFillColor(sf::Color(255, 255, 255, 230));

  rect.set_corners_radius(5);
  rect.set_corner_point_count(10);
  rect.setOutlineThickness(3);

  visible = false;
}

void StageBossButton::draw(sf::RenderTarget &target,
                           sf::RenderStates states) const
{
  if (visible)
  {
    target.draw(rect);
    target.draw(text);
  }
}

void StageBossButton::set_boss_available()
{
  text.setPosition(927.0f, 400.0f);
  text.setString("Fight boss?");
  rect.set_size(sf::Vector2f(text.getLocalBounds().width * 2,
                             text.getLocalBounds().height * 2.5));
  rect.setPosition(
      sf::Vector2f(text.getPosition().x - text.getLocalBounds().width / 2,
                   text.getPosition().y - text.getLocalBounds().height / 2.5));
  rect.setFillColor(sf::Color(150, 0, 0, 200));
  rect.setOutlineColor(sf::Color(170, 0, 0, 200));
}

void StageBossButton::set_boss_active()
{
  text.setPosition(927.0f, 400.0f);
  text.setString("Quit fight?");
  rect.set_size(sf::Vector2f(text.getLocalBounds().width * 2,
                             text.getLocalBounds().height * 2.5));
  rect.setPosition(
      sf::Vector2f(text.getPosition().x - text.getLocalBounds().width / 2,
                   text.getPosition().y - text.getLocalBounds().height / 2.5));
  rect.setFillColor(sf::Color(0, 0, 60, 200));
  rect.setOutlineColor(sf::Color(0, 0, 70, 200));
}

bool StageBossButton::boundaries_contain(sf::Vector2f &pos)
{
  return rect.getGlobalBounds().contains(pos);
}

sf::FloatRect StageBossButton::get_bounds()
{
  return rect.getGlobalBounds();
}

void StageBossButton::set_visible(bool v)
{
  visible = v;
}
