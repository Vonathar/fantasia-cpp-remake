#ifndef _MONEY_H_
#define _MONEY_H_

#include "entity.h"
#include "resources.h"
#include <SFML/Graphics.hpp>

/**
 * A class that represents an animated money drop.
 *
 * Each money drop is assigned a random number of frames upon initialisation,
 * which can directly be drawn to the window by calling its render method (as
 * long as there are frames left).
 */
struct Money : public Entity
{
  public:
  Money(const double &value, Resources &resources);

  /**
   * Draws the money to the window, then updates the sprite.
   *
   * The scale is updated based on the number of frames left: it's increased if
   * there are more than half of the total frames left, and decreased otherwise.
   * The position is updated linearly, following a quadratic Bezier curve with a
   * randomised middle point.
   *
   * @param target the window the money is drawn on.
   */
  void render(sf::RenderTarget &target) override;
  bool has_more_frames() const;

  private:
  sf::Sprite sprite{};
  float total_frames;
  float remaining_frames;

  sf::Vector2f start_point{};
  sf::Vector2f mid_point{};
  sf::Vector2f end_point{};

  /**
   * Calculates the position of a point on the Bezier curve.
   *
   * The start, mid, and end point of the curve are expected to have already
   * been assigned prior to any call to this function.
   *
   * @param t how far the calculated point should be from the start point.
   * @return the point on the Bezier curve.
   */
  sf::Vector2f calc_bezier_curve(float t) const;
};

#endif //_MONEY_H_
