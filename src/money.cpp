#include "money.h"
#include <random>

Money::Money(const double &value, Resources &resources)
{
  static std::random_device random_device;
  static std::mt19937 rng(random_device());
  std::uniform_real_distribution<float> frames_dist(100.0, 400.0);

  total_frames = frames_dist(rng);
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

  end_point.x = 1605.0f;
  end_point.y = 240.0f;

  sprite.setPosition(start_point);
  sprite.setScale(sf::Vector2f(0.80f, 0.80f));

  ResourceName texture_name = [&]
  {
    if (value <= 10)
      return ResourceName::COIN_TEXTURE_1;

    if (value <= 20)
      return ResourceName::COIN_TEXTURE_2;

    if (value <= 30)
      return ResourceName::COIN_TEXTURE_3;

    if (value <= 40)
      return ResourceName::COIN_TEXTURE_4;

    if (value <= 50)
      return ResourceName::COIN_TEXTURE_5;
  }();

  sprite.setTexture(resources.get_texture(texture_name));
}

void Money::render(sf::RenderTarget &target)
{
  target.draw(sprite);

  if (remaining_frames > total_frames / 2)
    sprite.scale(1.002, 1.002);
  else
    sprite.scale(0.992, 0.992);

  const float t = (total_frames - remaining_frames) / total_frames;
  sprite.setPosition(calc_bezier_curve(t));

  remaining_frames--;
}

bool Money::has_more_frames() const
{
  return remaining_frames > 0;
}

sf::Vector2f Money::calc_bezier_curve(const float t) const
{
  return sf::Vector2f{
      ((1 - t) * (1 - t) * start_point.x) + 2 * ((1 - t) * t * mid_point.x) +
          (t * t * end_point.x),
      ((1 - t) * (1 - t) * start_point.y) + 2 * ((1 - t) * t * mid_point.y) +
          (t * t * end_point.y)};
}