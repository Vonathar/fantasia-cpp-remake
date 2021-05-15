#include "stage.h"

StageName Stage::get_stage () const
{
  return stage_;
}
void Stage::set_stage (StageName stage)
{
  stage_ = stage;
}
bool Stage::is_next_stage_unlocked () const
{
  return is_next_stage_unlocked_;
}
void Stage::set_is_next_stage_unlocked (bool is_next_stage_unlocked)
{
  is_next_stage_unlocked_ = is_next_stage_unlocked;
}
int Stage::get_kills_for_next_stage () const
{
  return kills_for_next_stage_;
}
void Stage::set_kills_for_next_stage (int kills_for_next_stage)
{
  kills_for_next_stage_ = kills_for_next_stage;
}
