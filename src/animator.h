#ifndef _ANIMATOR_H_
#define _ANIMATOR_H_

#include "damage_bubble.h"
#include "enemy.h"
#include "player.h"
#include "resources.h"
#include "stage.h"
#include <SFML/Graphics.hpp>
#include <map>
#include <vector>

/**
 * A class responsible for animating sprites' properties (e.g. their scale).
 *
 * Animated properties can be customised by tweaking the constants in the
 * individual update functions, such as:
 *
 * 1) the maximum value the property can be increased by;
 * 2) the number of frames that it takes for the animation to complete (i.e.
 * reach the maximum allowed value);
 * 3) the increment applied after each rendering iteration.
 */
class Animator
{
  public:
  Animator(std::unique_ptr<sf::RenderWindow> &w, Resources &res, Player &p,
           Enemy &e, Stage &s);

  /**
   * Updates all sprites based on their animation state.
   */
  void animate();

  /**
   * Adds a new damage bubble that represents the given value.
   *
   * @param damage the value drawn inside of the bubble.
   */
  void add_damage_bubble(const int &damage);

  /**
   * Sets a sprite in the clicked state, triggering the click animation.
   *
   * @param sprite the sprite to animate.
   */
  void set_clicked_state(sf::Sprite &sprite);

  /**
   * Sets a sprite in the dead state, triggering the death animation.
   *
   * @param sprite the sprite to animate.
   */
  void set_dead_state(sf::Sprite &sprite);

  private:
  Resources &resources;
  Player &player;
  Enemy &enemy;
  Stage &stage;
  std::unique_ptr<sf::RenderWindow> &window;
  /// Each hoverable sprite has an 'animation state', which can either be true
  /// or false: true means that the property should be actively animated
  /// (unless the maximum allowed increase has been reached), and false that it
  /// should not be animated anymore (and return to the baseline value if it
  /// currently isn't).
  std::map<sf::Sprite *, bool> hover_animation_states;
  /// Each clickable sprite has an 'animation state', which holds the number of
  /// frames left for the animation to complete. The first half of the frames
  /// scales up the sprite, whereas the second half scales it down to its
  /// original size.
  std::map<sf::Sprite *, int> click_animation_states;
  /// Each killable sprite has an 'animation state', which holds the number of
  /// frames left for the animation to complete. The last frame is used
  /// exclusively for the regeneration of the entity.
  std::map<sf::Sprite *, int> death_animation_states;
  /// A reference to the original scale of each sprite, used to return the value
  /// to its baseline at the end of potentially multiple animations.
  std::map<sf::Sprite *, const sf::Vector2f> original_scales;
  /// The damage bubbles that have to be drawn to the screen. Individual bubbles
  /// are removed and destroyed once all animation frames have been drawn.
  std::vector<DamageBubble> damage_bubbles;

  const int click_animation_frames = 20;
  const int death_animation_frames = 80;

  /**
   * Scales a sprite by the given increment.
   *
   * @param sprite the sprite to be scaled.
   * @param increment how much the sprite should scale and move.
   */
  void scale(sf::Sprite &sprite, const float &increment);

  /**
   * Finds the currently hovered sprite, then refreshes all hover states.
   */
  void refresh_hover_states();

  /**
   * Updates the scale of all hovered sprites.
   *
   * For animations with a hover state set to true, this will increment their
   * scale linearly until the maximum allowed value is reached (defined in the
   * local constant max_scale_increase). For animations with a state set to
   * false, this will decrease their scale linearly until the baseline is
   * reached (or ignore them if they are already at their baseline value).
   */
  void scale_hovered();

  /**
   * Updates the scale of all clicked sprites.
   *
   * For animations with a clicked state with a value greater than one, this
   * will change their scale based on the amount of animation frames left:
   * (defined in the local constant max_scale_increase). For animations with a
   * state set to false, this will decrease their scale linearly until the
   * baseline is reached (or ignore them if they are already at their baseline
   * value).
   */
  void scale_clicked();

  /**
   * Draws all damage bubbles to the window.
   *
   * This function only draws a single frame for each existing damage bubble.
   * All damage bubbles that don't have any frame left to render are removed
   * from the vector at the end of each invocation.
   */
  void draw_damage_bubbles();

  /**
   * Updates the position, scale, and rotation of dead sprites.
   *
   * The animation has two different stages: in the first 70% of the total
   * frames, the sprite is moved upwards, scaled, and rotated clockwise; in the
   * remaining 30% of the frames, the sprite is moved moved downwards and scaled
   * down.
   */
  void draw_dead_sprites();
};

#endif //_ANIMATOR_H_
