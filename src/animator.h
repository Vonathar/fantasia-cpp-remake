#ifndef _ANIMATOR_H_
#define _ANIMATOR_H_

#include "enemy.h"
#include <SFML/Graphics.hpp>
#include <map>

/**
 * A class responsible for animating sprites' properties (e.g. their scale).
 *
 * Each sprite has an 'animation state', which can either be true or false: true
 * means that the property should be actively animated (unless the
 * maximum allowed increase has been reached), and false that it should not be
 * animated anymore (and return to the baseline value if it currently isn't).
 *
 * Animated properties define two constants in their individual update
 * functions, allowing isolated tweaking of:
 *
 * 1) the maximum value the property can be increased by;
 * 2) the number of frames that it takes for the animation to complete (i.e.
 * reach the maximum allowed value).
 */
class Animator
{
  public:
  Animator(std::unique_ptr<sf::RenderWindow> &w, sf::Sprite &player_sprite,
           sf::Sprite &enemy_sprite);

  /**
   * Updates all sprites based on their animation state.
   */
  void animate();

  private:
  std::unique_ptr<sf::RenderWindow> &window;
  std::map<sf::Sprite *, bool> animation_states;
  std::map<sf::Sprite *, sf::Vector2f> original_scales;

  /**
   * Refreshes all animation states.
   */
  void refresh_states();

  /**
   * Updates the scale of all sprites that should be animated.
   *
   * For animations with a state set to true, this will increment their scale
   * linearly until the maximum allowed value is reached (defined in the local
   * constant max_scale_increase); for animations with a state set to false,
   * this will decrease their scale linearly until the baseline is reached (or
   * ignore them if they are already at their baseline value).
   */
  void update_scales();
};

#endif //_ANIMATOR_H_
