#ifndef ROUNDEDRECTANGLESHAPE_HPP
#define ROUNDEDRECTANGLESHAPE_HPP

#include <SFML/Graphics/Shape.hpp>

namespace sf
{

class RoundedRectangleShape : public sf::Shape {
 public:
  explicit RoundedRectangleShape (const Vector2f &size = Vector2f (0, 0),
								  float radius = 0,
								  unsigned int corner_point_count = 0);

  void set_size (const Vector2f &size);

  void set_corners_radius (float radius);

  void set_corner_point_count (unsigned int count);

  std::size_t getPointCount () const override;

  sf::Vector2f getPoint (std::size_t index) const override;

 private:
  Vector2f size;
  float radius;
  unsigned int corner_point_count;
};
}// namespace sf
#endif// ROUNDEDRECTANGLESHAPE_HPP
