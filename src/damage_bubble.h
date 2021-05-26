#ifndef _DAMAGE_BUBBLE_H_
#define _DAMAGE_BUBBLE_H_

#include "entity.h"
#include "resources.h"
#include "rounded_rect.h"
#include <SFML/Graphics.hpp>

/**
 * A class that represents a floating damage bubble.
 *
 * Each bubble is assigned a number of frames upon initialisation, which can
 * directly be drawn to the window by calling its render method.
 */
class DamageBubble : public Entity
{
  public:
  explicit DamageBubble(const int &dmg, Resources &res);

  /**
   * Draws the damage bubble on the given target window.
   *
   * The position of the damage bubble is changed by a constant offset at the
   * end of each call. Each invocation consumes one of the available frames.
   *
   * @param target the window the damage bubble is drawn on.
   */
  void render(sf::RenderTarget &target) override;

  /**
   * Checks if the damage bubble still has frames left to render.
   *
   * @return whether there are frames left.
   */
  bool has_more_frames() const;

  private:
  RoundedRect bubble_rect{};
  sf::Text damage_text;
  float random_offset;
  int remaining_frames;
};

#endif //_DAMAGE_BUBBLE_H_
