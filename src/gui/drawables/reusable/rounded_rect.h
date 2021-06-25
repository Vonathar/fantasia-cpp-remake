#ifndef _ROUNDED_RECT_H_
#define _ROUNDED_RECT_H_

#include <SFML/Graphics/Shape.hpp>

class RoundedRect : public sf::Shape
{
  public:
  explicit RoundedRect(const sf::Vector2f &size = sf::Vector2f(0, 0),
                       float radius = 0, unsigned int corner_point_count = 0);
  void set_size(const sf::Vector2f &s);
  void set_corners_radius(float r);
  void set_corner_point_count(unsigned int c);
  std::size_t getPointCount() const override;
  sf::Vector2f getPoint(std::size_t index) const override;

  private:
  sf::Vector2f size;
  float radius;
  unsigned int corner_point_count;
};
#endif // _ROUNDED_RECT_H_
