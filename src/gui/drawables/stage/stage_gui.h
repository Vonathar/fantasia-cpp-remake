#ifndef _STAGE_GUI_H_
#define _STAGE_GUI_H_

#include "../../../interfaces/clickable.h"
#include "../../resources.h"
#include "../reusable/rounded_rect.h"
#include "stage_boss_button.h"
#include "stage_enemy_counter.h"
#include "stage_level.h"

class StageGUI : public sf::Drawable
{
  public:
  explicit StageGUI(Resources &r);
  void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
  sf::FloatRect get_next_level_bounds();
  sf::FloatRect get_boss_button_bounds();
  void set_enemies_killed(int n);
  void set_next_level_selected();
  void set_boss_fight(bool bf);
  void set_next_level_unlocked();

  private:
  int enemies_killed{0};
  bool boss_fight;
  StageName stage_name;
  Resources &resources;
  StageEnemyCounter enemy_counter{resources};
  StageBossButton boss_button{resources};
  sf::Text stage_name_text{};
  RoundedRect main_rect{};
  StageLevel level_rect_1{resources, 1, 845.0f, 320.0f};
  StageLevel level_rect_2{resources, 2, 895.0f, 320.0f};
  StageLevel level_rect_3{resources, 3, 945.0f, 320.0f};
  StageLevel level_rect_4{resources, 4, 995.0f, 320.0f};
  StageLevel level_rect_5{resources, 5, 1045.0f, 320.0f};
  void set_stage_name_text(StageName n);
  StageLevel &get_next_level();
};

#endif //_STAGE_GUI_H_
