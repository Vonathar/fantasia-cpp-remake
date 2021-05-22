#ifndef _PLAYER_GUI_H_
#define _PLAYER_GUI_H_

#include "SFML/Graphics.hpp"
#include "entity.h"
#include "progress_bar.h"
#include "resources.h"
#include <iostream>

class PlayerGUI : public Entity
{
  public:
  explicit PlayerGUI(Resources &r);
  void render(sf::RenderTarget &target) override;
  void set_hp(double hp);
  void set_max_hp(double max_hp);
  void set_xp(double xp);
  void set_required_xp(double max_xp);
  void set_fever(double fever);
  void set_info(const std::string &rank, int level);

  private:
  Resources &resources;
  ProgressBar hp_bar{169, sf::Color(207, 63, 46), 625.0f, 871.0f};
  ProgressBar fever_bar{689, sf::Color(141, 102, 241), 625.0f, 896.0f};
  ProgressBar xp_bar{689, sf::Color(166, 255, 17), 625.0f, 921.0f};
  sf::Text info;
};

#endif // !_PLAYER_GUI_H
