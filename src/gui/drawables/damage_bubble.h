#ifndef _DAMAGE_BUBBLE_H_
#define _DAMAGE_BUBBLE_H_

#include "../resources.h"
#include "reusable/rounded_rect.h"
#include <SFML/Graphics.hpp>

/**
 * A class that represents a floating damage bubble.
 *
 * Each bubble is assigned a number of frames upon initialisation, which can
 * directly be drawn to the window by calling its render method.
 */
class DamageBubble : public sf::Drawable
{
  public:
  explicit DamageBubble(const long double &dmg, Resources &res);

  /**
   * Draws the damage bubble on the given target window.
   *
   * The position of the damage bubble is changed by a constant offset at the
   * end of each call. Each invocation consumes one of the available frames.
   *
   * @param target the window the damage bubble is drawn on.
   */
  void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

  /**
   * Checks if the damage bubble still has frames left to render.
   *
   * @return whether there are frames left.
   */
  bool has_more_frames() const;

  private:
  mutable RoundedRect bubble_rect{};
  mutable sf::Text damage_text;
  mutable int remaining_frames;
  float x_offset;
  int total_frames = 30;
};

#endif //_DAMAGE_BUBBLE_H_
