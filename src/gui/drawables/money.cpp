#include "money.h"
#include <random>

Money::Money(const long double &value, Resources &resources) : value(value)
{
  static std::random_device random_device;
  static std::mt19937 rng(random_device());
  std::uniform_int_distribution<int> frames_dist(40, 160);

  total_frames = [&]
  {
    int rand_int = frames_dist(rng);
    return rand_int % 2 == 0 ? rand_int : rand_int + 1;
  }();

  remaining_frames = total_frames;

  std::uniform_real_distribution<float> start_offset_dist(-10.0, 10.0);
  float start_offset_x = start_offset_dist(rng);
  float start_offset_y = start_offset_dist(rng);

  start_point.x = 1055.0f + start_offset_x;
  start_point.y = 710.0f + start_offset_y;

  std::uniform_real_distribution<float> mid_offset_dist(-300.0, 300.0);
  float mid_offset_x = mid_offset_dist(rng);
  float mid_offset_y = mid_offset_dist(rng);

  mid_point.x = 1205.0f + mid_offset_x;
  mid_point.y = 1000.0f + mid_offset_y;

  end_point.x = 1621.0f;
  end_point.y = 255.0f;

  sprite.setPosition(start_point);
  sprite.setScale(sf::Vector2f(0.80f, 0.80f));

  ResourceName texture_name = [&]
  {
    if (value <= 10)
      return ResourceName::COIN_TEXTURE_1;

    if (value <= 20)
      return ResourceName::COIN_TEXTURE_2;

    if (value <= 40)
      return ResourceName::COIN_TEXTURE_3;

    if (value <= 80)
      return ResourceName::COIN_TEXTURE_4;

    if (value > 150)
      return ResourceName::COIN_TEXTURE_5;

    if (value <= 500)
      return ResourceName::COIN_TEXTURE_6;

    if (value <= 2000)
      return ResourceName::COIN_TEXTURE_7;

    if (value <= 10000)
      return ResourceName::COIN_TEXTURE_8;

    else
      return ResourceName::COIN_TEXTURE_9;
  }();

  sprite.setTexture(resources.get_texture(texture_name));
}

void Money::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  if (remaining_frames == 0)
    return;

  target.draw(sprite);

  if (remaining_frames > total_frames / 2)
    sprite.scale(1.003, 1.003);
  else
    sprite.scale(0.987, 0.987);

  const float t = static_cast<float>(total_frames - remaining_frames) /
                  static_cast<float>(total_frames);
  sprite.setPosition(calc_bezier_curve(t));

  remaining_frames--;
}

sf::Vector2f Money::calc_bezier_curve(const float t) const
{
  return sf::Vector2f{
      ((1 - t) * (1 - t) * start_point.x) + 2 * ((1 - t) * t * mid_point.x) +
          (t * t * end_point.x),
      ((1 - t) * (1 - t) * start_point.y) + 2 * ((1 - t) * t * mid_point.y) +
          (t * t * end_point.y)};
}

bool Money::has_more_frames() const
{
  return remaining_frames > 0;
}

long double &Money::get_value()
{
  return value;
}
